import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    SwipeView {
          id: view

          currentIndex: 1
          anchors.fill: parent

          Item {
              id: firstPage
              Rectangle{
                  width: 640
                  height: 480
                  color: "red"
                  LabelButton{
                      text: "启动程序"
                      width: 100
                      height: 60
                      anchors.centerIn: parent
                      onClicked: {
                          startupManager.startTool()
                      }
                  }
                  LabelButton{
                      id:statusButton
                      anchors.left: parent.left
                      anchors.top: parent.top
                      text: ""
                      width: 100
                      height: 60
                  }
              }
          }
          Item {
              id: secondPage
              Rectangle{

              }
          }
          Item {
              id: thirdPage
              Rectangle{

              }
          }
      }

      PageIndicator {
          id: indicator

          count: view.count
          currentIndex: view.currentIndex

          anchors.bottom: view.bottom
          anchors.horizontalCenter: parent.horizontalCenter
      }

    Connections{
        target: startupManager
        onUpdateCurrentRunningStatus:{
            statusButton.text=status
        }
    }
}
