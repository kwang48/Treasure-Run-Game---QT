#-------------------------------------------------
#
# Project created by QtCreator 2016-02-04T14:19:59
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homework5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    enemy.cpp \
    game.cpp \
    health.cpp \
    score.cpp \
    weapon.cpp

HEADERS  += mainwindow.h \
    player.h \
    enemy.h \
    game.h \
    health.h \
    score.h \
    weapon.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
