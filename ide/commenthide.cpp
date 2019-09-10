#include "commenthide.h"

commentHide::commentHide(QTextDocument *parent)
{
    commentHideRule rule;
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    commentHideRules.append(rule);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}
