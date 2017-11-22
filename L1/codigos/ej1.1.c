#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 	FILE *archivo_in, *archivo_out;
 	char linea[500];
 	archivo_in = fopen("archivo.txt","r");
	archivo_out = fopen("archivo_out.txt","w");
	 	

 	if (archivo_in == NULL)
 	{
 		perror("Problemas reservando memoria");
		exit (1);
 	}
 	while (feof(archivo_in) == 0)
 	{
 		if(fgets(linea,500,archivo_in) != NULL)
 			fprintf(archivo_out,"%s",linea);
 	}

 	fclose(archivo_in);
	fclose(archivo_out);
	return 0;
}
