#ifndef UDP_GLOBAL_H
#define UDP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UDP_LIBRARY)
#  define UDP_EXPORT Q_DECL_EXPORT
#else
#  define UDP_EXPORT Q_DECL_IMPORT
#endif

#endif // UDP_GLOBAL_H
