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

        model:gameModel
        anchors.fill: parent

        height: 50
        width: 50

        delegate: Rectangle
        {

            implicitHeight: 50
            implicitWidth: 50

            border.color: "black"
            border.width: 2
    }
    }


       // anchors.centerIn : parent

//        BoardLayoutNubmers {
//            anchors.right: board.left
//        }

//        BoardLayoutNubmers {
//            anchors.left: board.right
//        }

//        BoardLayoutSymbols {
//            anchors.bottom: board.top
//        }


//        BoardLayoutSymbols {
//            anchors.top: board.bottom
//        }

    }






