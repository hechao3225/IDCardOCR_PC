/****************************************************************************
** Meta object code from reading C++ file 'ocrthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IDCardOCR/ocrthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ocrthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OCRThread_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OCRThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OCRThread_t qt_meta_stringdata_OCRThread = {
    {
QT_MOC_LITERAL(0, 0, 9), // "OCRThread"
QT_MOC_LITERAL(1, 10, 12), // "newOCRResult"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "QString&"
QT_MOC_LITERAL(4, 33, 3), // "str"
QT_MOC_LITERAL(5, 37, 11), // "progressVal"
QT_MOC_LITERAL(6, 49, 8), // "infoType"
QT_MOC_LITERAL(7, 58, 7), // "ocrDone"
QT_MOC_LITERAL(8, 66, 19) // "startTesseractError"

    },
    "OCRThread\0newOCRResult\0\0QString&\0str\0"
    "progressVal\0infoType\0ocrDone\0"
    "startTesseractError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OCRThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,
       7,    0,   36,    2, 0x06 /* Public */,
       8,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OCRThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OCRThread *_t = static_cast<OCRThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newOCRResult((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->ocrDone(); break;
        case 2: _t->startTesseractError(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OCRThread::*_t)(QString & , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OCRThread::newOCRResult)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (OCRThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OCRThread::ocrDone)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (OCRThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OCRThread::startTesseractError)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject OCRThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_OCRThread.data,
      qt_meta_data_OCRThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OCRThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OCRThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OCRThread.stringdata0))
        return static_cast<void*>(const_cast< OCRThread*>(this));
    return QThread::qt_metacast(_clname);
}

int OCRThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void OCRThread::newOCRResult(QString & _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OCRThread::ocrDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void OCRThread::startTesseractError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
