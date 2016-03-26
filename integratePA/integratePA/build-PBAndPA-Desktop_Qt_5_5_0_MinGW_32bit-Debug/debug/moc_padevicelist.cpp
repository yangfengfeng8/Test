/****************************************************************************
** Meta object code from reading C++ file 'padevicelist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PBAndPA/PA/padevicelist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'padevicelist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PAAddDevice_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PAAddDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PAAddDevice_t qt_meta_stringdata_PAAddDevice = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PAAddDevice"
QT_MOC_LITERAL(1, 12, 7), // "readyIP"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "errors"
QT_MOC_LITERAL(4, 28, 14), // "connectClicked"
QT_MOC_LITERAL(5, 43, 13) // "cancelClicked"

    },
    "PAAddDevice\0readyIP\0\0errors\0connectClicked\0"
    "cancelClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PAAddDevice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   40,    2, 0x0a /* Public */,
       5,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PAAddDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PAAddDevice *_t = static_cast<PAAddDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyIP((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->errors((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->connectClicked(); break;
        case 3: _t->cancelClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PAAddDevice::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PAAddDevice::readyIP)) {
                *result = 0;
            }
        }
        {
            typedef void (PAAddDevice::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PAAddDevice::errors)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject PAAddDevice::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PAAddDevice.data,
      qt_meta_data_PAAddDevice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PAAddDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PAAddDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PAAddDevice.stringdata0))
        return static_cast<void*>(const_cast< PAAddDevice*>(this));
    return QDialog::qt_metacast(_clname);
}

int PAAddDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PAAddDevice::readyIP(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PAAddDevice::errors(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_PADeviceList_t {
    QByteArrayData data[35];
    char stringdata0[540];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PADeviceList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PADeviceList_t qt_meta_stringdata_PADeviceList = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PADeviceList"
QT_MOC_LITERAL(1, 13, 28), // "changeCurrentIPForMainWindow"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 2), // "IP"
QT_MOC_LITERAL(4, 46, 19), // "changeCurrentStatus"
QT_MOC_LITERAL(5, 66, 6), // "Status"
QT_MOC_LITERAL(6, 73, 6), // "errors"
QT_MOC_LITERAL(7, 80, 19), // "connectDeviceForTab"
QT_MOC_LITERAL(8, 100, 22), // "disconnectDeviceForTab"
QT_MOC_LITERAL(9, 123, 18), // "deleteDeviceForTab"
QT_MOC_LITERAL(10, 142, 18), // "rebootDeviceForTab"
QT_MOC_LITERAL(11, 161, 26), // "searchDevicePortNameForTab"
QT_MOC_LITERAL(12, 188, 26), // "changeDevicePortNameForTab"
QT_MOC_LITERAL(13, 215, 30), // "getDevicePortNameForPAPortName"
QT_MOC_LITERAL(14, 246, 13), // "connectDevice"
QT_MOC_LITERAL(15, 260, 16), // "disconnectDevice"
QT_MOC_LITERAL(16, 277, 9), // "addDevice"
QT_MOC_LITERAL(17, 287, 12), // "deleteDevice"
QT_MOC_LITERAL(18, 300, 10), // "pingDevice"
QT_MOC_LITERAL(19, 311, 12), // "rebootDevice"
QT_MOC_LITERAL(20, 324, 14), // "portNameDevice"
QT_MOC_LITERAL(21, 339, 9), // "dectionIP"
QT_MOC_LITERAL(22, 349, 14), // "connectSuccess"
QT_MOC_LITERAL(23, 364, 17), // "disconnectSuccess"
QT_MOC_LITERAL(24, 382, 16), // "updateDeviceType"
QT_MOC_LITERAL(25, 399, 4), // "List"
QT_MOC_LITERAL(26, 404, 13), // "getDeviceType"
QT_MOC_LITERAL(27, 418, 8), // "Firmware"
QT_MOC_LITERAL(28, 427, 6), // "closed"
QT_MOC_LITERAL(29, 434, 40), // "on_treeWidget_customContextMe..."
QT_MOC_LITERAL(30, 475, 3), // "pos"
QT_MOC_LITERAL(31, 479, 31), // "on_treeWidget_itemDoubleClicked"
QT_MOC_LITERAL(32, 511, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(33, 528, 4), // "item"
QT_MOC_LITERAL(34, 533, 6) // "column"

    },
    "PADeviceList\0changeCurrentIPForMainWindow\0"
    "\0IP\0changeCurrentStatus\0Status\0errors\0"
    "connectDeviceForTab\0disconnectDeviceForTab\0"
    "deleteDeviceForTab\0rebootDeviceForTab\0"
    "searchDevicePortNameForTab\0"
    "changeDevicePortNameForTab\0"
    "getDevicePortNameForPAPortName\0"
    "connectDevice\0disconnectDevice\0addDevice\0"
    "deleteDevice\0pingDevice\0rebootDevice\0"
    "portNameDevice\0dectionIP\0connectSuccess\0"
    "disconnectSuccess\0updateDeviceType\0"
    "List\0getDeviceType\0Firmware\0closed\0"
    "on_treeWidget_customContextMenuRequested\0"
    "pos\0on_treeWidget_itemDoubleClicked\0"
    "QTreeWidgetItem*\0item\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PADeviceList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  139,    2, 0x06 /* Public */,
       4,    1,  142,    2, 0x06 /* Public */,
       6,    1,  145,    2, 0x06 /* Public */,
       7,    1,  148,    2, 0x06 /* Public */,
       8,    1,  151,    2, 0x06 /* Public */,
       9,    1,  154,    2, 0x06 /* Public */,
      10,    1,  157,    2, 0x06 /* Public */,
      11,    1,  160,    2, 0x06 /* Public */,
      12,    1,  163,    2, 0x06 /* Public */,
      13,    1,  166,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  169,    2, 0x0a /* Public */,
      15,    0,  170,    2, 0x0a /* Public */,
      16,    0,  171,    2, 0x0a /* Public */,
      17,    0,  172,    2, 0x0a /* Public */,
      18,    0,  173,    2, 0x0a /* Public */,
      19,    0,  174,    2, 0x0a /* Public */,
      20,    0,  175,    2, 0x0a /* Public */,
      21,    1,  176,    2, 0x0a /* Public */,
      22,    1,  179,    2, 0x0a /* Public */,
      23,    1,  182,    2, 0x0a /* Public */,
      24,    1,  185,    2, 0x0a /* Public */,
      26,    1,  188,    2, 0x0a /* Public */,
      28,    0,  191,    2, 0x0a /* Public */,
      29,    1,  192,    2, 0x08 /* Private */,
      31,    2,  195,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QStringList,   25,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   30,
    QMetaType::Void, 0x80000000 | 32, QMetaType::Int,   33,   34,

       0        // eod
};

void PADeviceList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PADeviceList *_t = static_cast<PADeviceList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeCurrentIPForMainWindow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->changeCurrentStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->errors((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->connectDeviceForTab((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->disconnectDeviceForTab((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->deleteDeviceForTab((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->rebootDeviceForTab((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->searchDevicePortNameForTab((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->changeDevicePortNameForTab((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->getDevicePortNameForPAPortName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->connectDevice(); break;
        case 11: _t->disconnectDevice(); break;
        case 12: _t->addDevice(); break;
        case 13: _t->deleteDevice(); break;
        case 14: _t->pingDevice(); break;
        case 15: _t->rebootDevice(); break;
        case 16: _t->portNameDevice(); break;
        case 17: _t->dectionIP((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->connectSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->disconnectSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->updateDeviceType((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 21: _t->getDeviceType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->closed(); break;
        case 23: _t->on_treeWidget_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 24: _t->on_treeWidget_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PADeviceList::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PADeviceList::changeCurrentIPForMainWindow)) {
                *result = 0;
            }
        }
        {
            typedef void (PADeviceList::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PADeviceList::changeCurrentStatus)) {
                *result = 1;
            }
        }
        {
            typedef void (PADeviceList::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PADeviceList::errors)) {
                *result = 2;
            }
        }
        {
            typedef void (PADeviceList::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PADeviceList::connectDeviceForTab)) {
                *result = 3;
            }
        }
        {
            typedef void (PADeviceList::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PADeviceList::disconnectDeviceForTab)) {
                *result = 4;
            }
        }
        {
            typedef void (PADeviceList::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PADeviceList::deleteDeviceForTab)) {
                *result = 5;
            }
        }
        {
            typedef void (PADeviceList::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PADeviceList::rebootDeviceForTab)) {
                *result = 6;
            }
        }
        {
            typedef void (PADeviceList::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PADeviceList::searchDevicePortNameForTab)) {
                *result = 7;
            }
        }
        {
            typedef void (PADeviceList::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PADeviceList::changeDevicePortNameForTab)) {
                *result = 8;
            }
        }
        {
            typedef void (PADeviceList::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PADeviceList::getDevicePortNameForPAPortName)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject PADeviceList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PADeviceList.data,
      qt_meta_data_PADeviceList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PADeviceList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PADeviceList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PADeviceList.stringdata0))
        return static_cast<void*>(const_cast< PADeviceList*>(this));
    return QWidget::qt_metacast(_clname);
}

int PADeviceList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void PADeviceList::changeCurrentIPForMainWindow(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PADeviceList::changeCurrentStatus(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PADeviceList::errors(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PADeviceList::connectDeviceForTab(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PADeviceList::disconnectDeviceForTab(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PADeviceList::deleteDeviceForTab(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PADeviceList::rebootDeviceForTab(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PADeviceList::searchDevicePortNameForTab(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PADeviceList::changeDevicePortNameForTab(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PADeviceList::getDevicePortNameForPAPortName(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
