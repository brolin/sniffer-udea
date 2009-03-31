/****************************************************************************
** Filter meta object code from reading C++ file 'uiFilter.h'
**
** Created: Mon Mar 30 21:37:43 2009
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../.ui/uiFilter.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Filter::className() const
{
    return "Filter";
}

QMetaObject *Filter::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Filter( "Filter", &Filter::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Filter::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Filter", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Filter::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Filter", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Filter::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "inFilter", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"tryFilter2", 1, param_slot_0 };
    static const QUMethod slot_1 = {"filterStart", 0, 0 };
    static const QUMethod slot_2 = {"filterStop", 0, 0 };
    static const QUMethod slot_3 = {"setDevice", 0, 0 };
    static const QUMethod slot_4 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "tryFilter2(const QString&)", &slot_0, QMetaData::Public },
	{ "filterStart()", &slot_1, QMetaData::Public },
	{ "filterStop()", &slot_2, QMetaData::Public },
	{ "setDevice()", &slot_3, QMetaData::Public },
	{ "languageChange()", &slot_4, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Filter", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Filter.setMetaObject( metaObj );
    return metaObj;
}

void* Filter::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Filter" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Filter::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: tryFilter2((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: filterStart(); break;
    case 2: filterStop(); break;
    case 3: setDevice(); break;
    case 4: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Filter::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Filter::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Filter::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
