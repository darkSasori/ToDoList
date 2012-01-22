#ifndef TODOLIST_H
#define TODOLIST_H

#include <QAbstractListModel>
#include <QList>
#include <QDebug>

#include "TodoItem.h"

class TodoList : public QAbstractListModel {
private:
    Q_OBJECT

    QList<TodoItem> m_lTodo;

public:
    enum roles{
        NOME = Qt::UserRole+1,
        ID
    };

    TodoList(QObject *parent = 0);

    void addItem(const TodoItem &item);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    Q_INVOKABLE void set(int id, QString desc);

    Q_INVOKABLE void remove(int id);

    Q_INVOKABLE QString get(int id);
};

#endif // TODOLIST_H
