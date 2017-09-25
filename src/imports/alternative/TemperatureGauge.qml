import QtQuick 2.0
import TemperatureGauge.Alternative 1.0
import TemperatureGauge.Alternative.impl 1.0
import TemperatureGauge.Template 1.0 as T

T.TemperatureGauge {
    id: control

    background: Rectangle {
        color: TemperatureGaugeAlternativeStyle.backgroundColor
    }
}
