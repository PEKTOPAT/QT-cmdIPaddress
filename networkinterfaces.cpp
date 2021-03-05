//******************************************************************************
#include "networkinterfaces.h"
//******************************************************************************
NetworkInterfaces::NetworkInterfaces()
{
      Interfaces = QNetworkInterface::allInterfaces();
      parent = new QObject();
      cmd = new QProcess(parent);
      qDebug() << Interfaces;


}
//----------------------------------------------------------------------------------
//***--------Функция получения  информации о интерфейсе--------***
//----------------------------------------------------------------------------------
QString NetworkInterfaces::InfoInterfaces()
{  
    for (int i = 0; i < Interfaces.size(); i++)
    {
        qDebug() << Interfaces[i].humanReadableName();
        qDebug() << Interfaces[i].name();
    }
    return 0;
}
//----------------------------------------------------------------------------------
//***--------Функция построения доплеровского смещения несущей частоты--------***
//----------------------------------------------------------------------------------
void NetworkInterfaces::SetAddress(QString nameInterfaces, QString Address, QString Mask, QString GateWay)
{
    cmd->start("cmd");
    cmd->waitForReadyRead();
    QByteArray result = cmd->readAll();
    QByteArray in = "netsh interface ipv4 set address name=\"Ethernet\" static 192.168.1.100 255.255.255.0 192.168.10.1\n";
    qDebug() << result.data();
    cmd->write(in);
    while(cmd->waitForReadyRead(30000))
    {
        result = cmd->readAll();
        qDebug() << result.data();
}




}
