/****************************************************************************
** Meta object code from reading C++ file 'WindowCtrlWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/WindowCtrlWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowCtrlWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CWindowCtrlWidget_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CWindowCtrlWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CWindowCtrlWidget_t qt_meta_stringdata_CWindowCtrlWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CWindowCtrlWidget"
QT_MOC_LITERAL(1, 18, 17), // "Sig_BtnMinClicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "Sig_BtnMaxClicked"
QT_MOC_LITERAL(4, 55, 8), // "bChecked"
QT_MOC_LITERAL(5, 64, 19), // "Sig_BtnCloseClicked"
QT_MOC_LITERAL(6, 84, 14), // "Sig_WindowMove"
QT_MOC_LITERAL(7, 99, 3), // "pos"
QT_MOC_LITERAL(8, 103, 21), // "Sig_WindowShowMaximum"
QT_MOC_LITERAL(9, 125, 4) // "bMax"

    },
    "CWindowCtrlWidget\0Sig_BtnMinClicked\0"
    "\0Sig_BtnMaxClicked\0bChecked\0"
    "Sig_BtnCloseClicked\0Sig_WindowMove\0"
    "pos\0Sig_WindowShowMaximum\0bMax"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CWindowCtrlWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,
       5,    0,   43,    2, 0x06 /* Public */,
       6,    1,   44,    2, 0x06 /* Public */,
       8,    1,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void CWindowCtrlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CWindowCtrlWidget *_t = static_cast<CWindowCtrlWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Sig_BtnMinClicked(); break;
        case 1: _t->Sig_BtnMaxClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->Sig_BtnCloseClicked(); break;
        case 3: _t->Sig_WindowMove((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->Sig_WindowShowMaximum((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CWindowCtrlWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CWindowCtrlWidget::Sig_BtnMinClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CWindowCtrlWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CWindowCtrlWidget::Sig_BtnMaxClicked)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CWindowCtrlWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CWindowCtrlWidget::Sig_BtnCloseClicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CWindowCtrlWidget::*_t)(const QPoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CWindowCtrlWidget::Sig_WindowMove)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CWindowCtrlWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CWindowCtrlWidget::Sig_WindowShowMaximum)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject CWindowCtrlWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CWindowCtrlWidget.data,
      qt_meta_data_CWindowCtrlWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CWindowCtrlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CWindowCtrlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CWindowCtrlWidget.stringdata0))
        return static_cast<void*>(const_cast< CWindowCtrlWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CWindowCtrlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CWindowCtrlWidget::Sig_BtnMinClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CWindowCtrlWidget::Sig_BtnMaxClicked(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CWindowCtrlWidget::Sig_BtnCloseClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CWindowCtrlWidget::Sig_WindowMove(const QPoint & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CWindowCtrlWidget::Sig_WindowShowMaximum(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
