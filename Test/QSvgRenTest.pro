TEMPLATE = subdirs

SUBDIRS = \
    Application \
    QSvgRen

Application.file = Application.pro
QSvgRen.file = ../QSvgRen/QSvgRen.pro

Application.depends = QSvgRen
