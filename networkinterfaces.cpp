//******************************************************************************
#ifdef _WIN32
#include <winsock2.h>
#include <iphlpapi.h>
#elif __linux__
#endif
//******************************************************************************
#include "networkinterfaces.h"
//******************************************************************************
#define dhcpMode "ON"; // ON/OFF
//******************************************************************************
NetworkInterfaces::NetworkInterfaces()
{
    Interfaces = QNetworkInterface::allInterfaces();
    parent = new QObject();
    cmd = new QProcess(parent);
}
//----------------------------------------------------------------------------------
//***---------------Функция получения  информации об интерфейсе-------------------***
//----------------------------------------------------------------------------------
QStringList NetworkInterfaces::InfoInterfaces()
{
    ListEthInterfaces.clear();
    if(Interfaces.size() == 0) return ListEthInterfaces;
#if defined(Q_OS_LINUX)
    QNetworkInterface::InterfaceType InterfaceType;
    for(int i = 0; i < Interfaces.size(); i++)
    {
        InterfaceType = Interfaces[i].type();
        if (InterfaceType == QNetworkInterface::Ethernet) ListEthInterfaces.append(Interfaces[i].humanReadableName());
    }
    return ListEthInterfaces;
#elif defined(Q_OS_WIN)
    /* variable used for GetIfEntry */
    MIB_IFROW str_IfRow;
    for(int i = 0; i < Interfaces.size(); i++)
    {
        str_IfRow.dwIndex = Interfaces[i].index();
        if (GetIfEntry(&str_IfRow) != NO_ERROR) return ListEthInterfaces;;
        if(str_IfRow.dwType == IF_TYPE_ETHERNET_CSMACD)
        {
            ListEthInterfaces.append(Interfaces[i].humanReadableName());
        }

    }
    return ListEthInterfaces;
#else
    qDebug() << "Undefined OS";
    return ListEthInterfaces;
#endif
    return ListEthInterfaces;
}
//----------------------------------------------------------------------------------
//***--Функция установки статических сетевых надстроек компьютера (UNIX or WIN)-***
//----------------------------------------------------------------------------------
void NetworkInterfaces::SetAddress(QString nameInterfaces, QString Address, QString Mask, QString GateWay)
{
    QString Mode = dhcpMode;
#if defined(Q_OS_LINUX)
    QString command = "sudo su";
    cmd->start(command, QIODevice::ReadWrite);
    cmd->waitForStarted();
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
    cmd->write(commandArray);
    cmd->closeWriteChannel();
#elif defined(Q_OS_WIN)
    QString command = "";
    cmd->start("cmd");
    cmd->waitForReadyRead();
    QByteArray result = cmd->readAll();
    qDebug() << result.data();
    if(Mode == "ON")
    {
        command = "netsh interface ip set address \"<name>\" dhcp\n";
        command.replace("<name>", nameInterfaces);
    }else if(Mode == "OFF")
    {
        command = "netsh interface ipv4 set address name=\"<name>\" static <address> <netmask> <gateway>\n";
        command.replace("<name>", nameInterfaces);
        command.replace("<address>", Address);
        command.replace("<gateway>", GateWay);
        command.replace("<netmask>", Mask);
    }
    QByteArray commandArray = command.toUtf8();
    cmd->write(commandArray);
    cmd->closeWriteChannel();
#else
    qDebug() << "Undefined OS";
#endif

}
