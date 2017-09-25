#ifndef TEMPERATUREGAUGEDEFAULTSTYLE_P_H
#define TEMPERATUREGAUGEDEFAULTSTYLE_P_H

#include <QtCore/qobject.h>
#include <QtGui/qcolor.h>

QT_BEGIN_NAMESPACE

class TemperatureGaugeDefaultStyle : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ backgroundColor CONSTANT FINAL)

public:
    explicit TemperatureGaugeDefaultStyle(QObject *parent = nullptr);

    QColor backgroundColor() const;
};

QT_END_NAMESPACE

#endif // TEMPERATUREGAUGEDEFAULTSTYLE_P_H
