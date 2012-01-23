#ifndef DBLIST_H
#define DBLIST_H

#include "TodoItem.h"
#include "TodoList.h"

class DBList {
private:
    TodoList *m_List;

protected:
    void addItem(const TodoItem &item);

public:
    DBList();
    virtual ~DBList();

    virtual void load() = 0;
    virtual void save() = 0;

    TodoList* getList();
};

#endif // DBLIST_H
