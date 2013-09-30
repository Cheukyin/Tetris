#-------------------------------------------------
#
# Project created by QtCreator 2013-08-18T09:44:45
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tetrix
TEMPLATE = app


SOURCES += main.cpp \
    TGLWidget.cpp \
    MAINWINDOW.cpp \
    OPERATOR.cpp \
    BLOCK.cpp \
    BLOCK_MATRIX.cpp \
    PGLWidget.cpp \
    USERDIALOG.cpp \
    SCORERECORD.cpp

HEADERS  += \
    TGLWidget.h \
    MAINWINDOW.h \
    OPERATOR.h \
    BLOCK.h \
    BLOCK_MATRIX.h \
    PGLWidget.h \
    USERDIALOG.h \
    SCORERECORD.h

FORMS    += mainwindow.ui
