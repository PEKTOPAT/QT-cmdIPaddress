#ifndef NETWORKINTERFACES_H
#define NETWORKINTERFACES_H

#include <QNetworkInterface>
#include <QProcess>
#include <QDebug>
#include <QNetworkAddressEntry>



class NetworkInterfaces
{
public:
    NetworkInterfaces();

public slots:
    QString InfoInterfaces();
    void SetAddress(QString nameInterfaces, QString Address, QString Mask, QString GateWay);
protected:

private slots:


private:

    QProcess *cmd;
    QNetworkInterface *interface;
    QObject *parent;
    QList <QNetworkInterface> Interfaces;

//    QString program;
//    QStringList arguments;
public:

};

#endif // NETWORKINTERFACES_H
