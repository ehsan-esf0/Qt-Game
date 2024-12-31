QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Soursces/bomb.cpp \
    Soursces/bombdisabler.cpp \
    Soursces/bullet.cpp \
    Soursces/clickablelabel.cpp \
    Soursces/clickablelabel2.cpp \
    Soursces/enemy.cpp \
    Soursces/fighter111.cpp \
    Soursces/fighter298.cpp \
    Soursces/gamepage.cpp \
    Soursces/ice_bomb.cpp \
    Soursces/loginpage.cpp \
    Soursces/main.cpp \
    Soursces/mainwindow.cpp \
    Soursces/savegamedata.cpp \
    Soursces/selectmap.cpp \
    Soursces/towerdestroyer.cpp \
    Soursces/towerdisabler.cpp \
    Soursces/turret_q8.cpp \
    Soursces/turret_q8f.cpp \
    Soursces/turret_q8r.cpp

HEADERS += \
    Header/bomb.h \
    Header/bombdisabler.h \
    Header/bullet.h \
    Header/clickablelabel.h \
    Header/clickablelabel2.h \
    Header/enemy.h \
    Header/fighter111.h \
    Header/fighter298.h \
    Header/gamepage.h \
    Header/ice_bomb.h \
    Header/loginpage.h \
    Header/mainwindow.h \
    Header/savegamedata.h \
    Header/selectmap.h \
    Header/towerdestroyer.h \
    Header/towerdisabler.h \
    Header/turret_q8.h \
    Header/turret_q8f.h \
    Header/turret_q8r.h

FORMS += \
    Ui\gamepage.ui \
    Ui\loginpage.ui \
    Ui\mainwindow.ui \
    Ui\selectmap.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Image.qrc

STATECHARTS += \
    chartGame.scxml

