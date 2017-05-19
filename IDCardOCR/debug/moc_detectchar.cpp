/****************************************************************************
** Meta object code from reading C++ file 'detectchar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../detectchar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detectchar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DetectChar_t {
    QByteArrayData data[14];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DetectChar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DetectChar_t qt_meta_stringdata_DetectChar = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DetectChar"
QT_MOC_LITERAL(1, 11, 7), // "ShowImg"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 14), // "ProcessClicked"
QT_MOC_LITERAL(4, 35, 25), // "on_testPushButton_clicked"
QT_MOC_LITERAL(5, 61, 28), // "on_pushButton_clear1_clicked"
QT_MOC_LITERAL(6, 90, 12), // "updateResult"
QT_MOC_LITERAL(7, 103, 9), // "resultStr"
QT_MOC_LITERAL(8, 113, 11), // "progressVal"
QT_MOC_LITERAL(9, 125, 8), // "infoType"
QT_MOC_LITERAL(10, 134, 16), // "updateIDCardInfo"
QT_MOC_LITERAL(11, 151, 18), // "showTesseractError"
QT_MOC_LITERAL(12, 170, 16), // "onCompleteCature"
QT_MOC_LITERAL(13, 187, 12) // "captureImage"

    },
    "DetectChar\0ShowImg\0\0ProcessClicked\0"
    "on_testPushButton_clicked\0"
    "on_pushButton_clear1_clicked\0updateResult\0"
    "resultStr\0progressVal\0infoType\0"
    "updateIDCardInfo\0showTesseractError\0"
    "onCompleteCature\0captureImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DetectChar[] = {

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
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    3,   58,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,
      11,    0,   66,    2, 0x0a /* Public */,
      12,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,   13,

       0        // eod
};

void DetectChar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DetectChar *_t = static_cast<DetectChar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowImg(); break;
        case 1: _t->ProcessClicked(); break;
        case 2: _t->on_testPushButton_clicked(); break;
        case 3: _t->on_pushButton_clear1_clicked(); break;
        case 4: _t->updateResult((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->updateIDCardInfo(); break;
        case 6: _t->showTesseractError(); break;
        case 7: _t->onCompleteCature((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DetectChar::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DetectChar.data,
      qt_meta_data_DetectChar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DetectChar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DetectChar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DetectChar.stringdata0))
        return static_cast<void*>(const_cast< DetectChar*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DetectChar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
