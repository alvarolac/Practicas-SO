/*---------------------------------------------
-- Universidad De Los Andes
-- Prof . Rodolfo Sumoza
-- Prep . Alvaro Araujo
-- Sistemas Operativos , A2017
---------------------------------------------*/

# include <stdio.h>
# include <stdlib.h>
# define NRO 100000000

int main ()
{
	int * vector ;
	vector = ( int *) malloc ( sizeof ( int )* NRO );
	if ( vector == NULL )
	{
		perror ( " Memoria Insuficiente " );
		exit (1);
	}

	int i =0;

	for ( i =0; i <= NRO ; i ++)
		vector [ i ] = i +500;

	for ( i =0; i <= NRO ; i ++)
		vector [ i ] = vector [ i ] + 500;

  printf("Ultima pos: %d\n", vector[NRO]);
  
  free(vector);

	return 0;
}
