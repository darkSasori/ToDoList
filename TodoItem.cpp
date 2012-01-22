#include "TodoItem.h"

TodoItem::TodoItem(){
}


QString TodoItem::getDesc(){
    return m_sDesc;
}

QString TodoItem::getID(){
    return m_sId;
}

void TodoItem::setDesc(QString desc){
    m_sDesc = desc;
}

void TodoItem::setID(QString id){
    m_sId = id;
}
