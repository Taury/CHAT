/****************************************************************************
** Meta object code from reading C++ file 'mainwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWin_t {
    QByteArrayData data[19];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWin_t qt_meta_stringdata_MainWin = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MainWin"
QT_MOC_LITERAL(1, 8, 29), // "on_pushButton_connect_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 29), // "on_radioButton_TcpSvr_clicked"
QT_MOC_LITERAL(4, 69, 10), // "newConnect"
QT_MOC_LITERAL(5, 80, 9), // "read_data"
QT_MOC_LITERAL(6, 90, 10), // "disConnect"
QT_MOC_LITERAL(7, 101, 25), // "on_pushButton_snd_clicked"
QT_MOC_LITERAL(8, 127, 27), // "on_pushButton_clear_clicked"
QT_MOC_LITERAL(9, 155, 29), // "on_radioButton_TcpClt_clicked"
QT_MOC_LITERAL(10, 185, 27), // "on_checkBox_autoSnd_clicked"
QT_MOC_LITERAL(11, 213, 7), // "checked"
QT_MOC_LITERAL(12, 221, 26), // "on_pushButton_file_clicked"
QT_MOC_LITERAL(13, 248, 34), // "on_listWidget_rcvmsg_doubleCl..."
QT_MOC_LITERAL(14, 283, 5), // "index"
QT_MOC_LITERAL(15, 289, 8), // "recvFile"
QT_MOC_LITERAL(16, 298, 26), // "on_radioButton_Udp_clicked"
QT_MOC_LITERAL(17, 325, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(18, 347, 4) // "arg1"

    },
    "MainWin\0on_pushButton_connect_clicked\0"
    "\0on_radioButton_TcpSvr_clicked\0"
    "newConnect\0read_data\0disConnect\0"
    "on_pushButton_snd_clicked\0"
    "on_pushButton_clear_clicked\0"
    "on_radioButton_TcpClt_clicked\0"
    "on_checkBox_autoSnd_clicked\0checked\0"
    "on_pushButton_file_clicked\0"
    "on_listWidget_rcvmsg_doubleClicked\0"
    "index\0recvFile\0on_radioButton_Udp_clicked\0"
    "on_comboBox_activated\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    1,   92,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    1,   96,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    1,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void MainWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWin *_t = static_cast<MainWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_connect_clicked(); break;
        case 1: _t->on_radioButton_TcpSvr_clicked(); break;
        case 2: _t->newConnect(); break;
        case 3: _t->read_data(); break;
        case 4: _t->disConnect(); break;
        case 5: _t->on_pushButton_snd_clicked(); break;
        case 6: _t->on_pushButton_clear_clicked(); break;
        case 7: _t->on_radioButton_TcpClt_clicked(); break;
        case 8: _t->on_checkBox_autoSnd_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_file_clicked(); break;
        case 10: _t->on_listWidget_rcvmsg_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->recvFile(); break;
        case 12: _t->on_radioButton_Udp_clicked(); break;
        case 13: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWin::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWin.data,
      qt_meta_data_MainWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWin.stringdata0))
        return static_cast<void*>(const_cast< MainWin*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
