#ifndef SETTING_H
#define SETTING_H



#include <include.h>

//主题和字体
QString backgroundColor ="#ffffff" ;
QString foregroundColor  = "#ffffff";
QString fontsize = "20pt";
QString fontfamily = "Consolas";

void MainWindow::Tommorrow_Night_triggered()
{
    theme = "tomorrowNight";
    settings.setValue("theme", "tomorrowNight");
    backgroundColor = "#1d1f21";
    //QString fgc = "#c5c8c6";
    //QString bgc = "#1d1f21";
    //QString lc = "#282a2e";

    setTabWidgetStyle();

    //setLineNumStyle(lc, fgc);
    //setOverViewStyle(lc, fgc);

    //updateHighlighterTheme();

    //lineColor = QColor(40, 42, 46);
   //configEditor->HighLightCursorLine();
}
void MainWindow:: Tommorrow_Light_triggered()
{
    theme = "tomorrowLight";
    settings.setValue("theme","tommorowLight");
    backgroundColor = "#ffffff";
    setTabWidgetStyle();
    //QString fgc = "#4d4d4c";
    //QString bgc = "#ffffff";
    //QString lc =  "#282a2e";
    //setTabWidgetStyle();
    //configEditor-
    //CodeEditor->updatecolor(lc);

}
void MainWindow ::Solarized_Dark_triggered()
{
    theme = "solarizedDark";
    settings.setValue("theme", "solarizedDark");
    //QString fgc = "#839496";
    //QString bgc = "#002b36";
    //QString lc = "#073642";
    backgroundColor = "#002b36";
    setTabWidgetStyle();
    //setTabWidgetStyle(fgc, bgc);



}

void MainWindow ::monokai_triggered()
{
    theme = "monokai";
   settings.setValue("theme", "monokai");
   backgroundColor = "#272822";
   setTabWidgetStyle();
  // QString fgc = "#e0e0e0";
   //QString bgc = "#272822";
   //QString lc = "#32332c";
   //setTabWidgetStyle(fgc, bgc);
}
void MainWindow::solarized_triggered(){
    theme = "solarized";
    settings.setValue("theme", "solarized");
    backgroundColor = "#fdf6e3";
    setTabWidgetStyle();
    //QString fgc = "#839496";
    //QString bgc = "#fdf6e3";
    //QString lc = "#eee7d5";
    //setTabWidgetStyle(fgc, bgc);

 }
void MainWindow::setfontsize1()
{
     fontsize = "12pt";
     setTabWidgetStyle();
}
void MainWindow::setfontsize2()
{
    fontsize = "16pt";
    setTabWidgetStyle();
}
void MainWindow::setfontsize3()
{
    fontsize = "20pt";
    setTabWidgetStyle();
}
void MainWindow::setfontsize4()
{
    fontsize = "24pt";
    setTabWidgetStyle();
}

void MainWindow::setfontheme1()
{
    fontfamily = "Consolas";
    setTabWidgetStyle();
}
void MainWindow::setfontheme2()
{
    fontfamily = "Anonymous Pro";
    setTabWidgetStyle();
}
void MainWindow::setfontheme3()
{
    fontfamily = "Calibri";
    setTabWidgetStyle();
}
void MainWindow::setfontheme4()
{
    fontfamily = "Courier";
    setTabWidgetStyle();
}


void MainWindow::setTabWidgetStyle(){
    QString stylesheet = "QPlainTextEdit {"
                "background-color: " +  backgroundColor  +";"
                "color:" + foregroundColor  +";"
                "font-size:"+fontsize+";"
                "font-family:"+fontfamily+";"


             "}"

     ;
    configEditor->setStyleSheet(stylesheet);
}

#endif // SETTING_H
