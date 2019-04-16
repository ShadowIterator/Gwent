/****************************************************************************
** Meta object code from reading C++ file 'foglet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gwent_Console/Card/foglet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'foglet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Foglet_t {
    QByteArrayData data[10];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Foglet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Foglet_t qt_meta_stringdata_Foglet = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Foglet"
QT_MOC_LITERAL(1, 7, 11), // "_startTurn_"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "_setWeather_"
QT_MOC_LITERAL(4, 33, 4), // "Row*"
QT_MOC_LITERAL(5, 38, 8), // "Weather*"
QT_MOC_LITERAL(6, 47, 10), // "SI_Object*"
QT_MOC_LITERAL(7, 58, 9), // "SI_String"
QT_MOC_LITERAL(8, 68, 15), // "_removeWeather_"
QT_MOC_LITERAL(9, 84, 11) // "__doConnect"

    },
    "Foglet\0_startTurn_\0\0_setWeather_\0Row*\0"
    "Weather*\0SI_Object*\0SI_String\0"
    "_removeWeather_\0__doConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Foglet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x0a /* Public */,
       3,    4,   39,    2, 0x0a /* Public */,
       8,    3,   48,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 5, 0x80000000 | 6, 0x80000000 | 7,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 7,    2,    2,    2,
    QMetaType::Void,

       0        // eod
};

void Foglet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Foglet *_t = static_cast<Foglet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->_startTurn_((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->_setWeather_((*reinterpret_cast< Row*(*)>(_a[1])),(*reinterpret_cast< Weather*(*)>(_a[2])),(*reinterpret_cast< SI_Object*(*)>(_a[3])),(*reinterpret_cast< SI_String(*)>(_a[4]))); break;
        case 2: _t->_removeWeather_((*reinterpret_cast< Row*(*)>(_a[1])),(*reinterpret_cast< SI_Object*(*)>(_a[2])),(*reinterpret_cast< SI_String(*)>(_a[3]))); break;
        case 3: _t->__doConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SI_Object* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SI_Object* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Foglet::staticMetaObject = {
    { &Card::staticMetaObject, qt_meta_stringdata_Foglet.data,
      qt_meta_data_Foglet,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Foglet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Foglet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Foglet.stringdata0))
        return static_cast<void*>(const_cast< Foglet*>(this));
    return Card::qt_metacast(_clname);
}

int Foglet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Card::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
