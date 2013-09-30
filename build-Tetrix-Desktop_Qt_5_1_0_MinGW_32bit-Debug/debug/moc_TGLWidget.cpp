/****************************************************************************
** Meta object code from reading C++ file 'TGLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tetrix/TGLWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TGLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TGLWidget_t {
    QByteArrayData data[11];
    char stringdata[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TGLWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TGLWidget_t qt_meta_stringdata_TGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 12),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 12),
QT_MOC_LITERAL(4, 37, 11),
QT_MOC_LITERAL(5, 49, 9),
QT_MOC_LITERAL(6, 59, 10),
QT_MOC_LITERAL(7, 70, 13),
QT_MOC_LITERAL(8, 84, 14),
QT_MOC_LITERAL(9, 99, 5),
QT_MOC_LITERAL(10, 105, 15)
    },
    "TGLWidget\0scorechanged\0\0levelchanged\0"
    "linechanged\0user_show\0send_score\0"
    "slow_dropdown\0quick_dropdown\0start\0"
    "pauseORcontinue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TGLWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x05,
       3,    1,   62,    2, 0x05,
       4,    1,   65,    2, 0x05,
       5,    0,   68,    2, 0x05,
       6,    1,   69,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    0,   72,    2, 0x08,
       8,    0,   73,    2, 0x08,
       9,    0,   74,    2, 0x08,
      10,    0,   75,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TGLWidget *_t = static_cast<TGLWidget *>(_o);
        switch (_id) {
        case 0: _t->scorechanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->levelchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->linechanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->user_show(); break;
        case 4: _t->send_score((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slow_dropdown(); break;
        case 6: _t->quick_dropdown(); break;
        case 7: _t->start(); break;
        case 8: _t->pauseORcontinue(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TGLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TGLWidget::scorechanged)) {
                *result = 0;
            }
        }
        {
            typedef void (TGLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TGLWidget::levelchanged)) {
                *result = 1;
            }
        }
        {
            typedef void (TGLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TGLWidget::linechanged)) {
                *result = 2;
            }
        }
        {
            typedef void (TGLWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TGLWidget::user_show)) {
                *result = 3;
            }
        }
        {
            typedef void (TGLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TGLWidget::send_score)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject TGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_TGLWidget.data,
      qt_meta_data_TGLWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *TGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TGLWidget.stringdata))
        return static_cast<void*>(const_cast< TGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int TGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TGLWidget::scorechanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TGLWidget::levelchanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TGLWidget::linechanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TGLWidget::user_show()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void TGLWidget::send_score(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
