/****************************************************************************
** Meta object code from reading C++ file 'mainpasswordmenu.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainpasswordmenu.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainpasswordmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSmainpasswordmenuENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSmainpasswordmenuENDCLASS = QtMocHelpers::stringData(
    "mainpasswordmenu",
    "closeEvent",
    "",
    "QCloseEvent*",
    "event",
    "on_addAccount_clicked",
    "showEvent",
    "QShowEvent*",
    "refreshTable",
    "on_addMenu_clicked",
    "on_deleteMenu_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSmainpasswordmenuENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[17];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[6];
    char stringdata5[22];
    char stringdata6[10];
    char stringdata7[12];
    char stringdata8[13];
    char stringdata9[19];
    char stringdata10[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSmainpasswordmenuENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSmainpasswordmenuENDCLASS_t qt_meta_stringdata_CLASSmainpasswordmenuENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "mainpasswordmenu"
        QT_MOC_LITERAL(17, 10),  // "closeEvent"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 12),  // "QCloseEvent*"
        QT_MOC_LITERAL(42, 5),  // "event"
        QT_MOC_LITERAL(48, 21),  // "on_addAccount_clicked"
        QT_MOC_LITERAL(70, 9),  // "showEvent"
        QT_MOC_LITERAL(80, 11),  // "QShowEvent*"
        QT_MOC_LITERAL(92, 12),  // "refreshTable"
        QT_MOC_LITERAL(105, 18),  // "on_addMenu_clicked"
        QT_MOC_LITERAL(124, 21)   // "on_deleteMenu_clicked"
    },
    "mainpasswordmenu",
    "closeEvent",
    "",
    "QCloseEvent*",
    "event",
    "on_addAccount_clicked",
    "showEvent",
    "QShowEvent*",
    "refreshTable",
    "on_addMenu_clicked",
    "on_deleteMenu_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmainpasswordmenuENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x08,    1 /* Private */,
       5,    0,   53,    2, 0x08,    3 /* Private */,
       6,    1,   54,    2, 0x08,    4 /* Private */,
       8,    0,   57,    2, 0x08,    6 /* Private */,
       9,    0,   58,    2, 0x08,    7 /* Private */,
      10,    0,   59,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject mainpasswordmenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSmainpasswordmenuENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmainpasswordmenuENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmainpasswordmenuENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<mainpasswordmenu, std::true_type>,
        // method 'closeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>,
        // method 'on_addAccount_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QShowEvent *, std::false_type>,
        // method 'refreshTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addMenu_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteMenu_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void mainpasswordmenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainpasswordmenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->closeEvent((*reinterpret_cast< std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        case 1: _t->on_addAccount_clicked(); break;
        case 2: _t->showEvent((*reinterpret_cast< std::add_pointer_t<QShowEvent*>>(_a[1]))); break;
        case 3: _t->refreshTable(); break;
        case 4: _t->on_addMenu_clicked(); break;
        case 5: _t->on_deleteMenu_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *mainpasswordmenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainpasswordmenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmainpasswordmenuENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::mainpasswordmenuClass"))
        return static_cast< Ui::mainpasswordmenuClass*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainpasswordmenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
