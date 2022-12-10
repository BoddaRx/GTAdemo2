QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    display.cpp \
    enemy.cpp \
    gameover.cpp \
    gate.cpp \
    graph.cpp \
    health.cpp \
    login.cpp \
    main.cpp \
    pellet.cpp \
    player.cpp \
    win.cpp

HEADERS += \
    bullet.h \
    car.h \
    display.h \
    enemy.h \
    gameover.h \
    gate.h \
    graph.h \
    health.h \
    login.h \
    main.h \
    pellet.h \
    player.h \
    timer.h \
    win.h

FORMS += \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
