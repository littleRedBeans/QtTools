#ifndef EVENTDISPATCHERLIBUV_H
#define EVENTDISPATCHERLIBUV_H
#include <QtCore/QAbstractEventDispatcher>
#include "QEventDispatcherLibuv_global.h"
class EventDispatcherLibUvPrivate;

class QEVENTDISPATCHERLIBUV_EXPORT EventDispatcherLibUv : public QAbstractEventDispatcher
{
    Q_OBJECT
public:
    explicit EventDispatcherLibUv(QObject *parent = 0);
    virtual ~EventDispatcherLibUv(void);

    virtual bool processEvents(QEventLoop::ProcessEventsFlags flags);
    virtual bool hasPendingEvents(void);

    virtual void registerSocketNotifier(QSocketNotifier *notifier);
    virtual void unregisterSocketNotifier(QSocketNotifier *notifier);

    virtual void registerTimer(int timerId,
                               int interval,
#if QT_VERSION >= 0x050000
                               Qt::TimerType timerType,
#endif
                               QObject *object);

    virtual bool unregisterTimer(int timerId);
    virtual bool unregisterTimers(QObject *object);
    virtual QList<QAbstractEventDispatcher::TimerInfo> registeredTimers(QObject *object) const;
#if QT_VERSION >= 0x050000
    virtual int remainingTime(int timerId);
#endif

#if defined(Q_OS_WIN) && QT_VERSION >= 0x050000
    virtual bool registerEventNotifier(QWinEventNotifier *notifier);
    virtual void unregisterEventNotifier(QWinEventNotifier *notifier);
#endif

    virtual void wakeUp(void);
    virtual void interrupt(void);
    virtual void flush(void);

protected:
    EventDispatcherLibUv(EventDispatcherLibUvPrivate &dd, QObject *parent = 0);

private:
    Q_DISABLE_COPY(EventDispatcherLibUv)
    Q_DECLARE_PRIVATE(EventDispatcherLibUv)
#if QT_VERSION >= 0x040600
    QScopedPointer<EventDispatcherLibUvPrivate> d_ptr;
#else
    EventDispatcherLibUvPrivate *d_ptr;
#endif
};

#endif // EVENTDISPATCHERLIBUV_H
