TEMPLATE = lib
TARGET = temperaturegaugetemplate
QT += qml quick
QT_PRIVATE += qml-private quick-private quicktemplates2-private quickcontrols2-private
CONFIG += plugin c++11
IMPORT_VERSION = 1.0

TARGET = $$qtLibraryTarget($$TARGET)
uri = TemperatureGauge.Template

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII

# Input
SOURCES += \
    temperaturegaugetemplate_plugin.cpp \
    temperaturegauge_p.cpp

HEADERS += \
    temperaturegaugetemplate_plugin.h \
    temperaturegauge_p.h \
    temperaturegauge_p_p.h

DISTFILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
