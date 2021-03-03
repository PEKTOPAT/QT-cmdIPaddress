//******************************************************************************
#include "networkinterfaces.h"
//******************************************************************************
NetworkInterfaces::NetworkInterfaces()
{
      //nameInterfaces.
      Address = "192.168.1.1;
      //Mask = "255.255.255.0";
      GateWay = "192.168.1.1";
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
    cmd->start(ipconfig,cmd);

}
