#include "temperaturegaugealternativeplugin.h"
#include "temperaturegaugealternativestyle_p.h"

static QObject *styleSingleton(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new TemperatureGaugeAlternativeStyle;
}

TemperatureGaugeAlternativePlugin::TemperatureGaugeAlternativePlugin(QObject *parent)
    : QQuickStylePlugin(parent)
{
}

void TemperatureGaugeAlternativePlugin::registerTypes(const char *uri)
{
    qmlRegisterModule(uri, 1, 0);
}

void TemperatureGaugeAlternativePlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQuickStylePlugin::initializeEngine(engine, uri);
    const QByteArray import = QByteArray(uri) + ".impl";
    qmlRegisterModule(import, 1, 0);
    qmlRegisterSingletonType<TemperatureGaugeAlternativeStyle>(import, 1, 0, "TemperatureGaugeAlternativeStyle", styleSingleton);
}

QString TemperatureGaugeAlternativePlugin::name() const
{
    return QStringLiteral("temperaturegaugealternativestyle");
}
