/****************************************************************************
** Meta object code from reading C++ file 'paPortName.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PBAndPA/PA/paPortName.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paPortName.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PAPortName_t {
    QByteArrayData data[10];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PAPortName_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PAPortName_t qt_meta_stringdata_PAPortName = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PAPortName"
QT_MOC_LITERAL(1, 11, 14), // "changePortName"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 17), // "onExprtPubClicked"
QT_MOC_LITERAL(4, 45, 18), // "onImportPubClicked"
QT_MOC_LITERAL(5, 64, 14), // "onOKPubClicked"
QT_MOC_LITERAL(6, 79, 17), // "onClearPubClicked"
QT_MOC_LITERAL(7, 97, 9), // "showLater"
QT_MOC_LITERAL(8, 107, 11), // "setPortName"
QT_MOC_LITERAL(9, 119, 7) // "strRecv"

    },
    "PAPortName\0changePortName\0\0onExprtPubClicked\0"
    "onImportPubClicked\0onOKPubClicked\0"
    "onClearPubClicked\0showLater\0setPortName\0"
    "strRecv"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PAPortName[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   52,    2, 0x08 /* Private */,
       4,    0,   53,    2, 0x08 /* Private */,
       5,    0,   54,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void PAPortName::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PAPortName *_t = static_cast<PAPortName *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changePortName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onExprtPubClicked(); break;
        case 2: _t->onImportPubClicked(); break;
        case 3: _t->onOKPubClicked(); break;
        case 4: _t->onClearPubClicked(); break;
        case 5: _t->showLater(); break;
        case 6: _t->setPortName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PAPortName::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PAPortName::changePortName)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PAPortName::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PAPortName.data,
      qt_meta_data_PAPortName,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PAPortName::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PAPortName::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PAPortName.stringdata0))
        return static_cast<void*>(const_cast< PAPortName*>(this));
    return QDialog::qt_metacast(_clname);
}

int PAPortName::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PAPortName::changePortName(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
