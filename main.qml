import QtQuick 2.12
import QtQuick.Window 2.12
import Painter 1.0
import QtQuick.Controls 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("i am burning")

    PainterItemQml {
        id: painterdItem
        width: 100
        height: 100
        anchors.centerIn: parent
    }

    Column {
        anchors.left: painterdItem.right
        anchors.leftMargin: 40
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        Button {

            text: "Clear"
            onClicked: {
                painterdItem.clearImage()
            }
        }

        Button {
            text: "Alayze"
            onClicked: {
                imageAnalyzer.analyzeImage(painterdItem.toImage())
            }
        }
    }

    Text {
        anchors.top: painterdItem.bottom
        anchors.topMargin: 50
        font.pixelSize: 30
        font.bold: true
        text: imageAnalyzer.resultStr
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
