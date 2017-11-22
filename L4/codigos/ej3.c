#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <signal.h>
#include <errno.h>
#include "colamsg.h"

void exit_signal(int);

int main()
{
  system("clear");
  printf("\n_______________________  Sucesión de Fibonacci _______________________\n\n");
  
  key_t key_colamsg = ftok(ROUTE, ID);
  int id_colamsg;
  msg_data data;
  
  
  
  signal(2, exit_signal);
  
  if((id_colamsg = msgget(key_colamsg, 0)) != -1) 
    msgctl(id_colamsg, IPC_RMID, 0);
	
  if((id_colamsg = msgget(key_colamsg, IPC_CREAT | 0666)) == -1) 
  {
  	perror("msgget");
		exit(EXIT_FAILURE);
	}
	
	
  int anterior0 = 0;
	int anterior1 = 1;
	int actual = 0;
	int i=3;

	printf("Termino 1: %d\n",0);
	fflush(stdout);  
  data.id = 1;
  data.numero = 0; 
  if (msgsnd(id_colamsg, (void *)&data, sizeof(msg_data), 0) == -1) 
  {
	  perror("Envio fallido");
  }
 	sleep(1);
 	printf("Termino 2: %d\n",1);
 	fflush(stdout);  
 	data.id = 2;
  data.numero = 1; 
  if (msgsnd(id_colamsg, (struct msgbuf *)&data, sizeof(msg_data), 0) == -1) 
   perror("Envio fallido");
 	sleep(1);

	while(1)
 	{
  	actual = anterior0 + anterior1;
		printf("Termino %d: %d\n",i , actual);
		fflush(stdout);  
		anterior0=anterior1;
		anterior1=actual;
		i++;
  	if(actual%2  == 0)
		  data.id = 1;
		else
		  data.id = 2;
    data.numero = actual; 
    if (msgsnd(id_colamsg, (struct msgbuf *)&data, sizeof(msg_data), 0) == -1) 
      perror("Envio fallido");
    sleep(1);
 	}
 	
 	return 0; 
}

void exit_signal(int num_signal)
{

  sleep(2);
  key_t key_colamsg = ftok(ROUTE, ID);
  int id_colamsg;
  msg_data data;
  
	if((id_colamsg = msgget(key_colamsg, 0)) == -1) 
	{
	  perror("msgget");
	  exit(EXIT_FAILURE);  
	}
  if (msgrcv(id_colamsg, (struct msgbuf *)&data, sizeof(msg_data), (long)3, 0) == -1) 
  {
    perror("msgrcv");
    exit(EXIT_FAILURE);
  } 
  kill(data.numero, SIGINT);
  printf("id: %d, numero:%d\n",data.id, data.numero);

  sleep(1);

	if (msgrcv(id_colamsg, (struct msgbuf *)&data, sizeof(msg_data), (long)4, 0) == -1) 
  {
    perror("msgrcv");
    exit(EXIT_FAILURE);
  } 
  kill(data.numero, SIGINT);
  
  sleep(2);
  

  
	printf("\n\n\tHasta luego!\n");
	fflush(stdout);  
  exit(EXIT_SUCCESS); 
}
