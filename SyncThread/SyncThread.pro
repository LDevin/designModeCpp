TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    event.cpp \
    wmutex.cpp \
    wcritical.cpp \
    wsemphore.cpp

HEADERS += \
    event.h \
    wmutex.h \
    wcritical.h \
    wsemaphore.h
