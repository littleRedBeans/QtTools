QT -= gui

TEMPLATE = lib
DEFINES += QEVENTDISPATCHERLIBUV_LIBRARY

CONFIG += c++17 plugin
DESTDIR = ../../../../bin
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
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
