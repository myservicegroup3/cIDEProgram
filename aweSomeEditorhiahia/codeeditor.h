#ifndef CODEEDITOR_H
#define CODEEDITOR_H
#include <QPlainTextEdit>
#include <QObject>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QSize>
#include <QSyntaxHighlighter>
#include <QTabWidget>
#include <QTabBar>
#include <myhighlighter.h>
#include <QCompleter>
class LineNumberArea;

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QTabWidget *parent = 0);
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
    void updatecolor(QString *c,QPaintEvent *event);
    QString wordUnderCursor() const;

protected:
    void keyPressEvent(QKeyEvent *e);
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
public slots:
    void onCompleterActivated(const QString &completion);
private slots:
    void setLineNumberAreaWidth(int newBlockCount);
    void HighLightCursorLine();
    void updateLineNumberArea(const QRect &, int);

private:
    QTabWidget *lineNumberArea;
    MyHighLighter *gCodeHighlighter;
    QCompleter *keyWordsComplter;
    QStringList keyWordsList;
    QTextCursor curTextCursor;
    QRect curTextCursorRect;
    QString completerPrefix;
};

class LineNumberArea : public QTabWidget
{
public:
    LineNumberArea(CodeEditor *editor) : QTabWidget(editor)
    {
        codeEditor = editor;
    }

    QSize sizeHint() const Q_DECL_OVERRIDE
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *codeEditor;

};


class tabCodeEditor:public QTabWidget
{
public:
    void readkeyword(const QString &fileName);
    tabCodeEditor(){

         blankEditor=new CodeEditor();
         blankEditor->colorCount();
         this->addTab(blankEditor,"test");

        MyHighLighter *highlighter = new MyHighLighter(this->blankEditor->document());
    }
    CodeEditor *blankEditor;


};
#endif // CODEEDITOR_H
