/****************************************************************************
** Meta object code from reading C++ file 'ColorSensorConfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Wendynator/Sensors/ColorSensor/ColorSensorConfig/ColorSensorConfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ColorSensorConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ColorSensorConfig_t {
    QByteArrayData data[12];
    char stringdata[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ColorSensorConfig_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ColorSensorConfig_t qt_meta_stringdata_ColorSensorConfig = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 12),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 37),
QT_MOC_LITERAL(4, 70, 5),
QT_MOC_LITERAL(5, 76, 37),
QT_MOC_LITERAL(6, 114, 44),
QT_MOC_LITERAL(7, 159, 5),
QT_MOC_LITERAL(8, 165, 44),
QT_MOC_LITERAL(9, 210, 41),
QT_MOC_LITERAL(10, 252, 19),
QT_MOC_LITERAL(11, 272, 16)
    },
    "ColorSensorConfig\0rangeChanged\0\0"
    "on_ColorMinChannelSlider_valueChanged\0"
    "value\0on_ColorMaxChannelSlider_valueChanged\0"
    "on_ColorMinChannelOption_currentIndexChanged\0"
    "index\0on_ColorMaxChannelOption_currentIndexChanged\0"
    "on_DefinedColorOption_currentIndexChanged\0"
    "on_okButtom_clicked\0findThresholdImg\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorSensorConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    1,   55,    2, 0x08,
       5,    1,   58,    2, 0x08,
       6,    1,   61,    2, 0x08,
       8,    1,   64,    2, 0x08,
       9,    1,   67,    2, 0x08,
      10,    0,   70,    2, 0x08,
      11,    0,   71,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ColorSensorConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ColorSensorConfig *_t = static_cast<ColorSensorConfig *>(_o);
        switch (_id) {
        case 0: _t->rangeChanged(); break;
        case 1: _t->on_ColorMinChannelSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_ColorMaxChannelSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_ColorMinChannelOption_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_ColorMaxChannelOption_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_DefinedColorOption_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_okButtom_clicked(); break;
        case 7: _t->findThresholdImg(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ColorSensorConfig::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ColorSensorConfig::rangeChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ColorSensorConfig::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ColorSensorConfig.data,
      qt_meta_data_ColorSensorConfig,  qt_static_metacall, 0, 0}
};


const QMetaObject *ColorSensorConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorSensorConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorSensorConfig.stringdata))
        return static_cast<void*>(const_cast< ColorSensorConfig*>(this));
    return QWidget::qt_metacast(_clname);
}

int ColorSensorConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ColorSensorConfig::rangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
