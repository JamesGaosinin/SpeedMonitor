/****************************************************************************
** Meta object code from reading C++ file 'ToolWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/ToolWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ToolWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CToolWidget_t {
    QByteArrayData data[8];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CToolWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CToolWidget_t qt_meta_stringdata_CToolWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CToolWidget"
QT_MOC_LITERAL(1, 12, 14), // "Sig_GrabWindow"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "Sig_UpDownClicked"
QT_MOC_LITERAL(4, 46, 20), // "E_TRAIN_UP_DOWN_TYPE"
QT_MOC_LITERAL(5, 67, 5), // "eType"
QT_MOC_LITERAL(6, 73, 18), // "Slot_UpDownClicked"
QT_MOC_LITERAL(7, 92, 8) // "bChecked"

    },
    "CToolWidget\0Sig_GrabWindow\0\0"
    "Sig_UpDownClicked\0E_TRAIN_UP_DOWN_TYPE\0"
    "eType\0Slot_UpDownClicked\0bChecked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CToolWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void CToolWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CToolWidget *_t = static_cast<CToolWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Sig_GrabWindow(); break;
        case 1: _t->Sig_UpDownClicked((*reinterpret_cast< E_TRAIN_UP_DOWN_TYPE(*)>(_a[1]))); break;
        case 2: _t->Slot_UpDownClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CToolWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CToolWidget::Sig_GrabWindow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CToolWidget::*_t)(E_TRAIN_UP_DOWN_TYPE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CToolWidget::Sig_UpDownClicked)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CToolWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CToolWidget.data,
      qt_meta_data_CToolWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CToolWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CToolWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CToolWidget.stringdata0))
        return static_cast<void*>(const_cast< CToolWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CToolWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CToolWidget::Sig_GrabWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CToolWidget::Sig_UpDownClicked(E_TRAIN_UP_DOWN_TYPE _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
