SOURCES += \
    module0.cpp \
    gui/src/qtmainwindow.cpp \
    gui/src/qhextable.cpp \
    gui/src/qasciitable.cpp \
    gui/src/qaddrhorizontal.cpp \
    gui/src/qaddrhorizontal2.cpp \
    gui/src/qaddrvertical.cpp \
    gui/src/menupanel.cpp \
    bus/src/filemenager.cpp \
    bus/src/file.cpp
QT += widgets

HEADERS += \
    gui/src/qtmainwindow.h \
    gui/src/qhextable.h \
    gui/src/qasciitable.h \
    bus/inc/configurations.h \
    bus/inc/globally.h \
    gui/src/qaddrhorizontal.h \
    gui/src/qaddrhorizontal2.h \
    bus/inc/types.h \
    gui/src/qaddrvertical.h \
    gui/src/menupanel.h \
    bus/src/file.h

RESOURCES += \
    res.qrc

OTHER_FILES +=

Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui
