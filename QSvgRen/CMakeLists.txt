cmake_minimum_required(VERSION 3.14)

project(QSvgRen LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Quick)

file(GLOB AGG_SRC "agg/*.h" "agg/ctrl/*.h" "agg/util/*.h" "agg/*.cpp" "agg/ctrl/*.cpp")
file(GLOB_RECURSE CSSOM_SRC "cssom/*.hpp" "cssom/*.cpp")
file(GLOB_RECURSE MIKROXML_SRC "mikroxml/*.hpp" "mikroxml/*.cpp")
file(GLOB_RECURSE PAPKI_SRC "papki/*.hpp" "papki/*.hxx" "papki/*.cpp")
file(GLOB_RECURSE R4_SRC "r4/*.hpp" "r4/*.cpp")
file(GLOB_RECURSE SVGDOM_SRC "svgdom/*.hpp" "svgdom/*.hxx" "svgdom/*.cpp")
file(GLOB_RECURSE SVGREN_SRC "svgren/*.hxx" "svgren/*.cpp")
file(GLOB_RECURSE UTKI_SRC "utki/*.hpp" "utki/*.hxx" "utki/*.cpp")
file(GLOB_RECURSE ZLIB_SRC "zlib/*.h" "zlib/*.c")
add_library(${PROJECT_NAME} SHARED
    QSvgRen.cpp
    QSvgRen.h
    ${AGG_SRC}
    ${CSSOM_SRC}
    ${MIKROXML_SRC}
    ${PAPKI_SRC}
    ${R4_SRC}
    ${SVGDOM_SRC}
    ${SVGREN_SRC}
    ${UTKI_SRC}
    ${ZLIB_SRC}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/agg/
    ${CMAKE_CURRENT_SOURCE_DIR}/ zlib/
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Quick
)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    QSVGREN_DLL
    QSVGREN_EXPORT_LIBRARY
)
