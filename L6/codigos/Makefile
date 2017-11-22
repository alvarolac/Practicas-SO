all : Servidor Cliente

CPPFLAGS = -g -I.

Servidor : Servidor.c
	cc -g -I. Servidor.c -o Servidor

Cliente : Cliente.c
	cc -g -I. Cliente.c -o Cliente

clean :
	rm Cliente Servidor
