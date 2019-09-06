#include "codeeditor.h"
#include <QtWidgets>

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
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
void CodeEditor::HighLightCursorLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;//定义一个光标类
    QColor lineColor = QColor(Qt::green).lighter(185);

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
