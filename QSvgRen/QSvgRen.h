#pragma once

#include <QQuickImageProvider>
#include <QImage>

class QSvgRen : public QQuickImageProvider
{
public:
    QSvgRen();

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);

    static void registerImageProvider(QQmlEngine *engine);
    static QImage render(const QString &fileName, const QSize &size);
};
