#include "temperaturegaugedefaultstyle_p.h"

QT_BEGIN_NAMESPACE

TemperatureGaugeDefaultStyle::TemperatureGaugeDefaultStyle(QObject *parent) :
    QObject(parent)
{
}

QColor TemperatureGaugeDefaultStyle::backgroundColor() const
{
    return QColor::fromRgba(0xFF0000FF);
}

QT_END_NAMESPACE
