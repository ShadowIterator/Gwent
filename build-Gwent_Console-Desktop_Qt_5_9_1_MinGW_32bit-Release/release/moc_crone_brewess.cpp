/****************************************************************************
** Meta object code from reading C++ file 'crone_brewess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gwent_Console/Card/crone_brewess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'crone_brewess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Crone_Brewess_t {
    QByteArrayData data[6];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Crone_Brewess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Crone_Brewess_t qt_meta_stringdata_Crone_Brewess = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Crone_Brewess"
QT_MOC_LITERAL(1, 14, 8), // "_played_"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "Row*"
QT_MOC_LITERAL(4, 29, 10), // "SI_Object*"
QT_MOC_LITERAL(5, 40, 9) // "SI_String"

    },
    "Crone_Brewess\0_played_\0\0Row*\0SI_Object*\0"
    "SI_String"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Crone_Brewess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 5,    2,    2,    2,    2,

       0        // eod
};

void Crone_Brewess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Crone_Brewess *_t = static_cast<Crone_Brewess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->_played_((*reinterpret_cast< Row*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< SI_Object*(*)>(_a[3])),(*reinterpret_cast< SI_String(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SI_Object* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Crone_Brewess::staticMetaObject = {
    { &Card::staticMetaObject, qt_meta_stringdata_Crone_Brewess.data,
      qt_meta_data_Crone_Brewess,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Crone_Brewess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Crone_Brewess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Crone_Brewess.stringdata0))
        return static_cast<void*>(const_cast< Crone_Brewess*>(this));
    return Card::qt_metacast(_clname);
}

int Crone_Brewess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Card::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
