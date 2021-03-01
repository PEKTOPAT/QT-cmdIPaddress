#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    interfaces = new QNetworkInterface();
    cmd = new QProcess(parent);

    //qDebug() << "mmm" << interfaces->allInterfaces();
    qDebug() << "mmm" << interfaces->name();

    //program = "C:\WINDOWS\System32\cmd.exe.";
    ui->setupUi(this);
    cmd->start("cmd");
    if (!cmd->waitForStarted())return;
    cmd->waitForReadyRead();
    QByteArray result1 = cmd->readAll();
    qDebug() << "1" << result1.data();


//    string str;
//        getline(cin,str);
//        while(str != string("exit"))
//        {
//            cmd.write(str.c_str());
//            cmd.write("\n");
//            cmd.waitForReadyRead();
//            result = cmd.readAll();
//            cout << result.data();
//            getline(cin,str);
//        }
    cmd->write("ping 8.8.8.8 -e \n");
    cmd->write("ipconfig\n");
    cmd->write("\n");
    cmd->waitForReadyRead();
    QByteArray result2 = cmd->readAll();
    qDebug() << "2" << result2.data();

    cmd->waitForReadyRead();
    QByteArray result3 = cmd->readAll();
    qDebug() << "3" << result3.data();
    //cmd->write("netsh interface ip set address name=\"Ethernet\" static 192.168.1.70 255.255.255.0 192.168.1.1");
//    cmd->waitForReadyRead();
//    QByteArray result3 = cmd->readAll();
//    qDebug() << "23" <<result3;



}

MainWindow::~MainWindow()
{
    delete ui;
}
