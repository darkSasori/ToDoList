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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView view;
    QObject::connect(view.engine(), SIGNAL(quit()), qApp, SLOT(quit()));

    TodoList *list = new TodoList();
    TodoList *ready = new TodoList();


    QDeclarativeContext *context = view.rootContext();
    context->setContextProperty("listTodo", list);
    context->setContextProperty("listReady", ready);

    view.setSource(QUrl::fromLocalFile("Main.qml"));
    view.setWindowTitle("ToDo List");
    view.show();

    int r = app.exec();

    return r;
}
