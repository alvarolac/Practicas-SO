#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

int main(int argc, char **argv)
{

  if(argc<2)
  {
    printf("[host] [puerto]\n");
    return 1;
  }
  
  int puerto, conexion;
  char buffer[200];
  
  /* 
  * Estructura -> Informacion Conexion
  */  
  struct sockaddr_in cliente;
  
  /* 
  * Estructura -> Informacion Host
  */  
  struct hostent *servidor; 
  
  servidor = gethostbyname(argv[1]);
  puerto=(atoi(argv[2]));
  
  if(servidor == NULL)
  { 
    printf("Error\n");
    return 1;
  }
  
  /* 
  * Asignacion -> socket
  */ 
  conexion = socket(AF_INET, SOCK_STREAM, 0); //Asignación del socket

  /* 
  * Inicializacion -> 0 en todas las variables
  */  
  bzero((char *)&cliente, sizeof((char *)&cliente));
  
  cliente.sin_family = AF_INET;
  cliente.sin_port = htons(puerto);
  bcopy((char *)servidor->h_addr, (char *)&cliente.sin_addr.s_addr, sizeof(servidor->h_length));
 
  /* 
  * Estableciendo Conexion
  */
  if(connect(conexion,(struct sockaddr *)&cliente, sizeof(cliente)) < 0)
  { 
    printf("Error\n");
    close(conexion);
    return 1;
  }
  
  printf("Conexion con -> %s:%d\n", inet_ntoa(cliente.sin_addr),htons(cliente.sin_port));
  
  printf("Escribe un mensaje: ");
  fgets(buffer, 200, stdin);
  send(conexion, buffer, 200, 0);
  bzero(buffer, 200);
  recv(conexion, buffer, 200, 0);
  printf("%s", buffer);
  
  close(conexion);

  return 0;
}
