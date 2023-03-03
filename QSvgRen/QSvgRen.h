#pragma once

#include <QQuickImageProvider>
#include <QImage>

#ifdef QSVGREN_DLL
#  ifndef QSVGREN_EXPORT
#    ifdef QSVGREN_EXPORT_LIBRARY
#      define QSVGREN_EXPORT Q_DECL_EXPORT
#    else
#      define QSVGREN_EXPORT Q_DECL_IMPORT
#    endif
#  endif
#else
#  ifndef QSVGREN_EXPORT
#    define QSVGREN_EXPORT
#  endif
#endif

class QSVGREN_EXPORT QSvgRen : public QQuickImageProvider
{
public:
    QSvgRen();

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);

    static void registerImageProvider(QQmlEngine *engine);
    static QImage render(const QString &fileName, const QSize &size);
};
