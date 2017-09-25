import QtQuick 2.0
import TemperatureGauge.impl 1.0
import TemperatureGauge.Template 1.0 as T

T.TemperatureGauge {
    id: control

    background: Rectangle {
        color: TemperatureGaugeDefaultStyle.backgroundColor
    }
}
