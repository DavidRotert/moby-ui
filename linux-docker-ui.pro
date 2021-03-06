QT+= core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/containerlistitem.cpp \
    src/containerslistpage.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/containerlistitem.h \
    src/containerslistpage.h \
    src/mainwindow.h

FORMS += \
    ui/containerlistitem.ui \
    ui/containerslistpage.ui \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/fonts.qrc \
    res/icons.qrc
