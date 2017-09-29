TEMPLATE=aux

temperaturegauge_docs.commands = export QT_INSTALL_DOCS=$$[QT_INSTALL_DOCS];
temperaturegauge_docs.commands += qdoc $$_PRO_FILE_PWD_/temperaturegauge.qdocconf

QMAKE_EXTRA_TARGETS += temperaturegauge_docs
