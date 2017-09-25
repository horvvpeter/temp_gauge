#include "temperaturegaugealternativestyle_p.h"

QT_BEGIN_NAMESPACE

TemperatureGaugeAlternativeStyle::TemperatureGaugeAlternativeStyle(QObject *parent) :
    QObject(parent)
{
}

QColor TemperatureGaugeAlternativeStyle::backgroundColorStart() const
{
    return QColor::fromRgb(0x364254);
}

QColor TemperatureGaugeAlternativeStyle::backgroundColorEnd() const
{
    return QColor::fromRgb(0x1f2226);
}

QColor TemperatureGaugeAlternativeStyle::positiveColorStart() const
{
    return QColor::fromRgb(0xa22c1e);
}

QColor TemperatureGaugeAlternativeStyle::positiveColorEnd() const
{
    return QColor::fromRgb(0xff230a);
}

QColor TemperatureGaugeAlternativeStyle::negativeColorStart() const
{
    return QColor::fromRgb(0x0f454f);
}

QColor TemperatureGaugeAlternativeStyle::negativeColorEnd() const
{
    return QColor::fromRgb(0x1f8ea3);
}

QColor TemperatureGaugeAlternativeStyle::tickColor() const
{
    return QColor::fromRgb(0x262424);
}

QT_END_NAMESPACE
