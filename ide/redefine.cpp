#include "redefine.h"
#include "ui_redefine.h"
#include "mainwindow.h"
#include <qDebug>
#include <QShortcut>
#include <qtoolbutton.h>
redefine::redefine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::redefine)
{
    //setWindowTitle("cmd text");


    ui->setupUi(this);
    ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
    ui->closeBtn->resize(200,200);

    /* 新建process */
    process = new QProcess(this);
    process->setProcessChannelMode(QProcess::MergedChannels);
    process->start("cmd.exe");


    /* 命令行相关 */
    connect(process,SIGNAL(readyRead()),this,SLOT(read_data()));                                    //读命令行数据
    connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(read_data()));                      //读命令行标准数据（兼容）
    connect(process,SIGNAL(errorOccurred(QProcess::ProcessError)),this,SLOT(error_process()));      //命令行错误处理
    connect(process,SIGNAL(finished(int)),this,SLOT(finished_process()));                           //命令行结束处理

    /* 焦点相关 */
}

redefine::~redefine()
{
    /* 关闭cmd */
    process->close();

    /* 释放空间 */
    delete ui;
    delete process;

    /* 拴住 */
    ui = NULL;
    process = NULL;

    /* 信息输出 */
    qDebug() << "end Process" << endl;
}

void redefine::write_cmd(QString cmd_str)
{
    /* 获得命令，\r\n代替键盘的Enter，没有则不会执行 */
    QString cmd = cmd_str + "\r\n";

    /* 转为char*并写入 */
    QByteArray qbarr = cmd.toLatin1();
    char *ch = qbarr.data();
    qint64 len = cmd.length();
    process->write(ch, len);

    /* 信息输出 */
    qDebug() << "Success:write_cmd：" << cmd << endl;
}

void redefine::read_data()
{
    /* 接收数据 */
    QByteArray bytes = process->readAll();

    /* 显示 */
    QString msg = QString::fromLocal8Bit(bytes);
    ui->textEdit->append(msg);
    ui->textEdit->update();

    /* 信息输出 */
    qDebug() << "Success:read_data:" << msg << endl;

}

void redefine::finished_process()
{
    /* 接收数据 */
    int flag = process->exitCode();

    /* 信息输出 */
    qDebug() << "Success:finishedProcess():" << flag << endl;
}

void redefine::error_process()
{
    /* 接收数据 */
    int err_code  = process->exitCode();
    QString err = process->errorString();

    /* 显示 */
    ui->textEdit->append(QString("error code:%1").arg(err_code));
    ui->textEdit->append(err);

    /* 信息输出 */
    qDebug() << "Success:error_process():" << err << endl;
}

void redefine::on_closeBtn_clicked(bool checked)
{
    this->close();
}




