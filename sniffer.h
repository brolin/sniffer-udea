#ifndef SNIFF_H
#define SNIFF_H

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/if_ether.h> /* includes net/ethernet.h */
#include <sys/socket.h>
#include <arpa/inet.h>

void cllback(u_char *, const struct pcap_pkthdr *, const u_char *);

class Sniffer{

public:

  Sniffer();//Throws const char *
  ~Sniffer();
  Sniffer(const char *);//Throws const char *
  void setInterface(const char *);//Throws const char *
  char * tryFilter(const char *, int );	//Return NULL if ok
  char * setLastFilter();//Return NULL if ok
  void filter(char *, char *);
  void filter(char *, char *, char *);
  void filter(char *, char *, char *, char *);
  void filter(char *, char *, char *, char *, int);
  int start();//return 0 si OK, -1 si ERROR, -2 si se parò con breakloop()
  void stop();
 
  int packetLength() const; //Mientras tanto para poder mostrar los paquetes
  const u_char *packet; //Mientras tanto para poder mostrar los paquetes
  bool go; //Mientras tanto para poder mostrar los paquetes


private:

  friend void cllback(u_char *, const struct pcap_pkthdr *, const u_char *);
  struct pcap_pkthdr header;
  pcap_t * handle;
  const char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  int PROMS_MODE;
  bpf_u_int32 mask;		/* The netmask of our sniffing device */
  bpf_u_int32 net;		/* The IP of our sniffing device */
  struct bpf_program lastFilter;



};

#endif
