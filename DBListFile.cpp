#include "DBListFile.h"

DBListFile::DBListFile(string file)
    :m_sFile(file)
    ,DBList(){
}

void DBListFile::load(){
    m_File.open(m_sFile.c_str(), std::fstream::in);
    if( !m_File.is_open() )
        return;

    char desc[256];
    while( !m_File.eof() ){
        m_File.getline(desc, 256);

        if( strlen(desc) > 0 ){
            TodoItem item;
            item.setDesc(desc);
            addItem(item);
        }
    }

    m_File.close();
}

void DBListFile::save(){
    m_File.open(m_sFile.c_str(), std::fstream::out);
    if( !m_File.is_open() )
        return;

    foreach ( TodoItem item, getList()->getList()) {
        m_File << item.getDesc().toStdString() << std::endl;
    }
    m_File.close();
}
