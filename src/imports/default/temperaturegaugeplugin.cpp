#include "temperaturegaugeplugin.h"
#include "temperaturegaugedefaultstyle_p.h"

QT_BEGIN_NAMESPACE

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
    qmlRegisterModule(uri, 1, 0);
    qmlRegisterType(typeUrl(QStringLiteral("TemperatureGauge.qml")), uri, 1, 0, "TemperatureGauge");
}

void TemperatureGaugePlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQuickStylePlugin::initializeEngine(engine, uri);
    const QByteArray import = QByteArray(uri) + ".impl";
    qmlRegisterModule(import, 1, 0);
    qmlRegisterSingletonType<TemperatureGaugeDefaultStyle>(import, 1, 0, "TemperatureGaugeDefaultStyle", styleSingleton);
}

QString TemperatureGaugePlugin::name() const
{
    return QStringLiteral("temperaturegaugedefaultstyle");
}

QT_END_NAMESPACE
