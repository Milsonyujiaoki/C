#include <stdio.h>
#include <stdlib.h> // Necessário para rand() e srand()
#include <time.h>   // Necessário para time()

#define BUFFER_LEN 24

int	main(void)
{
	int		vetor[BUFFER_LEN];
	size_t	i;

	srand((unsigned int)time(NULL));
	i = 0;
	while (i < BUFFER_LEN)
	{
		vetor[i] = (rand() % 100) + 1;
		i++;
	}
	i = 0;
	while (i < BUFFER_LEN)
	{
		printf("Posicao %zu: valor =  %i | Endereço = %p\n", i, vetor[i], (void*)&vetor[i]);
		i++;
	}
	return (0);
}
