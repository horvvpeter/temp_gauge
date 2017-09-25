TEMPLATE = app
TARGET = tst_alternative
CONFIG += qmltestcase
QT += quickcontrols2

DEFINES += TST_CONTROLS_DATA=\\\"$$PWD/../data\\\"

SOURCES += \
    $$PWD/tst_alternative.cpp

OTHER_FILES += \
    $$PWD/../data/*.qml

TESTDATA += \
    $$PWD/../data/tst_*
