#ifndef TEMPERATUREGAUGE_H
#define TEMPERATUREGAUGE_H

#include <QtQuickTemplates2/private/qquickcontrol_p.h>

class TemperatureGaugePrivate;
class Q_QUICKTEMPLATES2_PRIVATE_EXPORT TemperatureGauge : public QQuickControl
{
    Q_OBJECT

    Q_PROPERTY(Unit displayUnit READ displayUnit WRITE setDisplayUnit NOTIFY displayUnitChanged)
    Q_PROPERTY(double value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int minValue READ minValue WRITE setMinValue NOTIFY minValueChanged)
    Q_PROPERTY(int maxValue READ maxValue WRITE setMaxValue NOTIFY maxValueChanged)
    Q_PROPERTY(double displayValue READ displayValue NOTIFY displayValueChanged)
    Q_PROPERTY(double displayMinValue READ displayMinValue NOTIFY displayMinValueChanged)
    Q_PROPERTY(double displayMaxValue READ displayMaxValue NOTIFY displayMaxValueChanged)

public:
    explicit TemperatureGauge(QQuickItem *parent = nullptr);
    ~TemperatureGauge();

    enum Unit {
        Celsius,
        Kelvin
    };
    Q_ENUM(Unit)

    Unit displayUnit() const;
    void setDisplayUnit(Unit unitType);

    double value() const;
    void setValue(double);

    int minValue() const;
    void setMinValue(int);

    int maxValue() const;
    void setMaxValue(int);

    double displayValue() const;
    double displayMinValue() const;
    double displayMaxValue() const;

    double convertToDisplay(double v) const;

public Q_SLOTS:

Q_SIGNALS:
    void displayUnitChanged();
    void valueChanged();
    void minValueChanged();
    void maxValueChanged();
    void displayValueChanged();
    void displayMinValueChanged();
    void displayMaxValueChanged();

protected:
    TemperatureGauge(TemperatureGaugePrivate &dd, QQuickItem *parent);

private:
    Q_DISABLE_COPY(TemperatureGauge)
    Q_DECLARE_PRIVATE(TemperatureGauge)
};

QML_DECLARE_TYPE(TemperatureGauge)

#endif // TEMPERATUREGAUGE_H
