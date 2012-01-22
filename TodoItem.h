#ifndef TODOITEM_H
#define TODOITEM_H

#include <QString>
#include <QMetaType>

class TodoItem;
Q_DECLARE_METATYPE(TodoItem)

class TodoItem{
private:
    QString m_sDesc, m_sId;

public:
    TodoItem();

    QString getDesc();
    QString getID();

    void setDesc(QString desc);
    void setID(QString id);
};

#endif // TODOITEM_H
