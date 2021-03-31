#include "mainwindow.h"
#include "ui_mainwindow.h"
//******************************************************************************
#define Address "192.168.2.19"
#define Mask "255.255.255.0"
#define GateWay "192.168.2.1"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    netInterfaces = new NetworkInterfaces;
    nameInterfaces = (netInterfaces->InfoInterfaces())[2];
    qDebug() << "Use interfaces:" << nameInterfaces;
    netInterfaces->SetAddress(nameInterfaces, Address, Mask, GateWay);
}

MainWindow::~MainWindow()
{
    delete ui;
}
