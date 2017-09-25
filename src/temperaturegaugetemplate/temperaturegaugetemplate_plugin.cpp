#include "temperaturegaugetemplate_plugin.h"
#include "temperaturegauge_p.h"

#include <qqml.h>

void TemperatureGaugeTemplatePlugin::registerTypes(const char *uri)
{
    // @uri TemperatureGauge
    qmlRegisterType<TemperatureGauge>(uri, 1, 0, "TemperatureGauge");
}

