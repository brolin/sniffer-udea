#ifndef SNIFFTHREAD_H
#define  SNIFFTHREAD_H


#include "sniffer.h"
#include <qthread.h>

//class sniffThread : public QThread , public Sniffer {
class sniffThread : public QThread {
    
public:
    ~sniffThread();
    void run();
    
    void setSniffer(Sniffer *);

private:
    Sniffer * sniff;
};


#endif 
