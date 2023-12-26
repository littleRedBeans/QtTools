#include "UDP.h"
#include <QTimer>
#include "UDPPrivate.h"
Q_GLOBAL_STATIC(UDP, pinstance);
UDPPrivate::UDPPrivate(UDP *p, QObject *parent)
    : QObject(parent)
    , q_ptr(p)
{}

void UDPPrivate::bind(const QString &addr, quint16 port)
{
    Q_Q(UDP);
    std::lock_guard<std::mutex> lock(mutex);
    if (QString("%1%2").arg(socket->getAddr()).arg(socket->getPort())
        == QString("%1%2").arg(addr).arg(port)) {
        return;
    }
    socket = QSharedPointer<UvUDPSocket>(new UvUDPSocket(addr, port), &UvUDPSocket::deleteLater);
    socket->moveToThread(q->workThread);
    QTimer::singleShot(0, socket.data(), SLOT(init()));
}

UDP::UDP()
    : QObject(nullptr)
    , d_ptr(new UDPPrivate(this))
    , workThread(new QThread)
{
    this->moveToThread(workThread);
    workThread->start();
}

UDP::~UDP()
{
    workThread->quit();
    workThread->wait();
}

UDP *UDP::instance()
{
    return pinstance;
}

void UDP::bind(QString addr, quint16 port)
{
    Q_D(UDP);
    d->bind(addr, port);
}
