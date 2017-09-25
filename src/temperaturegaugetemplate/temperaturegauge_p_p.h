#ifndef TEMPERATUREGAUGE_P_P_H
#define TEMPERATUREGAUGE_P_P_H

#include <QtQuickTemplates2/private/qquickcontrol_p_p.h>
#include "temperaturegauge_p.h"

QT_BEGIN_NAMESPACE

class Q_QUICKTEMPLATES2_PRIVATE_EXPORT TemperatureGaugePrivate : public QQuickControlPrivate
{
public:
    TemperatureGaugePrivate();

    TemperatureGauge::Unit displayUnit;
    int value;
    int minValue;
    int maxValue;
};

QT_END_NAMESPACE

#endif // TEMPERATUREGAUGE_P_P_H
