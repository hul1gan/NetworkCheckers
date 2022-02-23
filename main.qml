import QtQuick 2.15
import QtQuick.Window 2.15

import GameModel 1.0

Window {
    id: mainwindow
    width: 700
    height: 700
    visible: true

    color: "#1B2E1D"

    GameModel{
        id:gameModel

    }

    Rectangle{
        anchors.centerIn: parent

        height:500
        width: 500

        color: "#61221F"

    TableView{

        id: tableModel

        model:gameModel
        anchors.centerIn: parent


        height: 50*8
        width: 50*8

        delegate: Rectangle
        {
            id:delegate
            implicitHeight: 50
            implicitWidth: 50

            border.color: "#E7D8A7"
            border.width: 0.2;

            color: model.isActiveCell ? "#613E1F"
                                      : "#BE9D80"
            Image {
                id: img
                anchors.fill: delegate
                source: model.isActiveCell&&(!model.isEmptyCell)?model.color: ""


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







