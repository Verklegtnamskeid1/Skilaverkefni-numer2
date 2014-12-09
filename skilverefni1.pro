QT	 += core sql
#compæla með c++11 stuðning
CONFIG += c++11

QT	 -= gui

TARGET = skilaverkefni1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    consoleui.cpp \
    sqlite.cpp \
    sk2data.cpp

HEADERS += \
    main.h \
    consoleui.h \
    sqlite.h \
    sk2data.h

OTHER_FILES += \
    Skil2.sqlite \
    backup.txt

