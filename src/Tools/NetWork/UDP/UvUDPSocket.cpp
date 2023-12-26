#include "UvUDPSocket.h"

UvUDPSocket::UvUDPSocket(const QString &_addr, quint16 _port, QObject *parent)
    : QObject{parent}
    , addr(_addr)
    , port(_port)
{
    
}

QString UvUDPSocket::getAddr()
{
    return addr;
}

quint16 UvUDPSocket::getPort()
{
    return port;
}

void UvUDPSocket::init() {}
