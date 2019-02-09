#-------------------------------------------------
#
# Project created by QtCreator 2019-02-09T16:22:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WidgetsTests
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

#INCLUDEPATH += D:\Rotkaeppchen\workspace_C++\FileAssociationHandler\FileAssociationHandler\FileAssociationHandler
#INCLUDEPATH += D:\Rotkaeppchen\workspace_C++\FileAssociationHandler\FileAssociationHandler\Debug
#INCLUDEPATH += "$$PWD/FileAssociationHandler"
#LIBS += "$$PWD/FileAssociationHandler.dll"

#INCLUDEPATH += "C:\Windows\System32"
#INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\10\Lib\10.0.17763.0\um\x64"

win32:LIBS += -lkernel32
win32:LIBS += -luser32
win32:LIBS += -lgdi32
win32:LIBS += -lwinspool
win32:LIBS += -lcomdlg32
win32:LIBS += -ladvapi32
win32:LIBS += -lshell32
win32:LIBS += -lole32
win32:LIBS += -loleaut32
win32:LIBS += -luuid
win32:LIBS += -lodbc32
win32:LIBS += -lodbccp32

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h \
        registry.h \
        registry2.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/./ -lFileAssociationHandler

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
