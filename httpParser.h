#ifndef HTTP_PARSER
#define HTTP_PARSER

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/if_ether.h> /* includes net/ethernet.h */
#include <sys/socket.h>
#include <arpa/inet.h>

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
