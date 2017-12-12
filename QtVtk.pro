#-------------------------------------------------
#
# Project created by QtCreator 2014-01-08T01:36:39
#
# Mirosław Socha : socha@agh.edu.pl
#
# http://mirek-socha.github.io/QtVtkStarter
#
#-------------------------------------------------

QT       += core gui

TARGET = QtVtk
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

# VTK - warto sprawdzić, czy na danym komuterze te ścieżki i pliki faktycznie istnieją i są poprawne
LIBS    += -L/usr/lib -lvtkCommon\
           -lvtksys -lQVTK -lvtkViews -lvtkWidgets\
           -lvtkInfovis -lvtkRendering -lvtkGraphics\
           -lvtkImaging -lvtkIO -lvtkFiltering\
           -lvtkDICOMParser -lvtkHybrid

INCLUDEPATH += /usr/include/vtk-5.8
