#ifndef UDP_H
#define UDP_H
#include <QThread>
#include "UDP_global.h"
class UDPPrivate;
class UDP_EXPORT UDP final : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UDP)
    Q_DISABLE_COPY(UDP)
    UDPPrivate *d_ptr;
    QThread *workThread;

public:
    explicit UDP();
    ~UDP();
    static UDP *instance();

    void bind(QString addr, quint16 port);

private:
};

#endif // UDP_H
