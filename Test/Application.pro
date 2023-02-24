QT += core quick widgets
CONFIG += c++11

INCLUDEPATH += \
    $$PWD/../QSvgRen
LIBS += \
    -L$$PWD/../QSvgRen \
    -lQSvgRen

RESOURCES += \
    main.qrc \
    qml.qrc

SOURCES += \
    main.cpp

