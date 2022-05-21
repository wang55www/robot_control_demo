cmake_minimum_required(VERSION 3.5)

project(robot_control_demo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 不同的系统环境需要修改此变量指定到QT安装路径
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt@5/5.15.2_1;/usr/local/Cellar/eigen/3.4.0_1")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories("/usr/local/Cellar/eigen/3.4.0_1/include/eigen3" "/usr/local/include")


set(TS_FILES robot_control_demo_zh_CN.ts)
file(GLOB_RECURSE EXT_SRC_DIR_LIST
    "${CMAKE_CURRENT_SOURCE_DIR}/device/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/device/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/common/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/common/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/LuaBridge/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LuaBridge/*.h"
)

message(status " this is src = ${EXT_SRC_DIR_LIST}")
message(status " INCLUDE_DIRECTORIES= ${INCLUDE_DIRECTORIES}")

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        lua_engine.h
        lua_engine.cpp
        ${EXT_SRC_DIR_LIST}
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(robot_control_demo
        ${PROJECT_SOURCES}
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(robot_control_demo SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(robot_control_demo
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(robot_control_demo PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(robot_control_demo PRIVATE "/usr/local/Cellar/jsoncpp/1.9.5/lib/libjsoncpp.dylib")
target_link_libraries(robot_control_demo PRIVATE "/usr/local/Cellar/lua@5.1/5.1.5_8/lib/liblua.5.1.5.dylib")
