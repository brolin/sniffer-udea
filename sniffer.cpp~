#include "sniffer.h"
#include <iostream>


Sniffer::Sniffer(){

dev=pcap_lookupdev(errbuf);//Se trata de encontrar uno.. si no.. lanza char *
if(dev==0)
throw "Ninguna interface disponible";
 
if(pcap_lookupnet(dev, &mask, &net, errbuf)==-1)
throw "Error de configuración de Interface";

handle= pcap_open_live(dev,BUFSIZ,PROMS_MODE,1000,errbuf);//Hacerlo aca o desde antes???
  if(handle==0)
    	throw errbuf;
      

PROMS_MODE=0;
go=false;
}

Sniffer::Sniffer(const char * inDev){

dev=inDev;

if(dev==0)
throw "Interfaz no válida";


if(pcap_lookupnet(dev, &mask, &net, errbuf)==-1)
throw "Error de configuración de Interface";

handle= pcap_open_live(dev,BUFSIZ,PROMS_MODE,1000,errbuf);//Hacerlo aca o desde antes???
  if(handle==0)
    throw errbuf;
    

handle=NULL;
PROMS_MODE=0;
go=false;

}

Sniffer::~Sniffer(){

pcap_close(handle);//QUe pasa cuando handle es NULL ???

}
void Sniffer::setInterface(const char * inDev){

dev=inDev;
if (handle!=0)
    pcap_close(handle);

handle= pcap_open_live(dev,BUFSIZ,PROMS_MODE,1000,errbuf);//Hacerlo aca o desde antes???
  if(handle==0)
    throw errbuf;

}



int Sniffer::start()
{

  //packet=pcap_next(handle,&header);

  std::cout<< "original: "<<std::hex<< this<<"\n";
 
  
  /*if(packet==0)
  {
    inerrbuf="NO packets";
    return -1;
  }*/

  return  pcap_loop(handle,-1,cllback,(u_char *) this);

}

void Sniffer::stop(){
   pcap_breakloop(handle);
}


 int Sniffer::packetLength() const{

return  header.len;

}


char * Sniffer::tryFilter( const char * inFilter, int optim=0 ){
if ( pcap_compile(handle, &lastFilter,inFilter, optim,mask)==-1 )
  return pcap_geterr(handle);

return NULL;

}

char * Sniffer::setLastFilter(){
if ( pcap_setfilter(handle,&lastFilter) ==-1 )
  return pcap_geterr(handle);

return NULL;


}

void cllback(u_char * args, const struct pcap_pkthdr * headerin, const u_char *packetin)
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
