/****************************************************************************
** Meta object code from reading C++ file 'USERDIALOG.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tetrix/USERDIALOG.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'USERDIALOG.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_USERDIALOG_t {
    QByteArrayData data[7];
    char stringdata[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_USERDIALOG_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_USERDIALOG_t qt_meta_stringdata_USERDIALOG = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 13),
QT_MOC_LITERAL(4, 36, 1),
QT_MOC_LITERAL(5, 38, 14),
QT_MOC_LITERAL(6, 53, 4)
    },
    "USERDIALOG\0okClicked\0\0receive_score\0"
    "s\0enableOKButton\0text\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_USERDIALOG[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08,
       3,    1,   30,    2, 0x08,
       5,    1,   33,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void USERDIALOG::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        USERDIALOG *_t = static_cast<USERDIALOG *>(_o);
        switch (_id) {
        case 0: _t->okClicked(); break;
        case 1: _t->receive_score((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->enableOKButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject USERDIALOG::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_USERDIALOG.data,
      qt_meta_data_USERDIALOG,  qt_static_metacall, 0, 0}
};


const QMetaObject *USERDIALOG::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *USERDIALOG::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_USERDIALOG.stringdata))
        return static_cast<void*>(const_cast< USERDIALOG*>(this));
    return QDialog::qt_metacast(_clname);
}

int USERDIALOG::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
