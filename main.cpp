#include <qapplication.h>
#include "uiFilter.h"


int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    Filter w;
    
        //Sniffer * sniff1=new Sniffer("eth1"); //falta catch
    
    
    
    w.show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}
