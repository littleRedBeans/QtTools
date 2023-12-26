#ifndef UVUDPSOCKET_H
#define UVUDPSOCKET_H

#include <QObject>
#include "uv.h"
class UvUDPSocket : public QObject
{
    Q_OBJECT
public:
    explicit UvUDPSocket(const QString &_addr, quint16 _port, QObject *parent = nullptr);
    QString getAddr();
    quint16 getPort();
signals:
private:
    void init();
    uv_udp_t *socket;
    QString addr;
    quint16 port;
};

#endif // UVUDPSOCKET_H
