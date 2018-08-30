import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    LabelButton{
        text: "启动程序"
        width: 100
        height: 60
        anchors.centerIn: parent
        onClicked: {
            startupManager.startTool()
        }
    }
}
