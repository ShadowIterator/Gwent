#-------------------------------------------------
#
# Project created by QtCreator 2017-09-13T09:41:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gwent_Client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    selectdialog.cpp \
    card.cpp \
    cardset.cpp \
    game.cpp \
    global.cpp \
    si_object.cpp \
    userinteraction.cpp \
    weather.cpp \
    cardwidget.cpp \
    cardsetwidget.cpp \
    fieldwidget.cpp \
    field.cpp \
    inputdialog.cpp \
    deckbuilder.cpp

HEADERS += \
        mainwindow.h \
    selectdialog.h \
    card.h \
    cardset.h \
    game.h \
    global.h \
    si_object.h \
    userinteraction.h \
    weather.h \
    cardwidget.h \
    qtgui.h \
    cardsetwidget.h \
    ui_battledialog.h \
    ui_cardsetwidget.h \
    ui_cardwidget.h \
    ui_mainwindow.h \
    ui_selectdialog.h \
    fieldwidget.h \
    ui_fieldwidget.h \
    field.h \
    inputdialog.h \
    deckbuilder.h

FORMS += \
        mainwindow.ui \
    selectdialog.ui \
    cardsetwidget.ui \
    inputdialog.ui \
    deckbuilder.ui

RESOURCES += \
    src.qrc

CONFIG += resources_big
