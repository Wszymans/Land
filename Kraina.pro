#-------------------------------------------------
#
# Project created by QtCreator 2018-05-30T18:05:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kraina
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


SOURCES += \
        main.cpp \
        land.cpp \
    animal.cpp \
    territory.cpp \
    continent.cpp \
    continentwindow.cpp \
    plant.cpp \
    marine.cpp \
    country.cpp \
    marinewindow.cpp \
    continenteditwindow.cpp

HEADERS += \
        land.h \
    animal.h \
    territory.h \
    continent.h \
    continentwindow.h \
    plant.h \
    marine.h \
    country.h \
    marinewindow.h \
    continenteditwindow.h

FORMS += \
        land.ui \
    continentwindow.ui \
    marinewindow.ui \
    continenteditwindow.ui
