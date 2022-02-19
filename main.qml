import QtQuick 2.15
import QtQuick.Window 2.15

import GameModel 1.0

Window {
    id: mainwindow
    width: 700
    height: 700
    visible: true

    GameModel{
   id:gameModel

    }

    TableView{

        id: tableModel

        model:gameModel
        anchors.centerIn: parent


        height: 50*8
        width: 50*8

        delegate: Rectangle
        {
            implicitHeight: 50
            implicitWidth: 50

            border.color: "black"
            border.width: 1;

            color: model.isActiveCell ? "gray"
                                  : "white"


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






