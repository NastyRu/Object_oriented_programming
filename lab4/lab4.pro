#-------------------------------------------------
#
# Project created by QtCreator 2019-05-20T22:08:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab4
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    facade.cpp \
    managers.cpp \
    commands.cpp \
    scene_container.cpp \
    objects.cpp \
    positions.cpp \
    points.cpp \
    camera.cpp \
    model.cpp \
    edges.cpp \
    matrix.cpp \
    draw.cpp \
    file_loader.cpp \
    file_save.cpp \
    model_builder.cpp

HEADERS += \
        mainwindow.h \
    facade.h \
    managers.h \
    commands.h \
    scene_container.h \
    objects.h \
    positions.h \
    points.h \
    camera.h \
    model.h \
    exceptions.h \
    iterators.h \
    base_builder.h \
    edges.h \
    matrix.h \
    base_draw.h \
    draw.h \
    file_loader.h \
    file_save.h \
    model_builder.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
