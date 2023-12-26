QT -= gui

TEMPLATE = lib
DEFINES += QEVENTDISPATCHERLIBUV_LIBRARY

CONFIG += c++17 plugin
DESTDIR = ../../../../bin
LIBS += -L../../../../bin
LIBS += -luv

SOURCES += \
    EventDispatcherLibUv.cpp \
    eventdispatcher_libuv_p.cpp \
    socknot_p.cpp \
    timers_p.cpp

HEADERS += \
    QEventDispatcherLibuv_global.h \
    EventDispatcherLibUv.h \
    eventdispatcher_libuv_p.h

INCLUDEPATH += ../../../../include/Tools/NetWork/
win32 {
        HEADERS += win32_utils.h
        SOURCES += win32_utils.cpp
}
QMAKE_POST_LINK = chmod +x ./Install.sh && ./Install.sh
# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
