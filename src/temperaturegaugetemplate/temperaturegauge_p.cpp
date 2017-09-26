#include "temperaturegauge_p.h"
#include "temperaturegauge_p_p.h"

/*!
    \qmltype TemperatureGauge
    \inherits Control
    \brief A simple gauge for showing temperature.

    TemperatureGauge is a simple thermometer like gauge which displays temperature.
    The input temperature is in the units of Celsius, however there is a possibility to display
    the temperature using units of Kelvin.

    It comes with two styles: default and alternative.
    \image tempgauge_default.png "Default style"
    \caption Default style
    \image tempgauge_alternative.png "Alternative style"
    \caption Alternative style

    \l {example} {See an example of how to use TemperatureGauge}
*/

/*!
    \qmlsignal TemperatureGauge::displayUnitChanged()

    This signal is emitted when displayUnit was changed.
*/

/*!
    \qmlsignal TemperatureGauge::valueChanged()

    This signal is emitted when \l{value} was changed.
*/

/*!
    \qmlsignal TemperatureGauge::minValueChanged()

    This signal is emitted when minValue was changed.
*/

/*!
    \qmlsignal TemperatureGauge::maxValueChanged()

    This signal is emitted when maxValue was changed.
*/

/*!
    \qmlsignal TemperatureGauge::displayValueChanged()

    This signal is emitted when the value or displayUnit was changed.
*/

/*!
    \qmlsignal TemperatureGauge::displayMinValueChanged()

    This signal is emitted when minValue or displayUnit was changed.
*/

/*!
    \qmlsignal TemperatureGauge::displayMaxValueChanged()

    This signal is emitted when maxValue or displayUnit was changed.
*/

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

/*!
    \qmlproperty enumeration TemperatureGauge::displayUnit

    This property holds the temperature unit to display.

    \value TemperatureGauge.Celsius Display temperature in the units of Celsius.
    \value TemperatureGauge.Kelvin  Display temperature in the units of Kelvin.
*/
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

/*!
    \qmlproperty double TemperatureGauge::value

    This property holds the temperature value in the units of Celsius.
    \sa displayValue
*/
double TemperatureGauge::value() const
{
    Q_D(const TemperatureGauge);
    return d->value;
}

void TemperatureGauge::setValue(double value)
{
    Q_D(TemperatureGauge);
    if (qFuzzyCompare(d->value, value)) {
        return;
    }
    d->value = value;
    emit valueChanged();
    emit displayValueChanged();
}

/*!
    \qmlproperty int TemperatureGauge::minValue

    This property holds the minimum temperature which should be displayed in the units of Celsius.
    \sa displayMinValue
*/
int TemperatureGauge::minValue() const
{
    Q_D(const TemperatureGauge);
    return d->minValue;
}

void TemperatureGauge::setMinValue(int minValue)
{
    Q_D(TemperatureGauge);
    if (d->minValue == minValue || d->maxValue <= minValue) {
        return;
    }
    d->minValue = minValue;
    emit minValueChanged();
    emit displayMinValueChanged();
}

/*!
    \qmlproperty int TemperatureGauge::maxValue

    This property holds the maximum temperature which should be displayed in the units of Celsius.
    \sa displayMaxValue
*/
int TemperatureGauge::maxValue() const
{
    Q_D(const TemperatureGauge);
    return d->maxValue;
}

void TemperatureGauge::setMaxValue(int maxValue)
{
    Q_D(TemperatureGauge);
    if (d->maxValue == maxValue || d->minValue >= maxValue) {
        return;
    }
    d->maxValue = maxValue;
    emit maxValueChanged();
    emit displayMaxValueChanged();
}

/*!
    \qmlproperty double TemperatureGauge::displayValue
    \readonly

    This property holds the temperature value in the selected display unit.
    \sa value, displayUnit
*/
double TemperatureGauge::displayValue() const
{
    Q_D(const TemperatureGauge);
    return convertToDisplay(d->value);
}

/*!
    \qmlproperty double TemperatureGauge::displayMinValue
    \readonly

    This property holds the minimum temperature which should be displayed in the selected display unit
    \sa minValue, displayUnit
*/
double TemperatureGauge::displayMinValue() const
{
    Q_D(const TemperatureGauge);
    return convertToDisplay(d->minValue);
}

/*!
    \qmlproperty double TemperatureGauge::displayMaxValue
    \readonly

    This property holds the maximum temperature which should be displayed in the selected display unit
    \sa maxValue, displayUnit
*/
double TemperatureGauge::displayMaxValue() const
{
    Q_D(const TemperatureGauge);
    return convertToDisplay(d->maxValue);
}

double TemperatureGauge::convertToDisplay(double v) const
{
    Q_D(const TemperatureGauge);
    if (d->displayUnit == TemperatureGauge::Celsius) {
        return v;
    } else {
        return v + CelsiusToKelvin;
    }
}
