QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cc \
    main_window.cc \
    option_edit_window.cc \
    option_item_widget.cc \
    question_edit_window.cc \
    question_item_widget.cc \
    service_edit_window.cc \
    service_item_widget.cc \
    util.cc

HEADERS += \
    main_window.h \
    option_edit_window.h \
    option_item_widget.h \
    question_edit_window.h \
    question_item_widget.h \
    service_edit_window.h \
    service_item_widget.h \
    util.h

FORMS += \
    main_window.ui \
    option_edit_window.ui \
    option_item_widget.ui \
    question_edit_window.ui \
    question_item_widget.ui \
    service_edit_window.ui \
    service_item_widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../appointy/build/appointy_base/Debug/bin/ -lappointy_base
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../appointy/build/appointy_base/Debug/bin/ -lappointy_base
else:unix: LIBS += -L$$PWD/../appointy/build/appointy_base/Debug/bin/ -lappointy_base

INCLUDEPATH += $$PWD/../appointy/appointy_base/include/util
INCLUDEPATH += $$PWD/../appointy/appointy_base/include/appointment
INCLUDEPATH += $$PWD/../appointy/appointy_base/include/service
INCLUDEPATH += $$PWD/../appointy/ext/json/include
INCLUDEPATH += $$PWD/../appointy/ext/json/include/nlohmann
DEPENDPATH += $$PWD/../appointy/appointy_base

