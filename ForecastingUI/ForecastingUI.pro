#-------------------------------------------------
#
# Project created by QtCreator 2019-01-27T22:24:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ForecastingUI
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
        qsmasettingswidget.cpp \
        qwmasettingswidget.cpp \
    qessettingswidget.cpp \
    qltpsettingswidget.cpp \
    qnumbersettingswidget.cpp \
    main.cpp \
    mainwindow.cpp \
    qessettingswidget.cpp \
    qltpsettingswidget.cpp \
    qnumbersettingswidget.cpp \
    qsmasettingswidget.cpp \
    qwmasettingswidget.cpp \
    Logic/qmodellogic.cpp

HEADERS += \
        mainwindow.h \
        qsmasettingswidget.h \
        qwmasettingswidget.h \
    qessettingswidget.h \
    qltpsettingswidget.h \
    qnumbersettingswidget.h \
    Logic/ES.h \
    mainwindow.h \
    qessettingswidget.h \
    qltpsettingswidget.h \
    qnumbersettingswidget.h \
    qsmasettingswidget.h \
    qwmasettingswidget.h \
    Logic/ES.h \
    Logic/fileGenerator.h \
    Logic/LTP.h \
    Logic/SMA.h \
    Logic/vectorGenerator.h \
    Logic/WMA.h \
    mainwindow.h \
    qessettingswidget.h \
    qltpsettingswidget.h \
    qnumbersettingswidget.h \
    qsmasettingswidget.h \
    qwmasettingswidget.h \
    Logic/qmodellogic.h \
    Logic/quantitativemethodbase.h

FORMS += \
        mainwindow.ui \
        qsmasettingswidget.ui \
        qwmasettingswidget.ui \
    qessettingswidget.ui \
    qltpsettingswidget.ui \
    qnumbersettingswidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
