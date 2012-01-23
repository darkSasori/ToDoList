QT += core gui declarative opengl xmlpatterns

CONFIG -= app_bundle
TARGET = ToDoList
TEMPLATE = app

OTHER_FILES += \
    Main.qml

SOURCES += \
    Main.cpp \
    TodoItem.cpp \
    TodoList.cpp \
    DBList.cpp \
    DBListFile.cpp

HEADERS += \
    TodoList.h \
    TodoItem.h \
    DBText.h \
    DBList.h \
    DBListFile.h











