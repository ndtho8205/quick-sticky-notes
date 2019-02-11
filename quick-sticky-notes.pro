QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = quick-sticky-notes
TEMPLATE = app

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

CONFIG += c++11

INCLUDEPATH += \
    src \
    src/data src/data/local src/data/model src/data/remote \
    src/controllers \
    src/gui

SOURCES += \
    src/main.cpp \
    src/gui/NoteWidget.cpp \
    src/data/model/Note.cpp \
    src/data/model/Todo.cpp \
    src/data/local/LocalDataManager.cpp \
    src/data/remote/RemoteDataManager.cpp \
    src/controllers/MainController.cpp

HEADERS += \
    src/gui/NoteWidget.h \
    src/data/model/Note.h \
    src/data/model/Todo.h \
    src/data/local/LocalDataManager.h \
    src/data/remote/RemoteDataManager.h \
    src/controllers/MainController.h

FORMS += \
    src/gui/NoteWidget.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
        icons/icons.qrc
