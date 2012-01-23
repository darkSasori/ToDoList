#include "DBList.h"

DBList::DBList(){
    m_List = new TodoList();
}

DBList::~DBList(){
}

void DBList::addItem(const TodoItem &item){
    m_List->addItem(item);
}

TodoList* DBList::getList(){
    return this->m_List;
}
