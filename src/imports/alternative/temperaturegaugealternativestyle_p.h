#ifndef TEMPERATUREGAUGEALTERNATIVESTYLE_P_H
#define TEMPERATUREGAUGEALTERNATIVESTYLE_P_H

#include <QtCore/qobject.h>
#include <QtGui/qcolor.h>

QT_BEGIN_NAMESPACE

class TemperatureGaugeAlternativeStyle : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ backgroundColor CONSTANT FINAL)

public:
    explicit TemperatureGaugeAlternativeStyle(QObject *parent = nullptr);

    QColor backgroundColor() const;
};

QT_END_NAMESPACE

#endif // TEMPERATUREGAUGEALTERNATIVESTYLE_P_H
