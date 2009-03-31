/****************************************************************************
** Form interface generated from reading ui file 'uiFilter.ui'
**
** Created: Tue Mar 31 10:41:38 2009
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.8   edited Jan 11 14:47 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FILTER_H
#define FILTER_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLineEdit;
class QLabel;

class Filter : public QDialog
{
    Q_OBJECT

public:
    Filter( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Filter();

    QPushButton* bttnStop;
    QLineEdit* leFilter;
    QPushButton* bttnStart;
    QLabel* tlOK;
    QLabel* textLabel1;
    QLineEdit* leDevice;
    QPushButton* pbConnect;
    QLabel* tlDevOK;

public slots:
    virtual void tryFilter2( const QString & inFilter );
    virtual void filterStart();
    virtual void filterStop();
    virtual void setDevice();

protected:

protected slots:
    virtual void languageChange();

private:
    void init();
    void destroy();

};

#endif // FILTER_H
