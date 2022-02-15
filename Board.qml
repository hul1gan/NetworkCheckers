import QtQuick 2.15
import QtQuick.Window 2.15

Rectangle{


//    border.color: "black"
//    border.width: 2

    BoardColumn {
        id: grid1
        x: 50
        Rectangle { color: "chocolate"; width: 50; height: 50}
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }


    }
    BoardColumn {
        id: grid2
        y: 50
        Rectangle { color: "chocolate"; width: 50; height: 50}
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }


    }
    BoardColumn {
        id: grid3
        y: 50 * 2
        x: 50
        Rectangle { color: "chocolate"; width: 50; height: 50}
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }

    }
    BoardColumn {
        id: grid4
        y: 50 * 3
        Rectangle { color: "chocolate"; width: 50; height: 50}
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }

    }
    BoardColumn {
        id: grid5
        y: 50 * 4
        x: 50
        Rectangle { color: "chocolate"; width: 50; height: 50}
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }

    }
    BoardColumn {
        id: grid6
        y: 50 * 5
        Rectangle { color: "chocolate"; width: 50; height: 50}
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }

    }
    BoardColumn {
        id: grid7
        y: 50 * 6
        x: 50
        Rectangle { color: "chocolate"; width: 50; height: 50}
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }

    }
    BoardColumn {
        id: grid8
        y: 50 * 7
        Rectangle { color: "chocolate"; width: 50; height: 50}
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }
        Rectangle { color: "chocolate"; width: 50; height: 50 }

    }

}
