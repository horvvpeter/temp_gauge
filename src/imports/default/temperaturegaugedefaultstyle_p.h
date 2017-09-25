#ifndef TEMPERATUREGAUGEDEFAULTSTYLE_P_H
#define TEMPERATUREGAUGEDEFAULTSTYLE_P_H

#include <QtCore/qobject.h>
#include <QtGui/qcolor.h>

QT_BEGIN_NAMESPACE

class TemperatureGaugeDefaultStyle : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ backgroundColor CONSTANT FINAL)
    Q_PROPERTY(QColor valueColor READ valueColor CONSTANT FINAL)
    Q_PROPERTY(QColor tickColor READ tickColor CONSTANT FINAL)

public:
    explicit TemperatureGaugeDefaultStyle(QObject *parent = nullptr);

    QColor backgroundColor() const;
    QColor valueColor() const;
    QColor tickColor() const;
};

QT_END_NAMESPACE

#endif // TEMPERATUREGAUGEDEFAULTSTYLE_P_H
