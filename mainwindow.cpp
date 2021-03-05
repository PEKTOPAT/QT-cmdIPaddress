#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    nameInterfaces = ("Ethernet");
    Address = ("192.168.1.66");
    Mask = ("255.255.255.0");
    GateWay = ("192.168.1.1");
    netInterfaces = new NetworkInterfaces;
    netInterfaces->InfoInterfaces();
    netInterfaces->SetAddress(nameInterfaces, Address, Mask, GateWay);
}

MainWindow::~MainWindow()
{
    delete ui;
}
