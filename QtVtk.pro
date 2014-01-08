#-------------------------------------------------
#
# Project created by QtCreator 2014-01-08T01:36:39
#
#-------------------------------------------------

QT       += core gui

TARGET = QtVtk
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS    += -L/usr/lib/vtk-5.8 -lvtkCommon\
           -lvtksys -lQVTK -lvtkViews -lvtkWidgets\
           -lvtkInfovis -lvtkRendering -lvtkGraphics\
           -lvtkImaging -lvtkIO -lvtkFiltering\
           -lvtkDICOMParser -lvtkHybrid

INCLUDEPATH += /usr/include/vtk-5.8
