#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QSvgRen.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QSvgRen::registerImageProvider(&engine);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if(engine.rootObjects().isEmpty()) return -1;

    return app.exec();
}
