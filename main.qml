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
        plug.invert_matrix(1, 1, 1, 1, 1, 1, 1, 1);
    }
}
