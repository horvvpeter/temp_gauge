TEMPLATE = lib
TARGET = temperaturegaugealternativeplugin
QT += qml quick
QT_PRIVATE += core-private gui-private qml-private quick-private quicktemplates2-private quickcontrols2-private
CONFIG += plugin c++11
IMPORT_VERSION = 1.0

TARGET = $$qtLibraryTarget($$TARGET)
uri = TemperatureGauge.Alternative

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII

HEADERS += \
    $$PWD/temperaturegaugealternativestyle_p.h \
    temperaturegaugealternativeplugin.h

SOURCES += \
    $$PWD/temperaturegaugealternativestyle.cpp \
    $$PWD/temperaturegaugealternativeplugin.cpp

QML_FILES = \
    $$PWD/TemperatureGauge.qml \

OTHER_FILES += \
    qmldir \
    $$QML_FILES

qmldir.files = qmldir $$QML_FILES

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
