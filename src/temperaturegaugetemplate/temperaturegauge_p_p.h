#ifndef TEMPERATUREGAUGE_P_P_H
#define TEMPERATUREGAUGE_P_P_H

#include <QtQuickTemplates2/private/qquickcontrol_p_p.h>
#include "temperaturegauge_p.h"

class Q_QUICKTEMPLATES2_PRIVATE_EXPORT TemperatureGaugePrivate : public QQuickControlPrivate
{
public:
    TemperatureGaugePrivate();

    TemperatureGauge::Unit displayUnit;
    double value;
    int minValue;
    int maxValue;
};

#endif // TEMPERATUREGAUGE_P_P_H
