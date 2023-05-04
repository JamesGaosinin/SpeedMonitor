#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CHARTWIDGET_LIB)
#  define CHARTWIDGET_EXPORT Q_DECL_EXPORT
# else
#  define CHARTWIDGET_EXPORT Q_DECL_IMPORT
# endif
#else
# define CHARTWIDGET_EXPORT
#endif
