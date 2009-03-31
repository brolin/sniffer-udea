/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/
#include <qapplication.h>
#include "sniffThread.h"
#include "sniffer.h"

// sniffThread * sniff1;
Sniffer * sniff1;
sniffThread * sniffThr;

void Filter::init(){
    try{
    sniff1=new Sniffer(); //falta catch
}catch (const char *){
  
}
catch (char *){
  qDebug("NO se inció bien");    
}

    sniffThr=new sniffThread(); //falta catch

qDebug("Pasó por Init() ");
}

void Filter::destroy(){
    
    qDebug("Entra destructor de Ventana Filter");    
    
    sniff1->stop();
    while(sniffThr->running())
	wait();
    
   qDebug("Se detiene captura");

    
    delete sniffThr;
    qDebug("Se borra sniffThr");
    
    delete sniff1;  
    qDebug("Se borra sniff1");
     
 

}
	


void Filter::tryFilter2( const QString & inFilter)
{    qDebug("Entra bien");
    //qDebug(inFilter);
    if ( sniff1->tryFilter( inFilter.latin1(),0  ) == 0)
{
qDebug("Filtro bien");
leFilter->setPaletteBackgroundColor(QColor(255,255,255));//Rojo
	tlOK->setEnabled(true);

}
    else{qDebug("Filtro mal");
	leFilter->setPaletteBackgroundColor(QColor(255,0,0));//Blanco
	tlOK->setEnabled(false);
}
}


void Filter::filterStart()
{
   if( leFilter->isModified() )
    {    sniff1->setLastFilter(); //Falta verificar return
    qDebug("Puso bien el filtro");
}
    //sniff1->Sniffer::start();
   // sniff1->start();
    sniffThr->setSniffer(sniff1); //Define el objeto sniffer dentro del nuevo thread
    sniffThr->start();//Comienza el nuevo thread q a su vez comienza la captura
    qDebug("Volvió de Start()");
}


void Filter::filterStop()
{
    sniff1->stop();
}


void Filter::setDevice()
{
    try{   sniff1->setInterface( ( leDevice->text() ).latin1() ) ;
    }catch (char * error)
    {	qDebug(error);
	leDevice->clear();
	return;
   }
    tlDevOK->setText("Dev OK");
    pbConnect->setEnabled(false);
    leDevice->setEnabled(false);
    
}
