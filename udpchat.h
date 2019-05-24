#ifndef UDPCHAT_H
#define UDPCHAT_H

#include <QUdpSocket>
#include <QHostAddress>

namespace Udp {
class UdpChat;
}

class UdpChat : public QUdpSocket
{
public:
    UdpChat(QUdpSocket *parent=0);

    QUdpSocket *Usocket;

    void Ubind(QHostAddress host,quint16 port);

    void setUport(quint16 port){UmyPort = port;}
    quint16 getUport(){return UmyPort;}

    QHostAddress getUmyAddr(){return UmyAddr;}

    QHostAddress GetlocalAddr();



    void UreadData(char *data, qint64 len);

    void UwriteData(QByteArray data,QHostAddress addr, quint16 port);

    ~UdpChat();

private:
    QHostAddress UmyAddr;
    quint16 UmyPort;

};

#endif // UDPCHAT_H
