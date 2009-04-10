#include "sniffer.h"

#include <iostream>
#include <sstream> //para hacer la conversión de int a char *
#include <string.h>

char Sniffer::devNames[MAX_DEVS][MAX_NAME_LENGTH]={'\0'};

Sniffer::Sniffer(){

dev=pcap_lookupdev(errbuf);//Se trata de encontrar uno.. si no.. lanza char *

if(dev==0)
  throw "Ninguna interface disponible";
 
//Si configuración es incorrecta lanza char *
if(pcap_lookupnet(dev, &mask, &net, errbuf)==-1)
  throw "Error de configuración de Interface";


//Si no se logró abrir para captura
handle= pcap_open_live(dev,BUFSIZ,PROMS_MODE,1000,errbuf);
if(handle==0)
  throw errbuf;
      

PROMS_MODE=0;
tempOutFile="test001";

}

Sniffer::Sniffer(const char * inDev, int proms){

dev=inDev;
PROMS_MODE=proms;

//si dev==0 se capturará de todas las interfaces
// Sólo válido para linux

//Si configuración es incorrecta lanza char *
if(pcap_lookupnet(dev, &mask, &net, errbuf)==-1)
  throw errbuf;

//Si no se pudo abrir para captura lanza char *
handle= pcap_open_live(dev,BUFSIZ,PROMS_MODE,1000,errbuf);
if(handle==0)
  throw errbuf;
    

tempOutFile="test001";

}

//Ojo con esto.. creo q hay q cerrar los handles en stop
Sniffer::~Sniffer(){

    //QUe pasa cuando son NULL?????
pcap_close(handle);
pcap_dump_close(handleDumper);
}


void Sniffer::setInterface(const char * inDev, int proms){

pcap_t * handleTemp;//Para no alterar los datos actuales si se presenta error

//BUFSIZ es declarado por pcap
//1000 es el read timeout, en este caso no importa pues siempre se usa con loop.

//Si no se pudo abrir para captura lanza char *
handleTemp= pcap_open_live(inDev,BUFSIZ,proms,1000,errbuf);
if(handleTemp==0)
  throw errbuf;
else
{
    //Cierra cualquier cosa que se hubiera abierto anteriormente
    if (handle!=0)
    pcap_close(handle);
    
    handle=handleTemp;
    PROMS_MODE=proms;
}

}


void Sniffer::readFile(const char * fileIn)
{
pcap_t * handleTemp;//Para no alterar los datos actuales si se presenta error

handleTemp=pcap_open_offline(fileIn,errbuf);
if(handleTemp==0)
  throw pcap_geterr(handle);//Lanza char * con error
else{
  //Por si se habia iniciado de otra forma en el constructor
  if(handle!=0)
  pcap_close(handle);

  handle=handleTemp;
}

}


const char * Sniffer::start()
{
  int rtnVal;
  
//packet=pcap_next(handle,&header);

  /*if(packet==0)
  {
    inerrbuf="NO packets";
    return -1;
  }*/
  if(handle==0)
  return "Error:Origen de datos indefinido";
  
  
  handleDumper=pcap_dump_open(handle, tempOutFile);
  if(handleDumper==0)
  return pcap_geterr(handle);

  //rtnVal=pcap_loop(handle,-1,cllback,(u_char *) this);
  rtnVal=pcap_loop(handle,-1,pcap_dump, (u_char *)handleDumper);

  switch(rtnVal){

  case 0://Llegaron los paquetes pedidos
  return NULL;
  break;

  case -1://Error, retorna char * 
  return pcap_geterr(handle);
  break;

  case -2://Se detuvo sin leer ningún paquete
  return NULL;
  break;

default:
return "Error Desconocido";    
  }
    

}

void Sniffer::stop(){
   pcap_breakloop(handle);
}

/*
 int Sniffer::packetLength() const{

return  header.len;

}*/

//Intenta compilar el filtro indicado
//Lo almacena el lastFilter
const char * Sniffer::tryFilter( const char * inFilter, int optim ){

if ( pcap_compile(handle, &lastFilter,inFilter, optim,mask)==-1 )
  return pcap_geterr(handle);

return NULL;

}

//Intenta activar el último filtro compilado (guardado el lastFilter)
const char * Sniffer::setLastFilter(){
if ( pcap_setfilter(handle,&lastFilter) ==-1 )
  return pcap_geterr(handle);

return NULL;


}

int Sniffer :: listDevs(){

char errbufStatic[PCAP_ERRBUF_SIZE];//Ojo con esto, que voy a hacer con el ??
 
int i=0;
pcap_if_t * devList, * ptrList;


if ( pcap_findalldevs(&devList,errbufStatic) == -1 ) 
  {
    //printf("Error in pcap_findalldevs: %s\n", errbuf);
  return -1;
    }

ptrList=devList;
while( ptrList!= 0){
  //devNames[i][0]=devlist[i]->name;
  //devNames[i]=ptrList->name;
  strncpy(&devNames[i][0], ptrList->name,MAX_NAME_LENGTH-1);
  devNames[i][MAX_NAME_LENGTH-1]='\0'; 
//std::cout<<devNames[i]<<"\n";
  i++;  
  ptrList=ptrList->next;
  std::cout<<i;
  if(i==MAX_DEVS)
  return i;

}

return i;

/*char * devNames[i+1];
std::ostringstream int2char;

int2char<<i;
devNames[0]=int2char.str();

ptrList=devList;
for(int j=1;j < i+1; j++){
  devNames[j]=ptrList->name;
  ptrList=ptrList->next;
}

return devNames;
*/
}


//Hasta ahora no hay nada que detectar aca
//Se verfica si el archivo genera error a la hora de inciar la captura
const char * Sniffer::dataToFile(const char * inFileName){

tempOutFile=inFileName;

return NULL;

}


const char * Sniffer::getTempFileName() const{

return tempOutFile;


}

/*void cllback(u_char * args, const struct pcap_pkthdr * headerin, const u_char *packetin)
{	static int j=0;
    Sniffer * sniff=(Sniffer* )args;
    std::cout<<"Copia: "<< std::hex<<sniff<<"\n";
    sniff->header=*headerin;
    sniff->packet=packetin;

  j++;
  std::cout<<"Se ha llamado "<<j<<" veces a cllback()\n";
  if(j==5)
  {sniff->go=true;
  std::cout<<"salió";
  }
}
*/
