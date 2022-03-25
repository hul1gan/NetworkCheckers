import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls

import GameModel 1.0

Window {

    property int heightCell: 100
    property int widthCell: 100
    property bool visibleBoard: true


    color: "#333333"

    id: mainwindow
    width: heightCell*9.5
    height: heightCell*9.5

    visible: true

//    ConnectionWindowSetting {
//    }


    Rectangle{

        visible: visibleBoard

        color: "#333333"


        property int counter: 0

        id: mainRectangle

        anchors.fill:parent

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

                color: model.figure.isSelectedCell ? "lightgoldenrodyellow": (model.figure.isHighLightCell ? Qt.lighter(cellColor, 1.6) : cellColor)

                Image {

                    id: img
                    anchors.fill: delegate
                    source: model.figure.imgPath
                    antialiasing: true

                }


                MouseArea
                {
                    id: mouse
                    anchors.fill: parent
                    hoverEnabled: true

                    onClicked:
                    {
                        // model.figure.isSelected = true;
                        mainRectangle.counter ++;
                        //console.log(mainRectangle.counter);

                        if(mainRectangle.counter == 2)
                        {
                            gameModel.checkPossibilityMove(row + 1, column + 1);
                            mainRectangle.counter = 0;

                        }
                        else
                        {
                            gameModel.findPossibleMoves(row + 1, column + 1);
                        }


                    }

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
