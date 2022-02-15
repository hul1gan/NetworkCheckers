import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: mainwindow
    width: 700
    height: 700
    visible: true

 Board {
        id:board
       // anchors.centerIn : parent

        BoardLayoutNubmers {
            anchors.right: board.left
        }

        BoardLayoutNubmers {
            anchors.left: board.right
        }

        BoardLayoutSymbols {
            anchors.bottom: board.top
        }


        BoardLayoutSymbols {
            anchors.top: board.bottom
        }

    }

}




