#include "temperaturegaugeplugin.h"
#include <QtCore/private/qfileselector_p.h>
#include <QtQuickControls2/private/qquickstyleselector_p.h>
#include <QtQuickControls2/qquickstyle.h>
#include <QtQuickControls2/private/qquickstyle_p.h>
#include "temperaturegaugedefaultstyle_p.h"

static QObject *styleSingleton(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new TemperatureGaugeDefaultStyle;
}

TemperatureGaugePlugin::TemperatureGaugePlugin(QObject *parent)
    : QQuickStylePlugin(parent)
{
}

void TemperatureGaugePlugin::registerTypes(const char *uri)
{
    // Using selector for TemperatureGauage.qml for styling support
    QQuickStylePrivate::init(typeUrl());
    const QString style = QQuickStyle::name();
    if (!style.isEmpty()) {
        QFileSelectorPrivate::addStatics(QStringList() << style.toLower());
    }

    QQuickStyleSelector selector;
    selector.setBaseUrl(typeUrl());

    qmlRegisterModule(uri, 1, 0);
    qmlRegisterType(selector.select(QStringLiteral("TemperatureGauge.qml")), uri, 1, 0, "TemperatureGauge");
}

void TemperatureGaugePlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    // Registering TemperatureGaugeDefaultStyle into TemperatureGauge.Alternative.impl module
    QQuickStylePlugin::initializeEngine(engine, uri);
    const QByteArray import = QByteArray(uri) + ".impl";
    qmlRegisterModule(import, 1, 0);
    qmlRegisterSingletonType<TemperatureGaugeDefaultStyle>(import, 1, 0, "TemperatureGaugeDefaultStyle", styleSingleton);
}

QString TemperatureGaugePlugin::name() const
{
    return QStringLiteral("temperaturegaugedefaultstyle");
}
