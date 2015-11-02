import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    id: root
    width: 600
    height: 600

    signal debugPrint(string msg)

    Text {
        width: 100
        height: 100

        text: message.name
        Component.onCompleted: {
            message.name = "Jonah"
        }
    }

    TextField {
        id: tf
        x: 0
        y: 20
        placeholderText: qsTr("Enter name")

        onAccepted: {
            message.name = text;
            root.debugPrint(text);
            console.log(message.Name());
        }
    }
}
