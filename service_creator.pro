QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cc \
    mainwindow.cc \
    optionitemwidget.cc \
    questioneditwindow.cc \
    questionitemwidget.cc \
    servicewidget.cc

HEADERS += \
    mainwindow.h \
    optionitemwidget.h \
    questioneditwindow.h \
    questionitemwidget.h \
    servicewidget.h

FORMS += \
    mainwindow.ui \
    optionitemwidget.ui \
    questioneditwindow.ui \
    questionitemwidget.ui \
    servicewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../appointy/build/appointy/Debug/bin/release/ -lappointy
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../appointy/build/appointy/Debug/bin/debug/ -lappointy
else:unix: LIBS += -L$$PWD/../appointy/build/appointy/Debug/bin/ -lappointy

INCLUDEPATH += $$PWD/../appointy/src
INCLUDEPATH += $$PWD/../appointy/src/util
INCLUDEPATH += $$PWD/../appointy/src/appointment
INCLUDEPATH += $$PWD/../appointy/src/service
INCLUDEPATH += $$PWD/../appointy/ext/json/include
INCLUDEPATH += $$PWD/../appointy/ext/json/include/nlohmann
DEPENDPATH += $$PWD/../appointy/src

unix|win32: LIBS += -lmongocxx
unix|win32: LIBS += -lmongoc-1.0
unix|win32: LIBS += -lbsoncxx
unix|win32: LIBS += -lbson-1.0