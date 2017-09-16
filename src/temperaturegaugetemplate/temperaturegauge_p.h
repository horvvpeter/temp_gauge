#ifndef TEMPERATUREGAUGE_H
#define TEMPERATUREGAUGE_H

#include <QtQuickTemplates2/private/qquickcontrol_p.h>

QT_BEGIN_NAMESPACE

class TemperatureGaugePrivate;
class Q_QUICKTEMPLATES2_PRIVATE_EXPORT TemperatureGauge : public QQuickControl
{
    Q_OBJECT

    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit TemperatureGauge(QQuickItem *parent = nullptr);
    ~TemperatureGauge();

    int value() const;
    void setValue(int);

public Q_SLOTS:

Q_SIGNALS:
    void valueChanged();

protected:
    TemperatureGauge(TemperatureGaugePrivate &dd, QQuickItem *parent);

private:
    Q_DISABLE_COPY(TemperatureGauge)
    Q_DECLARE_PRIVATE(TemperatureGauge)
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(TemperatureGauge)

#endif // TEMPERATUREGAUGE_H
