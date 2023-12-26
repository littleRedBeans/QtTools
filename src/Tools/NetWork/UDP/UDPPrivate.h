#ifndef UDPPRIVATE_H
#define UDPPRIVATE_H
#include <QSharedPointer>
#include "UDP.h"
#include "UvUDPSocket.h"
#include <mutex>
class UDPPrivate : public QObject
{
    Q_OBJECT
    UDPPrivate(UDP *p, QObject *parent = nullptr);
    ~UDPPrivate();

private:
    void bind(const QString &addr, quint16 port);
    Q_DECLARE_PUBLIC(UDP)
    UDP *const q_ptr;
    QSharedPointer<UvUDPSocket> socket;
    QString m_addr;
    quint16 m_port;
    std::mutex mutex;
};

#endif // UDPPRIVATE_H
