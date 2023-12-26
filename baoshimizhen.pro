QT += core gui sql
QT  +=  multimedia
QT  +=  sql
QT += sql core
QT       += core gui
QT       += core gui multimedia widgets
QT       += axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = baoshimizhen
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

CONFIG += c++11

SOURCES += \
    CGammaRamp.cpp \
    PixmapSlider.cpp \
    client.cpp \
    database.cpp \
    loginpage.cpp \
    main.cpp \
    hoverbutton.cpp \
    ranklistpage.cpp \
    registerpage.cpp \
    selectlevel.cpp \
    settingpage.cpp \
    startpage.cpp \
    gamewidget.cpp \
    myprobar.cpp \
    gem.cpp

HEADERS += \
    CGammaRamp.h \
    PixmapSlider.h \
    client.h \
    database.h \
    hoverbutton.h \
    loginpage.h \
    ranklistpage.h \
    registerpage.h \
    selectlevel.h \
    settingpage.h \
    startpage.h \
    gamewidget.h \
    myprobar.h \
    gem.h \
    user.h

FORMS += \
    loginpage.ui \
    ranklistpage.ui \
    registerpage.ui \
    selectlevel.ui \
    settingpage.ui \
    startpage.ui \
    gamewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    gdi32.dll


LIBS += -lole32

