//******************************************************************************
#include "networkinterfaces.h"
//******************************************************************************
NetworkInterfaces::NetworkInterfaces()
{
    Interfaces = QNetworkInterface::allInterfaces();
    parent = new QObject();
    cmd = new QProcess(parent);
    //pIfRow = new MIB_IFROW();
    //qDebug() << Interfaces;
    //qDebug() << IfRow->dwIndex;


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
#if defined(Q_OS_LINUX)
    qDebug() << "LINUX";
//    qDebug() << "Состояние до start" <<fly_term->state();
//        QByteArray command = "sudo su";
//        fly_term->start(command, QIODevice::ReadWrite);
//        fly_term->waitForStarted();
//        qDebug() << "Состояние после start" <<fly_term->state();
//        command = "echo \"auto lo\niface lo inet loopback\nauto eth0\niface eth0 inet static\n"
//                  "address 192.168.6.71\n"
//                  "gateway 192.168.6.1\n"
//                  "netmask 255.255.255.0\n"
//                  "network 192.168.6.0\n"
//                  "broadcast 192.168.6.255\n\" > /etc/network/interfaces; "
//                  "sudo ip addr flush eth0; "
//                  "sudo ifdown -a;"
//                  "sudo ifup -a";
//        fly_term->write(command);
//        fly_term->closeWriteChannel();
#elif defined(Q_OS_WIN)
    qDebug() << "WIN";
    //    qDebug() << "Sostoianie1" <<  cmd->state();
    //    cmd->start("cmd");
    //    qDebug() << "Sostoianie2" <<  cmd->state();
    //    cmd->waitForReadyRead();
    //    QByteArray result = cmd->readAll();
    //    QByteArray in = "netsh interface ipv4 set address name=\"Ethernet\" static 192.168.3.10 255.255.255.0 192.168.3.1\n";
    //    qDebug() << result.data();
    //    cmd->write(in);
    //    while(cmd->waitForReadyRead(30000))
    //    {
    //        result = cmd->readAll();
    //        qDebug() << result.data();
    //    }
#else
   qDebug() << "Undefined";
#endif
}

