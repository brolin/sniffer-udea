#ifndef HTTP_PARSER
#define HTTP_PARSER

#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <arpa/inet.h>
#include <net/ethernet.h>
 
#ifdef LINUX
#include <netinet/ether.h>
#endif
 
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
 
#include <fcntl.h>
#include <getopt.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <pcap.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

/*
  struct nread_ip -> ip header
  struct nread_tcp -> tcp header
 */

class httpParser {
 public:
  httpParser();
  ~httpParser();

};

#endif
