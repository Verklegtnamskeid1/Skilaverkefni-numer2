QT	 += core

QT	 -= gui

TARGET = skilaverkefni1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sk1data.cpp \
    consoleui.cpp

HEADERS += \
    main.h \
    sk1data.h \
    consoleui.h

OTHER_FILES += \
    sk1data.txt

