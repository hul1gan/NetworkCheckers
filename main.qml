import QtQuick 2.15
import QtQuick.Window 2.15

import GameModel 1.0

Window {
    property int heightCell: 100
    property int widthCell: 100

    id: mainwindow
    width: heightCell*9.5
    height: heightCell*9.5
    visible: true

    color: "#333333"

    GameModel {
        id:gameModel
    }

    TableView {

        id: tableModel

        model:gameModel
        anchors.centerIn: parent


        height: heightCell*8
        width: widthCell*8

        delegate: Rectangle
        {

            readonly property color cellColor: model.figure.isActiveCell ? "#333333" : Qt.lighter("#333333", 1.3)

            id:delegate
            implicitHeight: heightCell
            implicitWidth: widthCell

            border.color: "#73717B"
            border.width: 0.2;

            color: model.figure.isSelected ? Qt.lighter(cellColor, 1.6): cellColor

            Image {
                id: img
                anchors.fill: delegate
                source: model.figure.imgPath
                antialiasing: true
                //rotation: 180
            }

            MouseArea
            {
                id: mouse
                anchors.fill: parent
                hoverEnabled: true
                onClicked:
                {
                    gameModel.findWay(row + 1, column + 1);
                    console.log(index);

                    ;}
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












