#ifndef REDEFINE_H
#define REDEFINE_H

#include <QMainWindow>
#include <windows.h>
#include <windowsx.h>
#include <QMouseEvent>
#include <QProcess>
#include <handleapi.h>
#include <QShortcut>

namespace Ui {
class redefine;
}

class redefine : public QMainWindow
{
    Q_OBJECT

public:
    explicit redefine(QWidget *parent = 0);
    void write_cmd(QString cmd_str);
    ~redefine();

private:
    Ui::redefine *ui;
    QProcess *process;
    QShortcut *key;
    int boundaryWidth;
    QPoint clickPos;



public slots:
    void read_data();
    void finished_process();
    void error_process();
private slots:
    void on_closeBtn_clicked(bool checked);



};

#endif // REDEFINE_H
