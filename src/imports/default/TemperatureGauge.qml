import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import TemperatureGauge.impl 1.0
import TemperatureGauge.Template 1.0 as T

T.TemperatureGauge {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            (contentItem ? contentItem.implicitWidth : 0) + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             (contentItem ? contentItem.implicitHeight : 0) + topPadding + bottomPadding)

    contentItem: RowLayout {
        spacing: 10
        ColumnLayout {
            id: unitSelector
            scale: 0.8
            RadioButton {
                checked: true
                text: qsTr("Celsius")
                onCheckedChanged: {
                    if (checked) {
                        control.displayUnit = T.TemperatureGauge.Celsius
                    }
                }
            }
            RadioButton {
                text: qsTr("Kelvin")
                onCheckedChanged: {
                    if (checked) {
                        control.displayUnit = T.TemperatureGauge.Kelvin
                    }
                }
            }
        }
        Item {
            id: thermo
            property int mercuryWidth: 20
            property int mercuryHeightScale: 2

            height: backgroundRect.height
            Layout.alignment: Qt.AlignHCenter
            Rectangle {
                id: backgroundRect
                color: TemperatureGaugeDefaultStyle.backgroundColor
                width: thermo.mercuryWidth
                height: (control.maxValue - control.minValue) * thermo.mercuryHeightScale
            }
            Rectangle {
                id: displayValueRect
                color: TemperatureGaugeDefaultStyle.valueColor
                anchors.bottom: backgroundRect.bottom
                width: backgroundRect.width
                height: (control.value - control.minValue) * thermo.mercuryHeightScale
            }
            Repeater {
                id: tickRepeater
                property int majorTickStep: 10
                model: (Math.round(control.maxValue - control.minValue) / tickRepeater.majorTickStep) + 1;
                Row {
                    spacing: 5
                    y: {
                        if (index !== tickRepeater.count - 1) {
                            return (index * tickRepeater.majorTickStep) * thermo.mercuryHeightScale
                        } else {
                            return (index * tickRepeater.majorTickStep) * thermo.mercuryHeightScale - majorTick.height
                        }
                    }

                    width: majorTick.width + majorTickText.width
                    anchors.left: backgroundRect.right
                    Rectangle {
                        id: majorTick
                        height: 1
                        width: 10
                        color: TemperatureGaugeDefaultStyle.tickColor
                    }
                    Text {
                        id: majorTickText
                        font.pointSize: 8
                        anchors.verticalCenter: majorTick.verticalCenter
                        x: majorTick.x + 10
                        text: (control.displayMaxValue - (index * tickRepeater.majorTickStep)).toFixed(2)
                    }
                }
            }
            Text {
                text: control.displayValue.toFixed(2) + (control.displayUnit === T.TemperatureGauge.Celsius ? "C" : "K")
                anchors.top: backgroundRect.bottom
                anchors.topMargin: 10
                font.pointSize: 8
            }
        }
    }
}
