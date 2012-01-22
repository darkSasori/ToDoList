import QtQuick 1.0



Rectangle {
    id: rect
    width: 800
    height: 600
    color: "#332d2d"


    Flickable {
         width: 50; height: menu.height
         contentWidth: menu.width; contentHeight: menu.height

         Rectangle {
             id: menu
             width: 170; height: 600;
             color: "#00000000"
             border.color: "#f5eaea"
             radius: 5

             Text {
                 text: qsTr("MENU")
                 color: "white"
                 x: 45; y: 10
                 font.pixelSize: 25
             }

             Rectangle{
                 id: btnTodo
                 x: 10; y: 40
                 width: 100
                 height: 40
                 color: "red"
                 border.color: "#f5eaea"
                 border.width: 2
                 radius: 10
                 Text {
                     x: 10
                     y: 10
                     color: "white"
                     text: qsTr("To Do")
                     font.pixelSize: 20
                 }
                 MouseArea {
                     anchors.fill: parent
                     onClicked: {
                         lista.model = null
                         lista.model = listTodo
                         lista.delegate = dListTodo
                     }
                 }
             }

             Rectangle{
                 id: btnReady
                 x: 10; y: 90
                 width: 100
                 height: 40
                 color: "red"
                 border.color: "#f5eaea"
                 border.width: 2
                 radius: 10
                 Text {
                     x: 10
                     y: 10
                     color: "white"
                     text: qsTr("Ready")
                     font.pixelSize: 20
                 }
                 MouseArea {
                     anchors.fill: parent
                     onClicked: {
                         lista.model = null
                         lista.model = listReady
                         lista.delegate = dListReady
                     }
                 }
             }

             Rectangle{
                 id: btnAdd
                 x: 10; y: 140
                 width: 100
                 height: 40
                 color: "red"
                 border.color: "#f5eaea"
                 border.width: 2
                 radius: 10
                 Text {
                     x: 10
                     y: 10
                     color: "white"
                     text: qsTr("Add")
                     font.pixelSize: 20
                 }
                 MouseArea {
                     anchors.fill: parent
                     onClicked: {
                         addItem.pos.x= 300
                     }
                 }
             }

             Rectangle{
                 id: btnQuit
                 x: 10; y: 190
                 width: 100
                 height: 40
                 color: "red"
                 border.color: "#f5eaea"
                 border.width: 2
                 radius: 10
                 Text {
                     x: 10
                     y: 10
                     color: "white"
                     text: qsTr("Quit")
                     font.pixelSize: 20
                 }
                 MouseArea {
                     anchors.fill: parent
                     onClicked: {
                         Qt.quit();
                     }
                 }
             }
         }
     }

     Text {
         id: text1
         x: 274
         y: 0
         color: "#eee3e3"
         text: qsTr("TODO List")
         font.pixelSize: 50
     }

     Component {
         id: dListTodo
         Item {
             width: 180; height: 25
             Row {
                 spacing: 5
                 Image {
                     source: "check.gif"
                     MouseArea {
                         anchors.fill: parent
                         onClicked: {
                             listReady.set(-1, listTodo.get(index))
                             listTodo.remove(index)
                             lista.model = null
                             lista.model = listTodo
                         }
                     }
                 }
                 Image {
                     source: "btn_close.png"
                     MouseArea {
                         anchors.fill: parent
                         onClicked: {
                             listTodo.remove(index)
                             lista.model = null
                             lista.model = listTodo
                         }
                     }
                 }
                 Text {
                     text: name
                     color: "white"
                     MouseArea {
                         anchors.fill: parent
                         onClicked: {
                             txtItem.text= name
                             addItem.indexItem=index
                             addItem.pos.x=300
                         }
                     }
                 }
             }

         }
     }

     Component {
         id: dListReady
         Item {
             width: 180; height: 25
             Row {
                 spacing: 5
                 Image {
                     source: "btn_close.png"
                     MouseArea {
                         anchors.fill: parent
                         onClicked: {
                             listReady.remove(index)
                             lista.model = null
                             lista.model = listReady
                         }
                     }
                 }
                 Text {
                     text: name
                     color: "white"
                     MouseArea {
                         anchors.fill: parent
                         onClicked: {
                             txtItem.text= name
                             addItem.indexItem=index
                             addItem.pos.x=300
                         }
                     }
                 }
             }

         }
     }

     ListView {
         id: lista
         anchors.leftMargin: 120
         anchors.topMargin: 100
         anchors.fill: parent
         model: listTodo
         delegate: dListTodo
         focus: true
     }

     Rectangle{
         id: addItem
         x: -300; y: 250
         width: 250
         height: 75
         color: "#00000000"
         border.color: "#f5eaea"
         border.width: 2
         radius: 2
         property int indexItem: -1

         Rectangle {
             x: 10; y: 10
             color: "#00000000"
             border.color: "#f5eaea"
             border.width: 1
             width: 230
             height: 20
             TextInput {
                 id: txtItem
                 x: 5; y: 2
                 width: 220
                 color: "white"
                 text: "Description"
                 selectByMouse: true
                 Keys.onPressed: {
                     if( event.key == Qt.Key_Enter || event.key == 16777220 ){
                         listTodo.set(addItem.indexItem, txtItem.text);
                         lista.model = null
                         lista.model = listTodo
                         lista.delegate = dListTodo

                         txtItem.text = "Description"
                         addItem.pos.x = -300
                         addItem.indexItem=-1
                     }
                 }
             }
         }

         Rectangle {
             id: btnItem
             x: 130; y: 40
             width: 43
             height: 25
             color: "red"
             border.color: "#f5eaea"
             border.width: 2
             radius: 10
             Text {
                 x: 10
                 y: 5
                 color: "white"
                 text: qsTr("OK")
                 font.pixelSize: 15
             }
             MouseArea {
                 id: objSet;
                 anchors.fill: parent
                 onClicked: {
                     listTodo.set(addItem.indexItem, txtItem.text);
                     lista.model = null
                     lista.model = listTodo
                     lista.delegate = dListTodo

                     txtItem.text = "Description"
                     addItem.pos.x = -300
                     addItem.indexItem=-1
                 }
             }
         }

         Rectangle {
             id: btnCancel
             x: 180; y: 40
             width: 60
             height: 25
             color: "red"
             border.color: "#f5eaea"
             border.width: 2
             radius: 10
             Text {
                 x: 5
                 y: 5
                 color: "white"
                 text: qsTr("Cancel")
                 font.pixelSize: 15
             }
             MouseArea {
                 anchors.fill: parent
                 onClicked: {
                     txtItem.text = "Description"
                     addItem.pos.x = -300
                     addItem.indexItem=-1
                 }
             }
         }
     }
}
