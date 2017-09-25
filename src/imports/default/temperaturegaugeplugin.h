#ifndef TEMPERATUREGAUGEPLUGIN_H
#define TEMPERATUREGAUGEPLUGIN_H

#include <QtQuickControls2/private/qquickstyleplugin_p.h>
#include <QQmlEngine>

class TemperatureGaugePlugin: public QQuickStylePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    TemperatureGaugePlugin(QObject *parent = nullptr);
    void registerTypes(const char *uri) override;
    void initializeEngine(QQmlEngine *engine, const char *uri) override;
    QString name() const override;
};

#endif // TEMPERATUREGAUGEPLUGIN_H
