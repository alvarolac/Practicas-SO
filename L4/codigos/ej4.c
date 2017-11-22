#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <errno.h>
#include <signal.h>
#include "colamsg.h"

void exit_signal(int);

int main(int argc, char *argv[])
{

  if(argc != 2 )
  {
    printf("\n\tCantidad incorrecta de parametros!\n");
    exit(EXIT_FAILURE);  
  }
   
  int tipo = atoi(argv[1]); 
   
  if(tipo != 1 && tipo != 2 )
  {
    printf("\n\tParametros incorrectos!\n");
    exit(EXIT_FAILURE);  
  }
  
  signal(2, exit_signal);
  
  key_t key_colamsg = ftok(ROUTE, ID);
  int id_colamsg;
  msg_data data;
  
	if((id_colamsg = msgget(key_colamsg, 0)) == -1) 
	{
	  perror("msgget");
	  exit(EXIT_FAILURE);  
	}

  data.id = (tipo+2);
  data.numero = getpid();
  if(msgsnd(id_colamsg, (struct msgbuf *)&data, sizeof(msg_data), 0) == -1) 
    perror("Envio fallido");

  printf("id: %d, numero:%d",data.id, data.numero);


  if(tipo == 1)
    printf("\t --> %d Terminos Pares: \n\n\t", getpid());
  else  
    printf("\t --> %d Terminos Impares: \n\n\t", getpid());
  fflush(stdout);  
    
  while(1)
  {
    if(tipo == 1)
    {
     
     if(msgrcv(id_colamsg, (struct msgbuf *)&data, sizeof(msg_data), (long)1, IPC_NOWAIT) == -1) 
     {
    //   perror("msgrcv");
    //   exit(EXIT_FAILURE);
     }else{ 
     printf(" %d - ", data.numero);
     fflush(stdout);
    }
    }
    else
    {
     if(msgrcv(id_colamsg, (struct msgbuf *)&data, sizeof(msg_data), (long)2, IPC_NOWAIT) == -1) 
     {
       //perror("msgrcv");
       //exit(EXIT_FAILURE);
     }else{ 
    
     printf(" %d - ", data.numero);
     fflush(stdout);
     }
    }
  
  } 
}

void exit_signal(int num_signal)
{
  printf("\n\n\tHasta luego!\n");
  fflush(stdout);  
  exit(EXIT_SUCCESS);  
}

