QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MotionPlatform.cpp \
    main.cpp \
    ui_mainwindow.cpp \
    XYPlatform.cpp

HEADERS += \
    MotionPlatform.h \
    ui_mainwindow.h \
    XYPlatform.h

FORMS += \
    ui_mainwindow.ui


INCLUDEPATH += $$PWD/NanoDrive2.8.12/04_SDK/include
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/NanoDrive2.8.12/04_SDK/lib64/ -lNTControl

INCLUDEPATH += $$PWD/NanoDrive2.8.12/04_SDK/lib64
DEPENDPATH += $$PWD/NanoDrive2.8.12/04_SDK/lib64
