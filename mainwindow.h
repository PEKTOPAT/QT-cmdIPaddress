#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <networkinterfaces.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    NetworkInterfaces *netInterfaces;
    QString nameInterfaces, Address, Mask, GateWay;

};

#endif // MAINWINDOW_H
