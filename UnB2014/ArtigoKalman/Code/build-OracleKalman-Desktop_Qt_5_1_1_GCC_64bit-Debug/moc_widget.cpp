/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OracleKalman/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[23];
    char stringdata[565];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Widget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 12),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 7),
QT_MOC_LITERAL(4, 29, 16),
QT_MOC_LITERAL(5, 46, 37),
QT_MOC_LITERAL(6, 84, 5),
QT_MOC_LITERAL(7, 90, 37),
QT_MOC_LITERAL(8, 128, 44),
QT_MOC_LITERAL(9, 173, 5),
QT_MOC_LITERAL(10, 179, 44),
QT_MOC_LITERAL(11, 224, 41),
QT_MOC_LITERAL(12, 266, 30),
QT_MOC_LITERAL(13, 297, 40),
QT_MOC_LITERAL(14, 338, 23),
QT_MOC_LITERAL(15, 362, 23),
QT_MOC_LITERAL(16, 386, 37),
QT_MOC_LITERAL(17, 424, 28),
QT_MOC_LITERAL(18, 453, 4),
QT_MOC_LITERAL(19, 458, 26),
QT_MOC_LITERAL(20, 485, 26),
QT_MOC_LITERAL(21, 512, 26),
QT_MOC_LITERAL(22, 539, 24)
    },
    "Widget\0rangeChanged\0\0process\0"
    "findThresholdImg\0on_ColorMinChannelSlider_valueChanged\0"
    "value\0on_ColorMaxChannelSlider_valueChanged\0"
    "on_ColorMinChannelOption_currentIndexChanged\0"
    "index\0on_ColorMaxChannelOption_currentIndexChanged\0"
    "on_DefinedColorOption_currentIndexChanged\0"
    "on_addTotrackingButtom_clicked\0"
    "on_trackedColorsList_currentIndexChanged\0"
    "on_deleteButtom_clicked\0on_BorrarButtom_clicked\0"
    "on_SizeOfGaussian_currentIndexChanged\0"
    "on_futureButtom_stateChanged\0arg1\0"
    "on_pastButtom_stateChanged\0"
    "on_raioSlider_valueChanged\0"
    "on_ClearPastButtom_clicked\0"
    "on_gnuplotButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,  105,    2, 0x09,
       4,    0,  106,    2, 0x09,
       5,    1,  107,    2, 0x09,
       7,    1,  110,    2, 0x09,
       8,    1,  113,    2, 0x09,
      10,    1,  116,    2, 0x09,
      11,    1,  119,    2, 0x09,
      12,    0,  122,    2, 0x09,
      13,    1,  123,    2, 0x09,
      14,    0,  126,    2, 0x09,
      15,    0,  127,    2, 0x08,
      16,    1,  128,    2, 0x08,
      17,    1,  131,    2, 0x08,
      19,    1,  134,    2, 0x08,
      20,    1,  137,    2, 0x08,
      21,    0,  140,    2, 0x08,
      22,    0,  141,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->rangeChanged(); break;
        case 1: _t->process(); break;
        case 2: _t->findThresholdImg(); break;
        case 3: _t->on_ColorMinChannelSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_ColorMaxChannelSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_ColorMinChannelOption_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_ColorMaxChannelOption_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_DefinedColorOption_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_addTotrackingButtom_clicked(); break;
        case 9: _t->on_trackedColorsList_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_deleteButtom_clicked(); break;
        case 11: _t->on_BorrarButtom_clicked(); break;
        case 12: _t->on_SizeOfGaussian_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_futureButtom_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_pastButtom_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_raioSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_ClearPastButtom_clicked(); break;
        case 17: _t->on_gnuplotButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::rangeChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, 0, 0}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Widget::rangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
