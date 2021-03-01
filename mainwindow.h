#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QNetworkInterface>

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
//    QObject *parent;
//    QString program = "C:\WINDOWS\System32\cmd.exe";
//    QProcess *myProcess = new QProcess(parent);
    QObject *parent;
    QString program;
    QStringList arguments;
    QProcess *cmd;
    QNetworkInterface *interfaces;
};

#endif // MAINWINDOW_H
