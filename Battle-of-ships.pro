QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clickablelabel.cpp \
    clickablelabel2.cpp \
    gamepage.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    savegamedata.cpp \
    selectmap.cpp

HEADERS += \
    clickablelabel.h \
    clickablelabel2.h \
    gamepage.h \
    loginpage.h \
    mainwindow.h \
    savegamedata.h \
    selectmap.h

FORMS += \
    gamepage.ui \
    loginpage.ui \
    mainwindow.ui \
    selectmap.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Image.qrc

