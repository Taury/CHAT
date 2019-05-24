#include "udpchat.h"
#include <QHostInfo>



UdpChat::UdpChat(QUdpSocket *parent)
    :QUdpSocket(parent)
{
    Usocket = new QUdpSocket();
}

void UdpChat::Ubind(QHostAddress host,quint16 port)
{
    UmyAddr = host;
    UmyPort = port;
    Usocket->bind(UmyAddr,UmyPort);
}

UdpChat::~UdpChat()
{
    delete Usocket;
}

QHostAddress UdpChat::GetlocalAddr()
{
    QHostInfo hostinfo = QHostInfo::fromName(QHostInfo::localHostName());

    QHostAddress addr;
    foreach (addr, hostinfo.addresses())
    {
        if(addr.protocol() == QAbstractSocket::IPv4Protocol)
            break;
    }
    return addr;
}

void UdpChat::UreadData(char *data, qint64 len)
{
    Usocket->readDatagram(data,len,&UmyAddr,&UmyPort);
}

void UdpChat::UwriteData(QByteArray data, QHostAddress addr, quint16 port)
{
    Usocket->writeDatagram(data,addr,port);
}

