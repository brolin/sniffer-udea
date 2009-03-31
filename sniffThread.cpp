#include "sniffThread.h"

void sniffThread::run(){
    sniff->start();

}


void sniffThread::setSniffer(Sniffer * inSniffer){
    
  sniff=inSniffer;  
    
}


sniffThread:: ~sniffThread(){
    
    qDebug("Se llamó destructor de thread");
   
}
