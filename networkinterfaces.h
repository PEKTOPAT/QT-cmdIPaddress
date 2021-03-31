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
    QStringList InfoInterfaces();
    void SetAddress(QString nameInterfaces, QString Address, QString Mask, QString GateWay);
protected:

private slots:
    QString osVersion();

private:

    QProcess *cmd;
    QObject *parent;
    QList <QNetworkInterface> Interfaces;
    QStringList ListEthInterfaces;
public:

};

#endif // NETWORKINTERFACES_H
