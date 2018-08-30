import QtQuick 2.0
import QtQuick.Controls 1.4
Rectangle {
    property color enterColor:"red"
    property color backColor :"#35CCFF"
    property alias text:label.text
    property alias label:label
    signal clicked
    id: root
    color: backColor
    radius: width/2
    Label{
        id:label
        font.family: "微软雅黑"
        anchors.centerIn: parent
        color:"white"
    }
    ParallelAnimation{
        id:enter

        ColorAnimation {
            from: root.backColor
            to:   root.enterColor
            duration: 200
            target: root
            properties: "color"
        }
    }
    ParallelAnimation{
        id:exit

        ColorAnimation {
            from: root.enterColor
            to:root.backColor
            duration: 200
            target: root
            properties: "color"
        }
    }
    MouseArea{
        hoverEnabled: true
        anchors.fill: parent
        onEntered:enter.start()
        onExited: exit.start()
        onClicked: root.clicked()
    }
}
