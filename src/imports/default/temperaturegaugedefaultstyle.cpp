#include "temperaturegaugedefaultstyle_p.h"

QT_BEGIN_NAMESPACE

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

QT_END_NAMESPACE
