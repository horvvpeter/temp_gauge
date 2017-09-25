#include "temperaturegauge_p.h"
#include "temperaturegauge_p_p.h"

TemperatureGaugePrivate::TemperatureGaugePrivate()
    : displayUnit(TemperatureGauge::Celsius),
      value(0)
{

}

TemperatureGauge::TemperatureGauge(QQuickItem *parent)
    : QQuickControl(*(new TemperatureGaugePrivate), parent)
{
}

TemperatureGauge::~TemperatureGauge()
{
}

TemperatureGauge::TemperatureGauge(TemperatureGaugePrivate &dd, QQuickItem *parent)
    : QQuickControl(dd, parent)
{
}

TemperatureGauge::Unit TemperatureGauge::displayUnit() const
{
    Q_D(const TemperatureGauge);
    return d->displayUnit;
}

void TemperatureGauge::setDisplayUnit(TemperatureGauge::Unit unitType)
{
    Q_D(TemperatureGauge);
    if (d->displayUnit == unitType) {
        return;
    }
    d->displayUnit = unitType;
    emit displayUnitChanged();
}

int TemperatureGauge::value() const
{
    Q_D(const TemperatureGauge);
    return d->value;
}

void TemperatureGauge::setValue(int value)
{
    Q_D(TemperatureGauge);
    if (d->value == value) {
        return;
    }
    d->value = value;
    emit valueChanged();
}
