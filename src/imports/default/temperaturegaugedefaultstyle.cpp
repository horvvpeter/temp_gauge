#include "temperaturegaugedefaultstyle_p.h"

TemperatureGaugeDefaultStyle::TemperatureGaugeDefaultStyle(QObject *parent) :
    QObject(parent)
{
}

QColor TemperatureGaugeDefaultStyle::backgroundColor() const
{
    return QColor::fromRgba(0xFF727984);
}

QColor TemperatureGaugeDefaultStyle::valueColor() const
{
    return QColor::fromRgba(0xFFFF0000);
}

QColor TemperatureGaugeDefaultStyle::tickColor() const
{
    return QColor::fromRgba(0xFF000000);
}
