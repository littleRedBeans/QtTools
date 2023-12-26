QT -= gui

TEMPLATE = lib
DEFINES += UDP_LIBRARY

CONFIG += c++17 plugin

DESTDIR = ../../../../bin
LIBS += -L../../../../bin
LIBS += -luv -lQEventDispatcherLibuv
INCLUDEPATH += ../../../../include/Tools/NetWork/QEventDispatcherLibuv
INCLUDEPATH += ../../../../include/Tools/NetWork/
SOURCES += \
    UDP.cpp \
    UDPManager.cpp \
    UvUDPSocket.cpp

HEADERS += \
    UDPManager.h \
    UDPPrivate.h \
    UDP_global.h \
    UDP.h \
    UvUDPSocket.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
