//******************************************************************************
#include "networkinterfaces.h"
//******************************************************************************
NetworkInterfaces::NetworkInterfaces()
{
    Interfaces = QNetworkInterface::allInterfaces();
    parent = new QObject();
    cmd = new QProcess(parent);
    fly_term = new QProcess(parent);
    //qDebug() << Interfaces;


}
//----------------------------------------------------------------------------------
//***--------Функция получения  информации о интерфейсе--------***
//----------------------------------------------------------------------------------
QString NetworkInterfaces::InfoInterfaces()
{  
    for (int i = 0; i < Interfaces.size(); i++)
    {
        //qDebug() << Interfaces[i].humanReadableName();
        //qDebug() << Interfaces[i].name();
    }
    return 0;
}
//----------------------------------------------------------------------------------
//***--------Функция построения доплеровского смещения несущей частоты--------***
//----------------------------------------------------------------------------------
void NetworkInterfaces::SetAddress(QString nameInterfaces, QString Address, QString Mask, QString GateWay)
{
    qDebug() << "Состояние до start" <<fly_term->state();
    QByteArray command = "sudo su";
    fly_term->start(command, QIODevice::ReadWrite);
    fly_term->waitForStarted();
    qDebug() << "Состояние после start" <<fly_term->state();
    command = "echo \"auto lo\niface lo inet loopback\nauto eth0\niface eth0 inet static\n"
              "address 192.168.6.71\n"
              "gateway 192.168.6.1\n"
              "netmask 255.255.255.0\n"
              "network 192.168.6.0\n"
              "broadcast 192.168.6.255\n\" > /etc/network/interfaces; "
              "sudo ip addr flush eth0; "
              "sudo ifdown -a;"
              "sudo ifup -a";
    fly_term->write(command);
    fly_term->closeWriteChannel();

//    fly_term->waitForFinished();
//    command = ("sudo ifdown -a; sudo ifup -a");
//    fly_term->write(command);
//    fly_term->closeWriteChannel();
//    qDebug() << fly_term->readAllStandardError();
//    qDebug() << fly_term->readAllStandardOutput();
//    command = "nmcli device modify eth0 ipv4.gateway 192.168.34.1";
//    fly_term->write(command);
//    command = "sudo service networking restart";
//    fly_term->write(command);
//    resultLin= fly_term->readAll();
//    qDebug() << "result2" << resultLin.data();
    //fly_term->waitForFinished();
    //fly_term->close();
    //delete fly_term;
    //cmd->write(in);

    //    while(cmd->waitForReadyRead(30000))
    //    {
    //        result = cmd->readAll();
    //        qDebug() << "ANDREI" << result.data();
    //}
}
