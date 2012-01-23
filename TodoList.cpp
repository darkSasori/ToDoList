#include "TodoList.h"

TodoList::TodoList(QObject *parent)
    :QAbstractListModel(parent){
    QHash<int, QByteArray> r;
    r[NOME] = "name";
    r[ID]   = "id";
    setRoleNames(r);
}

void TodoList::addItem(const TodoItem &item){
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_lTodo << item;
    endInsertRows();
}

int TodoList::rowCount(const QModelIndex &parent) const{
    return m_lTodo.count();
}

QVariant TodoList::data(const QModelIndex &index, int role) const{
    if( m_lTodo.count() < 0 || index.row() > m_lTodo.count() )
        return QVariant();

    TodoItem item = m_lTodo[index.row()];
    switch( role ){
    case NOME:
        return item.getDesc();
    case ID:
        return item.getID();
    default:
        return QVariant();
    }
}

Q_INVOKABLE void TodoList::set(int id, QString desc){
    if( id == -1 ){
        TodoItem item;
        item.setDesc(desc);
        item.setID("5");
        addItem(item);
    }
    else
        m_lTodo[id].setDesc(desc);
}

Q_INVOKABLE void TodoList::remove(int id){
    m_lTodo.removeAt(id);
}

Q_INVOKABLE QString TodoList::get(int id){
    return m_lTodo[id].getDesc();
}

QList<TodoItem> TodoList::getList(){
    return m_lTodo;
}
