#include "DBList.h"

DBList::~DBList(){
}

TodoList* DBList::getList(){
    return this->m_List;
}
