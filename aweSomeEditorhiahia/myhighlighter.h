#ifndef MYHIGHLIGHTER_H
#define MYHIGHLIGHTER_H
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QTextDocument>
#include <QtWidgets>
class MyHighLighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    MyHighLighter(QTextDocument *document = 0);
    void readSyntaxHighter(const QString &fileName);
    QMap<QString, QColor> syntaxHightMap; //保存语法高亮信息
protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineKey;
    QTextCharFormat singleLineValue;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
    QRegularExpression matchReExpression;
};
#endif // MYHIGHLIGHTER_H
