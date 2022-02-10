import QtQuick 2.15
import QtQuick.Window 2.15

Rectangle{
    width: 50*8 + 4
    height: 50*8 + 4

    border.color: "black"
    border.width: 2

    BoardColumn {
        id: grid1

        Component.onCompleted: {console.log(y)}
    }
    BoardColumn {
        id: grid2
        x: 52
        y: 52

        Component.onCompleted: {console.log(y)}

    }
    BoardColumn {
        id: grid3
        y: 50 * 2 + 2
    }
    BoardColumn {
        id: grid4
        x: 52
        y: 50 * 3 + 2
    }
    BoardColumn {
        id: grid5
        y: 50 * 4 + 2
    }
    BoardColumn {
        id: grid6
        x: 52
        y: 50 * 5 + 2
    }
    BoardColumn {
        id: grid7
        y: 50 * 6  + 2
    }
    BoardColumn {
        id: grid8
        x: 52
        y: 50 * 7 + 2
    }

}


