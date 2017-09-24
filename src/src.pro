TEMPLATE = subdirs

SUBDIRS += \
    imports \
    temperaturegaugetemplate

imports.depends = temperaturegaugetemplate
