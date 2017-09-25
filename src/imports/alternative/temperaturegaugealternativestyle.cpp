#include "temperaturegaugealternativestyle_p.h"

QT_BEGIN_NAMESPACE

TemperatureGaugeAlternativeStyle::TemperatureGaugeAlternativeStyle(QObject *parent) :
    QObject(parent)
{
}

QColor TemperatureGaugeAlternativeStyle::backgroundColor() const
{
    return QColor::fromRgba(0xFF00FFFF);
}

QT_END_NAMESPACE
