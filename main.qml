import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    id: root
    signal debugPrint(string msg)

    Rectangle {
        objectName: "rect"
        width: 600
        height: 600

        Text {
            width: 100
            height: 100

            text: message.name
            Component.onCompleted: {
                message.name = "Jonah"
            }
        }

        Text {
            x: 50
            y: 0

            text: message.Age()
        }

        TextField {
            id: tf
            x: 0
            y: 20
            placeholderText: qsTr("Enter name")

            onAccepted: {
                message.name = text;
                root.debugPrint(text);
            }
        }

        function rectFunc() {
            console.log("rect func");
        }
    }

    function rootFunc() {
        console.log("root func");
    }

}
