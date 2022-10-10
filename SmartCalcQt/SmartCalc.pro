#-------------------------------------------------
#
# Project created by QtCreator 2022-08-20T01:11:55
#
#-------------------------------------------------

CONFIG += qt release warn_off console
QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FirstQtCreatorOpen
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
        mainwindow.cpp \
        depositwindow.cpp \
        creditwindow.cpp \
        qcustomplot.cpp \
    ../src/s21_check.c \
    ../src/s21_credit.c \
    ../src/s21_deposit.c \
    ../src/s21_Engine.c \
    ../src/s21_Stack.c

HEADERS += \
        mainwindow.h \
        depositwindow.h \
        qcustomplot.h \
        creditwindow.h \
    ../src/s21_Calculate.h \
    ../src/s21_Engine.h \
    ../src/s21_Stack.h

FORMS += \
        mainwindow.ui \
        depositwindow.ui \
        creditwindow.ui

DISTFILES += \
    ../src/Makefile
