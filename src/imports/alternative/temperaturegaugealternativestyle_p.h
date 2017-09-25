#ifndef TEMPERATUREGAUGEALTERNATIVESTYLE_P_H
#define TEMPERATUREGAUGEALTERNATIVESTYLE_P_H

#include <QtCore/qobject.h>
#include <QtGui/qcolor.h>

class TemperatureGaugeAlternativeStyle : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColorStart READ backgroundColorStart CONSTANT FINAL)
    Q_PROPERTY(QColor backgroundColorEnd READ backgroundColorEnd CONSTANT FINAL)
    Q_PROPERTY(QColor positiveColorStart READ positiveColorStart CONSTANT FINAL)
    Q_PROPERTY(QColor positiveColorEnd READ positiveColorEnd CONSTANT FINAL)
    Q_PROPERTY(QColor negativeColorStart READ negativeColorStart CONSTANT FINAL)
    Q_PROPERTY(QColor negativeColorEnd READ negativeColorEnd CONSTANT FINAL)
    Q_PROPERTY(QColor tickColor READ tickColor CONSTANT FINAL)

public:
    explicit TemperatureGaugeAlternativeStyle(QObject *parent = nullptr);

    QColor backgroundColorStart() const;
    QColor backgroundColorEnd() const;
    QColor positiveColorStart() const;
    QColor positiveColorEnd() const;
    QColor negativeColorStart() const;
    QColor negativeColorEnd() const;
    QColor tickColor() const;
};

#endif // TEMPERATUREGAUGEALTERNATIVESTYLE_P_H
