#include "temperaturegauge_p.h"
#include "temperaturegauge_p_p.h"

QT_BEGIN_NAMESPACE

namespace
{
    const double CelsiusToKelvin = 274.15;
}

TemperatureGaugePrivate::TemperatureGaugePrivate()
    : displayUnit(TemperatureGauge::Celsius),
      value(0),
      minValue(-50),
      maxValue(50)
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
    emit displayValueChanged();
    emit displayMinValueChanged();
    emit displayMaxValueChanged();
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
    emit displayValueChanged();
}

int TemperatureGauge::minValue() const
{
    Q_D(const TemperatureGauge);
    return d->minValue;
}

void TemperatureGauge::setMinValue(int minValue)
{
    Q_D(TemperatureGauge);
    if (d->minValue == minValue) {
        return;
    }
    d->minValue = minValue;
    emit minValueChanged();
    emit displayMinValueChanged();
}

int TemperatureGauge::maxValue() const
{
    Q_D(const TemperatureGauge);
    return d->maxValue;
}

void TemperatureGauge::setMaxValue(int maxValue)
{
    Q_D(TemperatureGauge);
    if (d->maxValue == maxValue) {
        return;
    }
    d->maxValue = maxValue;
    emit maxValueChanged();
    emit displayMaxValueChanged();
}

double TemperatureGauge::displayValue() const
{
    Q_D(const TemperatureGauge);
    return convertToDisplay(d->value);
}

double TemperatureGauge::displayMinValue() const
{
    Q_D(const TemperatureGauge);
    return convertToDisplay(d->minValue);
}

double TemperatureGauge::displayMaxValue() const
{
    Q_D(const TemperatureGauge);
    return convertToDisplay(d->maxValue);
}

double TemperatureGauge::convertToDisplay(int v) const
{
    Q_D(const TemperatureGauge);
    if (d->displayUnit == TemperatureGauge::Celsius) {
        return v;
    } else {
        return v + CelsiusToKelvin;
    }
}

QT_END_NAMESPACE
