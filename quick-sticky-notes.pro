QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = quick-sticky-notes
TEMPLATE = app

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

CONFIG += c++11

INCLUDEPATH += src src/core src/gui src/utils

SOURCES += \
    src/main.cpp \
    src/gui/NoteWidget.cpp

HEADERS += \
    src/gui/NoteWidget.h

FORMS += \
    src/gui/NoteWidget.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
        icons/icons.qrc
