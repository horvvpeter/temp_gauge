TEMPLATE = app
TARGET = tst_default
CONFIG += qmltestcase

DEFINES += TST_CONTROLS_DATA=\\\"$$PWD/../data\\\"

SOURCES += \
    $$PWD/tst_default.cpp

OTHER_FILES += \
    $$PWD/../data/*.qml

TESTDATA += \
    $$PWD/../data/tst_*
