cmake_minimum_required(VERSION 3.16)

project(QSvgRenTest LANGUAGES C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Quick)

qt_add_executable(${PROJECT_NAME}
    main.cpp
    main.qrc
    qml.qrc
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets Qt6::Quick)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../QSvgRen)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../QSvgRen QSvgRen)
target_link_libraries(${PROJECT_NAME} PRIVATE QSvgRen)

if(ANDROID)
    set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android)
    add_custom_target(Android SOURCES
        android/AndroidManifest.xml
        android/build.gradle
        android/gradle.properties
    )
endif()
