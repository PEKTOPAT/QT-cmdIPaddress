#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        netInterfaces = new NetworkInterfaces;
        netInterfaces->InfoInterfaces();

        netInterfaces->SetAddress(QString Ethernet, QString 192.168.1.111, QString 255.255.255.0, QString 192.168.1.1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
