/****************************************************************************
** Meta object code from reading C++ file 'SpeedMonitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/SpeedMonitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SpeedMonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SpeedMonitor_t {
    QByteArrayData data[16];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpeedMonitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpeedMonitor_t qt_meta_stringdata_SpeedMonitor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SpeedMonitor"
QT_MOC_LITERAL(1, 13, 18), // "Slot_BtnMinClicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 18), // "Slot_BtnMaxClicked"
QT_MOC_LITERAL(4, 52, 8), // "bChecked"
QT_MOC_LITERAL(5, 61, 20), // "Slot_BtnCloseClicked"
QT_MOC_LITERAL(6, 82, 17), // "Slot_WindowMoveTo"
QT_MOC_LITERAL(7, 100, 3), // "pos"
QT_MOC_LITERAL(8, 104, 19), // "Slot_CreateTrainWgt"
QT_MOC_LITERAL(9, 124, 11), // "nUpDownType"
QT_MOC_LITERAL(10, 136, 10), // "strDevName"
QT_MOC_LITERAL(11, 147, 16), // "Slot_ChartUpdate"
QT_MOC_LITERAL(12, 164, 15), // "Slot_GrabWindow"
QT_MOC_LITERAL(13, 180, 21), // "Slot_ChangeUpDownType"
QT_MOC_LITERAL(14, 202, 20), // "E_TRAIN_UP_DOWN_TYPE"
QT_MOC_LITERAL(15, 223, 5) // "eType"

    },
    "SpeedMonitor\0Slot_BtnMinClicked\0\0"
    "Slot_BtnMaxClicked\0bChecked\0"
    "Slot_BtnCloseClicked\0Slot_WindowMoveTo\0"
    "pos\0Slot_CreateTrainWgt\0nUpDownType\0"
    "strDevName\0Slot_ChartUpdate\0Slot_GrabWindow\0"
    "Slot_ChangeUpDownType\0E_TRAIN_UP_DOWN_TYPE\0"
    "eType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpeedMonitor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    1,   59,    2, 0x08 /* Private */,
       8,    2,   62,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,
      12,    0,   68,    2, 0x08 /* Private */,
      13,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void SpeedMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpeedMonitor *_t = static_cast<SpeedMonitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Slot_BtnMinClicked(); break;
        case 1: _t->Slot_BtnMaxClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->Slot_BtnCloseClicked(); break;
        case 3: _t->Slot_WindowMoveTo((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->Slot_CreateTrainWgt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->Slot_ChartUpdate(); break;
        case 6: _t->Slot_GrabWindow(); break;
        case 7: _t->Slot_ChangeUpDownType((*reinterpret_cast< E_TRAIN_UP_DOWN_TYPE(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SpeedMonitor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SpeedMonitor.data,
      qt_meta_data_SpeedMonitor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SpeedMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpeedMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SpeedMonitor.stringdata0))
        return static_cast<void*>(const_cast< SpeedMonitor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SpeedMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
