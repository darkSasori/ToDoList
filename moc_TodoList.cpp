/****************************************************************************
** Meta object code from reading C++ file 'TodoList.h'
**
** Created: Sun Jan 22 14:58:25 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TodoList.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TodoList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TodoList[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x02,
      38,   35,    9,    9, 0x02,
      58,   35,   50,    9, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_TodoList[] = {
    "TodoList\0\0id,desc\0set(int,QString)\0"
    "id\0remove(int)\0QString\0get(int)\0"
};

const QMetaObject TodoList::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_TodoList,
      qt_meta_data_TodoList, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TodoList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TodoList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TodoList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TodoList))
        return static_cast<void*>(const_cast< TodoList*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int TodoList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: set((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: remove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { QString _r = get((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
