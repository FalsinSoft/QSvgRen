cmake_minimum_required(VERSION 3.16)

project(QSvgRenTest VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Quick)

qt_add_executable(QSvgRenTest
    main.cpp
    main.qrc
    qml.qrc
)

qt_add_qml_module(QSvgRenTest
    URI QSvgRenTest
    VERSION 1.0
    QML_FILES main.qml 
)

target_link_libraries(QSvgRenTest PRIVATE
    Qt::Core
    Qt::Widgets
    Qt::Quick
)

add_subdirectory(../QSvgRen ../QSvgRen)
target_include_directories(QSvgRenTest PRIVATE ../QSvgRen)
target_link_libraries(QSvgRenTest PRIVATE QSvgRen)
