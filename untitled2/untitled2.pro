TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    base.cpp \
    finder_down.cpp \
    finder_right.cpp \
    finder_up.cpp \
    input.cpp \
    output.cpp \
    step.cpp

HEADERS += \
    input.h \
    output.h \
    finder_up.h \
    finder_down.h \
    finder_right.h \
    step.h \
    base.h
