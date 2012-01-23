#ifndef DBLISTFILE_H
#define DBLISTFILE_H

#include <fstream>
#include <QDebug>
#include <string>
#include "DBList.h"
#include "TodoItem.h"
#include "TodoList.h"

using std::string;

class DBListFile : public DBList {
private:
    std::fstream m_File;
    string m_sFile;

public:
    DBListFile(string file);

    void load();
    void save();
};

#endif // DBLISTFILE_H
