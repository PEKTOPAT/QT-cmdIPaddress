//******************************************************************************
#ifdef Q_OS_WIN
#include <winsock2.h>
#include <iphlpapi.h>
#else
#endif
//******************************************************************************
#include "networkinterfaces.h"
//******************************************************************************
#define dhcpMode "OFF"; // ON/OFF
//******************************************************************************
NetworkInterfaces::NetworkInterfaces()
{
    Interfaces = QNetworkInterface::allInterfaces();
    parent = new QObject();
    cmdWIN = new QProcess(parent);
    cmdUNIX = new QProcess(parent);
}
//----------------------------------------------------------------------------------
//***---------------Функция получения  информации об интерфейсе-------------------***
//----------------------------------------------------------------------------------
QStringList NetworkInterfaces::InfoInterfaces()
{
    ListEthInterfaces.clear();
    if(Interfaces.size() == 0) return ListEthInterfaces;
#if defined(Q_OS_LINUX)
    for(int i = 0; i < Interfaces.size(); i++)
    {
        InterfaceType = Interfaces[i].type();
        if (InterfaceType == QNetworkInterface::Ethernet) ListEthInterfaces.append(Interfaces[i].humanReadableName());
    }
    return ListEthInterfaces;
#elif defined(Q_OS_WIN)

#else
    qDebug() << "Undefined OS";
    return ListEthInterfaces;
#endif

}
//----------------------------------------------------------------------------------
//***--Функция установки статических сетевых надстроек компьютера (UNIX or WIN)-***
//----------------------------------------------------------------------------------
void NetworkInterfaces::SetAddress(QString nameInterfaces, QString Address, QString Mask, QString GateWay)
{
    QString Mode = dhcpMode;
#if defined(Q_OS_LINUX)
    QString command = "sudo su";
    cmdUNIX->start(command, QIODevice::ReadWrite);
    cmdUNIX->waitForStarted();
    if(Mode == "ON")
    {
        command = "echo \"auto lo\niface lo inet loopback\nauto <name>\niface <name> inet dhcp\" > /etc/network/interfaces; "
                  "sudo ip addr flush eth0; "
                  "sudo ifdown -a;"
                  "sudo ifup -a";
        command.replace("<name>", nameInterfaces);
    }else if(Mode == "OFF")
    {
        command = "echo \"auto lo\niface lo inet loopback\nauto <name>\niface <name> inet static\n"
                  "address <address>\n"
                  "gateway <gateway>\n"
                  "netmask <netmask>\n\" > /etc/network/interfaces; "
                  "sudo ip addr flush eth0; "
                  "sudo ifdown -a;"
                  "sudo ifup -a";
        command.replace("<name>", nameInterfaces);
        command.replace("<address>", Address);
        command.replace("<gateway>", GateWay);
        command.replace("<netmask>", Mask);
    }
    QByteArray commandArray = command.toUtf8();
    cmdUNIX->write(commandArray);
    cmdUNIX->closeWriteChannel();
#elif defined(Q_OS_WIN)
    qDebug() << "\t\tWINDOWS Network devices:";
    /* variable used for GetIfEntry */
    MIB_IFROW str_IfRow;
    for(int i = 0; i < Interfaces.size(); i++)
    {
        str_IfRow.dwIndex = Interfaces[i].index();
        if (GetIfEntry(&str_IfRow) != NO_ERROR) qDebug() << "ERROR";
        if(str_IfRow.dwType == IF_TYPE_ETHERNET_CSMACD)
        {
            NetEthDevices.append(Interfaces[i].humanReadableName());
            qDebug() << Interfaces[i].humanReadableName();
        }
    }
    qDebug() << "Состояние до start" <<  cmdWIN->state();
    cmdWIN->start("cmdWIN");
    qDebug() << "Состояние после start" <<  cmdWIN->state();
    cmdWIN->waitForReadyRead();
    QByteArray result = cmdWIN->readAll();
    qDebug() << result.data();
    QByteArray in = "netsh interface ipv4 set address name=\"Ethernet\" static 192.168.3.10 255.255.255.0 192.168.3.1\n";
    cmdWIN->write(in);
    //        while(cmdWIN->waitForReadyRead(30000))
    //        {
    //            result = cmdWIN->readAll();
    //            qDebug() << result.data();
    //        }
#else
    qDebug() << "Undefined OS";
#endif
}
