import QtQuick 2.0
import QtQuick.Controls 1.4

import com.itage 1.0

Rectangle {
    objectName: "rect"
    width: 600
    height: 600
    color: "red"

    Plug {
        id: plug
    }

    Label {
        id: txt
        width: 600
    }

    Component.onCompleted: {
        var list = plug.invert_matrix(1.0,-1.0, -1.0,-1.0, 1.0,1.0, -1.0,1.0);
        for (var i = 0; i < 8; i++) {
            console.log("value: " + list[i]);
        }
    }
}
