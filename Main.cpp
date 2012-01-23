#include <QtGui>
#include <QtDeclarative>
#include <QGLWidget>
#include <QtDebug>
#include <QFile>
#include <QtXmlPatterns>
#include <QStringList>

#include "TodoItem.h"
#include "TodoList.h"
#include "DBList.h"
#include "DBListFile.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView view;
    QObject::connect(view.engine(), SIGNAL(quit()), qApp, SLOT(quit()));

    DBList *list = new DBListFile("todo.list");
    DBList *ready = new DBListFile("ready.list");

    list->load();
    ready->load();

    QDeclarativeContext *context = view.rootContext();
    context->setContextProperty("listTodo", list->getList());
    context->setContextProperty("listReady", ready->getList());

    view.setSource(QUrl::fromLocalFile("Main.qml"));
    view.setWindowTitle("ToDo List");
    view.show();

    int r = app.exec();

    list->save();
    ready->save();

    return r;
}
