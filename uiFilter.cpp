/****************************************************************************
** Form implementation generated from reading ui file 'uiFilter.ui'
**
** Created: Sat Apr 11 10:04:07 2009
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.8   edited Jan 11 14:47 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "uiFilter.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "uiFilter.ui.h"
/*
 *  Constructs a Filter as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Filter::Filter( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "Filter" );

    bttnStop = new QPushButton( this, "bttnStop" );
    bttnStop->setGeometry( QRect( 300, 180, 151, 51 ) );

    leFilter = new QLineEdit( this, "leFilter" );
    leFilter->setEnabled( FALSE );
    leFilter->setGeometry( QRect( 70, 30, 241, 31 ) );

    bttnStart = new QPushButton( this, "bttnStart" );
    bttnStart->setGeometry( QRect( 80, 180, 181, 51 ) );

    tlOK = new QLabel( this, "tlOK" );
    tlOK->setEnabled( FALSE );
    tlOK->setGeometry( QRect( 330, 40, 66, 21 ) );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setGeometry( QRect( 20, 90, 40, 31 ) );

    leDevice = new QLineEdit( this, "leDevice" );
    leDevice->setGeometry( QRect( 70, 90, 71, 31 ) );

    pbConnect = new QPushButton( this, "pbConnect" );
    pbConnect->setGeometry( QRect( 150, 100, 60, 21 ) );

    tlDevOK = new QLabel( this, "tlDevOK" );
    tlDevOK->setEnabled( TRUE );
    tlDevOK->setGeometry( QRect( 220, 100, 66, 21 ) );

    cbDevs = new QComboBox( FALSE, this, "cbDevs" );
    cbDevs->setGeometry( QRect( 430, 60, 120, 16 ) );
    languageChange();
    resize( QSize(756, 262).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( leFilter, SIGNAL( textChanged(const QString&) ), this, SLOT( tryFilter2(const QString&) ) );
    connect( bttnStart, SIGNAL( clicked() ), this, SLOT( filterStart() ) );
    connect( bttnStop, SIGNAL( clicked() ), this, SLOT( filterStop() ) );
    connect( pbConnect, SIGNAL( clicked() ), this, SLOT( setDevice() ) );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Filter::~Filter()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Filter::languageChange()
{
    setCaption( tr( "Filter" ) );
    bttnStop->setText( tr( "Stop" ) );
    bttnStart->setText( tr( "Start" ) );
    tlOK->setText( tr( "OK" ) );
    textLabel1->setText( tr( "Dev:" ) );
    pbConnect->setText( tr( "Connect" ) );
    tlDevOK->setText( QString::null );
}

