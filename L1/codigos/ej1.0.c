#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *archivo_in, *archivo_out;
	char caracter;
	
	archivo_in = fopen("archivo.txt","r");
	archivo_out = fopen("archivo_out.txt","w");
	
	if (archivo_in == NULL)
	{
		printf("\nError de apertura del archivo. \n\n");
	}
	else
    	{
				

    	    while (feof(archivo_in) == 0)
	    {
			caracter = fgetc(archivo_in);
			if(caracter != EOF)
				fprintf(archivo_out,"%c",caracter);
	    }
	}

    fclose(archivo_in);
    fclose(archivo_out);
	
	return 0;
}