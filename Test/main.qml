import QtQuick
import QtQuick.Window

Window {
    visible: true
    width: 500
    height: 500
    title: "QSvgRenTest"

    Image {
	    id: image
        anchors.fill: parent
	    source: "image://QSvgRen/:/tiger.svg"
	    sourceSize.width: width
        sourceSize.height: height
    }
}
