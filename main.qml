import QtQuick 2.15
import QtQuick.Window 2.15

import GameModel 1.0

Window {
    id: mainwindow
    width: 700
    height: 700
    visible: true

    color: "#333333"

    GameModel {
        id:gameModel
    }

    Rectangle {
        anchors.centerIn: parent

        height:500
        width: 500

        color: "#86858d"

        TableView {

            id: tableModel

            model:gameModel
            anchors.centerIn: parent


            height: 50*8
            width: 50*8

            delegate: Rectangle
            {
                readonly property color cellColor: model.isActiveCell ? "#9b7b73" : "#d3c9cc"

                id:delegate
                implicitHeight: 50
                implicitWidth: 50

                border.color: "#73717B"
                border.width: 0.2;

                color: mouse.containsMouse? Qt.lighter(cellColor, 1.3): cellColor

                Image {
                    id: img
                    anchors.fill: delegate
                    source: model.isActiveCell && (!model.isEmptyCell) ? model.color: ""
                }

                MouseArea
                {
                    id: mouse
                    anchors.fill: parent
                    hoverEnabled: true

                    onClicked: {
                        if(model.isActiveCell && (!model.isEmptyCell))
                        {
                            console.log("chose");
                            gameModel.findWay(model.rowPosition, model.colPosition);
                        }

                    }
                }
                Text
                {
                    text: model.rowPosition.toString() + model.colPosition
                }
            }
        }

        BoardLayoutNubmers {
            parent: tableModel
            anchors.right: tableModel.left
        }

        BoardLayoutNubmers {
            parent: tableModel
            anchors.left: tableModel.right
        }

        BoardLayoutSymbols {
            parent: tableModel
            anchors.bottom: tableModel.top
        }

        BoardLayoutSymbols {
            parent: tableModel
            anchors.top: tableModel.bottom
        }
    }




}







