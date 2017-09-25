import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Qt.labs.settings 1.0
import TemperatureGauge 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 500
    height: 400
    title: qsTr("TemperatureGauge example")

    Settings {
        id: settings
        property string style
    }

    ColumnLayout {
        spacing: 10
        anchors.fill: parent
        anchors.margins: 10

        RowLayout {
            spacing: 10

            Label {
                text: "Select style:"
            }

            ComboBox {
                id: styleBox
                property int styleIndex: -1
                model: availableStyles
                Component.onCompleted: {
                    styleIndex = find(settings.style, Qt.MatchFixedString)
                    if (styleIndex !== -1)
                        currentIndex = styleIndex
                }
                Layout.fillWidth: true
            }

            Popup {
                id: styleSavePopup
                closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
                modal: true
                x: Math.round(window.width - width) / 2
                y: Math.round(window.height - height) / 2

                Text {
                    text: "Restart is required for style change"
                }
            }

            Button {
                text: "Save"
                onClicked: {
                    settings.style = styleBox.displayText;
                    styleSavePopup.open();
                }
            }
        }

        RowLayout {
            spacing: 10
            TemperatureGauge {
                id: temperatureGauge
                minValue: -50
                maxValue: 50
            }

            Dial {
                from: temperatureGauge.minValue
                to: temperatureGauge.maxValue
                onValueChanged: temperatureGauge.value = value
                scale: 0.8
                Layout.fillWidth: true
                Text {
                    anchors.centerIn: parent
                    text: parent.value.toFixed(2)
                }
            }
        }

        Item {
            // spacer
            Layout.fillHeight: true
        }
    }
}
