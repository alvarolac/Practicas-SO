#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>

int main(int argc, char **argv)
{

  if(argc<2)
  {
    printf("%s [puerto]\n",argv[0]);
    return 1;
  }
  
  int conexionServidor, conexionCliente, puerto; 

  socklen_t longCliente;
  struct sockaddr_in servidor, cliente;
  
  char buffer[200];
  
  puerto = atoi(argv[1]);
  
  /* 
  * Asignacion -> socket
  */   
  conexionServidor = socket(AF_INET, SOCK_STREAM, 0); 
  
  bzero((char *)&servidor, sizeof(servidor));
  
  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(puerto);
  servidor.sin_addr.s_addr = INADDR_ANY; //Macro -> Propia Direccion
  
  /* 
  * Asignacion -> socket a puerto
  */   
  if(bind(conexionServidor, (struct sockaddr *)&servidor, sizeof(servidor)) < 0)
  { 
    printf("Error\n");
    close(conexionServidor);
    return 1;
  }
  
  /* 
  * Escuchando ...
  */   
  listen(conexionServidor, 20);
  printf("Esperando, puerto: %d\n", ntohs(servidor.sin_port));
  
  longCliente = sizeof(cliente);
  
  /* 
  * Esperando por conexion ...
  */   
  conexionCliente = accept(conexionServidor, (struct sockaddr *)&cliente, &longCliente);
  if(conexionCliente<0)
  {
    printf("Error\n");
    close(conexionServidor);
    return 1;
  }
  
  printf("Conexion con -> %s:%d\n", inet_ntoa(cliente.sin_addr),htons(cliente.sin_port));

  if(recv(conexionCliente, buffer, 200, 0) < 0)
  { 
    printf("Error\n");
    close(conexionServidor);
    return 1;
  }
  else
  {
    printf("%s\n", buffer);
    bzero((char *)&buffer, sizeof(buffer));
    send(conexionCliente, "Recibido\n", 15, 0);
  }
  close(conexionServidor);

  return 0;
}

