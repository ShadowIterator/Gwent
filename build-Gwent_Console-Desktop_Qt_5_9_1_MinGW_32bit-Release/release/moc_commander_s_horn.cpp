/****************************************************************************
** Meta object code from reading C++ file 'commander_s_horn.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gwent_Console/Card/commander_s_horn.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commander_s_horn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Commander_s_Horn_t {
    QByteArrayData data[6];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Commander_s_Horn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Commander_s_Horn_t qt_meta_stringdata_Commander_s_Horn = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Commander_s_Horn"
QT_MOC_LITERAL(1, 17, 8), // "_played_"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "Row*"
QT_MOC_LITERAL(4, 32, 10), // "SI_Object*"
QT_MOC_LITERAL(5, 43, 9) // "SI_String"

    },
    "Commander_s_Horn\0_played_\0\0Row*\0"
    "SI_Object*\0SI_String"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Commander_s_Horn[] = {

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

void Commander_s_Horn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Commander_s_Horn *_t = static_cast<Commander_s_Horn *>(_o);
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

const QMetaObject Commander_s_Horn::staticMetaObject = {
    { &Card::staticMetaObject, qt_meta_stringdata_Commander_s_Horn.data,
      qt_meta_data_Commander_s_Horn,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Commander_s_Horn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Commander_s_Horn::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Commander_s_Horn.stringdata0))
        return static_cast<void*>(const_cast< Commander_s_Horn*>(this));
    return Card::qt_metacast(_clname);
}

int Commander_s_Horn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
