QT	 += core sql
#compæla með c++11 stuðning
CONFIG += c++11

QT	 -= gui

TARGET = skilaverkefni1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sk1data.cpp \
    consoleui.cpp \
    cvs.cpp \
    sqlite.cpp

HEADERS += \
    main.h \
    sk1data.h \
    consoleui.h \
    sqlite.h

OTHER_FILES += \
    Skil2.sqlite \
    backup.txt

