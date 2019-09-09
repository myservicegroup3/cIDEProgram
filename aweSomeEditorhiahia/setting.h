#ifndef SETTING_H
#define SETTING_H

#include <include.h>
void MainWindow::setting_init()
{
    int windowWidth = settings.value("windowWidth", 1200).toInt();
    int windowHeight = settings.value("windowHeight", 900).toInt();
    MainWindow::resize(windowWidth, windowHeight);
    setTabWidgetStyle();

    QMenu *ptheme = psetting->addMenu(u8"主题");
    QAction *ptheme1 = ptheme->addAction("TommorrowLight");
    connect(ptheme1,SIGNAL(triggered()),this,SLOT(Tommorrow_Light_triggered()));
    QAction *ptheme2 = ptheme->addAction("Solarized");
    connect(ptheme2,SIGNAL(triggered()),this,SLOT(solarized_triggered()));


    QAction *ptheme3 = ptheme->addAction("SolarizedDark");
    connect(ptheme3,SIGNAL(triggered()),this,SLOT(Solarized_Dark_triggered()));
    QAction *ptheme4 = ptheme->addAction("Monokai");
    connect(ptheme4,SIGNAL(triggered()),this,SLOT(monokai_triggered()));
    QAction *ptheme5 = ptheme->addAction("TommorrowNight");

    connect(ptheme5,SIGNAL(triggered()),this,SLOT(Tommorrow_Night_triggered()));

    //2字体大小
    QMenu *pword = psetting->addMenu(u8"字体大小");
    QAction *pword1 = pword->addAction("12");
    connect(pword1,SIGNAL(triggered()),this,SLOT(setfontsize1()));
    QAction *pword2 = pword->addAction("16");
     connect(pword2,SIGNAL(triggered()),this,SLOT(setfontsize2()));
    QAction *pword3 = pword->addAction("20");
     connect(pword3,SIGNAL(triggered()),this,SLOT(setfontsize3()));
    QAction *pword4 = pword->addAction("24");
     connect(pword4,SIGNAL(triggered()),this,SLOT(setfontsize4()));
    //字体风格
    QMenu *pwordtheme = psetting->addMenu(u8"字体风格");
    QAction *pwordtheme1 = pwordtheme->addAction("Consolas");
    connect(pwordtheme1,SIGNAL(triggered()),this,SLOT(setfontheme1()));
    QAction *pwordtheme2 = pwordtheme->addAction("AnonymousPro");
    connect(pwordtheme2,SIGNAL(triggered()),this,SLOT(setfontheme2()));
    QAction *pwordtheme3 = pwordtheme->addAction("Calibri");
    connect(pwordtheme3,SIGNAL(triggered()),this,SLOT(setfontheme3()));
    QAction *pwordtheme4 = pwordtheme->addAction("Courier");
    connect(pwordtheme4,SIGNAL(triggered()),this,SLOT(setfontheme4()));
}
//主题和字体
QString backgroundColor ="#ffffff" ;
QString foregroundColor  = "gray";
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
                "font-color:gray;"


             "}"

     ;
    configEditor->setStyleSheet(stylesheet);
}

#endif // SETTING_H
