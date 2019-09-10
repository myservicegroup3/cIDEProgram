#include "codeeditor.h"
#include <QtWidgets>
#include <myhighlighter.h>
#include <QDebug>
CodeEditor::CodeEditor(QTabWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);
    //块的数量的修改后，就修改序号区域宽度属性
    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(setLineNumberAreaWidth(int)));
    //内容更新请求,只要内容发生变化就调用（包括光标的闪烁）。
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    //实时更新光标变化，实现行高亮
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(HighLightCursorLine()));
    setLineNumberAreaWidth(0);
    //this->setStyleSheet();
    HighLightCursorLine();



    gCodeHighlighter = new MyHighLighter (this->document());
    gCodeHighlighter->readSyntaxHighter (QString(":/SynatxHight/C.txt")); //设置语法高亮文件

    //补全列表设置
    QMap<QString, QColor>::iterator iter;
    for (iter = gCodeHighlighter->syntaxHightMap.begin(); iter != gCodeHighlighter->syntaxHightMap.end(); ++iter)
    {
        keyWordsList.append(iter.key());
    }
    keyWordsList.append("(  )");
    keyWordsList.append("{  }");
    keyWordsList.append("[  ]");
    qDebug() << "keyWordsList" << keyWordsList;

    keyWordsComplter = new QCompleter(keyWordsList);

    keyWordsComplter->setWidget(this);
    keyWordsComplter->setCaseSensitivity(Qt::CaseInsensitive);
    keyWordsComplter->setCompletionMode(QCompleter::PopupCompletion);
    keyWordsComplter->setMaxVisibleItems(4);
    keyWordsComplter->popup()->setStyleSheet(     "    background-color: white;\ "
                                                  "    color: black;\            "
                                                  "min-width:200px;"
                                                  "min-height:200px;"
                                                  "    font: 17px \"Consolas\";"
                                                             );

    keyWordsComplter->setCompletionColumn(0);

    lineNumberArea->setVisible(true);

  connect(keyWordsComplter, SIGNAL(activated(QString)), this, SLOT(onCompleterActivated(QString)));

}
int CodeEditor::lineNumberAreaWidth()
{
    //计算左侧序号边距的区域宽度大小
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10)
    {
        max /= 10;
        ++digits;
    }
    int space = 15 + fontMetrics().width(QLatin1Char('9')) * digits;
    return space;
}

void CodeEditor::setLineNumberAreaWidth(int /* newBlockCount */)
{
    //设置绘图工具窗口。
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        setLineNumberAreaWidth(0);
}



void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEditor::onCompleterActivated(const QString &completion)
{
    QString completionPrefix = wordUnderCursor(),
            shouldInertText = completion;

    curTextCursor = textCursor();
    if (!completion.contains(completionPrefix))
    {
        // delete the previously typed.
        curTextCursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, completionPrefix.size());
        curTextCursor.clearSelection();
    }
    else
    {
        // 补全相应的字符
        shouldInertText = shouldInertText.replace(
            shouldInertText.indexOf(completionPrefix), completionPrefix.size(), "");
    }
    curTextCursor.insertText(shouldInertText);
}
void CodeEditor::HighLightCursorLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;//定义一个光标类
    QColor lineColor = QColor(Qt::yellow).lighter(180);

    //设置高亮颜色和宽度
    selection.format.setBackground(lineColor);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    //构造空游标设，设置锚点，取消之前选择，防止高亮多行
    selection.cursor = this->textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);
    //高亮显示
    setExtraSelections(extraSelections);
}
void CodeEditor::updatecolor(QString * c,QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(),*c);
}

QString CodeEditor::wordUnderCursor() const
{
    //不断向左移动cursor，并选中字符，并查看选中的单词中是否含有空格——空格作为单词的分隔符
    QTextCursor curTextCursor = textCursor();
    QString selectedString;
    while (curTextCursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, 1))
    {
        selectedString = curTextCursor.selectedText();
        if (selectedString.startsWith(QString(" ")) || selectedString.startsWith(QChar(0x422029)))
        {
            break;
        }

    }
    if (selectedString.startsWith(QChar(0x422029)))
    {
        selectedString.replace(0, 1, QChar(' '));
    }
    return selectedString.trimmed();
}

void CodeEditor::keyPressEvent(QKeyEvent *e)
{
    if (keyWordsComplter)
    {
        if (keyWordsComplter->popup()->isVisible())
        {
            switch(e->key())
            {
                case Qt::Key_Escape:
                case Qt::Key_Enter:
                case Qt::Key_Return:
                case Qt::Key_Tab:
                    e->ignore();
                    return;
                default:
                    break;
            }
        }
        QPlainTextEdit::keyPressEvent(e);
        completerPrefix = this->wordUnderCursor();
        keyWordsComplter->setCompletionPrefix(completerPrefix); // 通过设置QCompleter的前缀，来让Completer寻找关键词
        curTextCursorRect = cursorRect();
        if (completerPrefix == "")
        {
            return;
        }
        //qDebug() << "completerPrefix:" << completerPrefix << " match_count:" << keyWordsComplter->completionCount() << " completionColumn:"<<keyWordsComplter->completionColumn();
        if (keyWordsComplter->completionCount() > 0)
        {
            keyWordsComplter->complete(QRect(curTextCursorRect.left(), curTextCursorRect.top(), 30, 45));
        }
    }
}
void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(),QColor(Qt::green).lighter(180));

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(-2, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}


