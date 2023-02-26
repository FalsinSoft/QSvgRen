#include <QFile>
#include <QScreen>
#include <QApplication>
#include <QQuickImageProvider>
#include "svgren/render.hpp"
#include "QSvgRen.h"

QSvgRen::QSvgRen() : QQuickImageProvider(QQuickImageProvider::Image)
{
}

QImage QSvgRen::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
	const QImage image = render(id, requestedSize);
	*size = requestedSize;
	return image;
}

void QSvgRen::registerImageProvider(QQmlEngine *engine)
{
	engine->addImageProvider(QLatin1String("QSvgRen"), new QSvgRen);
}

QImage QSvgRen::render(const QString &fileName, const QSize &size)
{
	QImage image(size, QImage::Format_RGBA8888);
	QFile file(fileName);

	if(file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		auto dom = svgdom::load(file.readAll().toStdString());

		if(dom)
		{
			const QScreen *screen = QApplication::primaryScreen();
			svgren::parameters p;
			svgren::result data;

			p.dpi = screen->devicePixelRatio();
			p.dims_request.x() = size.width();
			p.dims_request.y() = size.height();
			data = svgren::render(*dom, p);

			if(data.pixels.size() > 0)
			{
				for(int i = 0; i < size.height(); ++i)
				{
					memcpy(image.scanLine(i), data.pixels.data() + i * size.width(), size.width() * 4);
				}
			}
		}
	}

	return image;
}
