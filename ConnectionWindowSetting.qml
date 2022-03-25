import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls

import GameModel 1.0

Rectangle{
    // text: "New Game"
    width: heightCell*4
    height: heightCell*6
    anchors.centerIn: parent

    border.width: 5
    border.color: "gray"

    Rectangle
    {
        width: parent.width
        height: parent.height/2

        anchors.top: parent.top
        border.color: "black"
        border.width: 3
    }

    Button{

        width: parent.width
        height: heightCell

        anchors.top: parent.bottom
        //anchors.verticalCenter: parent.verticalCenter

        text:  "Start";

        onClicked: {visibleBoard  = true;}
    }
}
