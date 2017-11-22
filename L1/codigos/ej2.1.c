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
	int *vector;
  int i =0;
  vector = (int *) malloc(sizeof(int));
  
  if ( vector == NULL )
  {
    perror ( " Problemas reservando memoria " );
    exit (1);
  }
  
  for ( i =0; i <= NRO ; i ++)
  {
    vector[i] = i +500;
    vector = (int *)realloc(vector,(i+2)*sizeof(int));

    if ( vector == NULL)
    {
      perror ( " Problemas reservando memoria " );
      return(1);
    }
  }

  for ( i =0; i <= NRO ; i ++)
    vector[i] = vector[i] + 500;
  
  printf("Ultima pos: %d\n", vector[NRO]);
  
  free (vector);

  return 0;

}
