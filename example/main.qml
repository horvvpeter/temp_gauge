import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Qt.labs.settings 1.0
import TemperatureGauge 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello TemperatureGauge!")

    Settings {
        id: settings
        property string style
    }

    TemperatureGauge {
        width: 50
        height: 50
    }

    ColumnLayout {
        spacing: 20
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

        Item {
            // spacer
            Layout.fillHeight: true
        }
    }
}
