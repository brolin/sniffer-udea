 
#ifndef SNIFF_H
#define SNIFF_H

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/if_ether.h> /* includes net/ethernet.h */
#include <sys/socket.h>
#include <arpa/inet.h>

class Sniffer{

public:

  Sniffer();//Busca la primera interfaz disponible, si no encuentra ninguna o la encontrada no esta bien configurada lanza const char * con mensaje de error. Modo Promiscuo desactivado.
  ~Sniffer();
  Sniffer(const char *,int =0 );//Recibe como argumento el nombre de un dispositivo. Si no se puede acceder a él lanza interrupción char *. IMPORTANTE; si arg=NULL se intenta capturar de todas las interfaces disponibles. Segundo argumento: modo promiscuo, activado=1, desact=0 (por defecto).
  void setInterface(const char *, int =0);//Recibe como argumento el nombre de un dispositivo. Si no se puede acceder a él lanza interrupción char *. IMPORTANTE; si arg=NULL intenta capturar de todas las interfaces disponibles. (Se puede usar sin importar que constructor se usó.Segundo argumento: modo promiscuo, activado=1, desact=0 (por defecto).
  void readFile(const char *);// Define como origen de datos un archivo. Si no se puede usar el archivo lanza interrupción char *.
  const char * tryFilter(const char *, int p=0);//Verifica si la sintaxis del filtro indicado por const char * es correcta. el argumento int es opcional e indica si se desea optimizar el filtro. Retorna NULL si está bien o un mensaje de error en caso contrario.
  const char * setLastFilter();//Intenta definir el último filtro probado con tryFilter() como activo para la captura. Retorna NULL si no hubo problemas o un mensaje de error en caso contrario.
  
  static int listDevs(); //Obtiene la lista de Interfaces disponibles. Sus nombres se almacenan en la matriz statica devNames en donde cada fila es un nombre de tamaño MAX_NAME_LENGTH. Retorna la cantidad de interfaces encontradas.
  
  static const int MAX_DEVS=5;
  static const int MAX_NAME_LENGTH=11;
  static char devNames[MAX_DEVS][MAX_NAME_LENGTH];//Ojo con esto, no usarlo sin llamar antes a listDevs y verificar el número de dispositivos encontrados

  const char * dataToFile(const char *);//Recibe como argumento el nombre del archivo en el cual se desea almacenar las capturas. NOTA: en el archivo se almacenan los datos junto con otra estructura propia de pcap. Por defecto los datos son almacenados en un archivo cuyo nombre es el valor de retorno del método getTempFileName();
  
  const char * start();//Comienza una captura con los parametros definidos anteriormente. Return NULL si OK, mensaje de Error en char * de lo contrario.
  
  const char * getTempFileName() const; //Retorna el nombre del archivo donde se almacenan las capturas.desig
  
void stop();//Detiene la captura de paquetes.
 
   
private:
    
  struct pcap_pkthdr header;
  pcap_t * handle;
  const char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  int PROMS_MODE;
  bpf_u_int32 mask;		/* The netmask of our sniffing device */
  bpf_u_int32 net;		/* The IP of our sniffing device */
  struct bpf_program lastFilter;
  const char  * tempOutFile;
  pcap_dumper_t * handleDumper;

};







#endif
