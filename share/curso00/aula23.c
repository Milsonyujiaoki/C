#include <stdio.h>
#include <stdlib.h> // Necessário para rand(), srand(), malloc() e free()
#include <time.h>   // Necessário para time()

int	main(void)
{
	size_t	i;
	int		seed;
	size_t	buff;
	int		*vetor;

	printf("Insira o tamanho do vetor: ");
	buff = 0;
	if (scanf("%zu", &buff) != 1)
	{
		printf("Erro ao ler o número.\n");
		return (1);
	}
	vetor = (int *)malloc(sizeof(int) * buff);
	if (vetor == NULL)
	{
		printf("Erro de alocação de memória.\n");
		return (1);
	}
	printf("O número de itens no vetor será: %zu\n", buff);
	printf("Insira uma chave para gerar os números: ");
	seed = 0;
	if (scanf("%i", &seed) != 1)
	{
		free(vetor);
		return (1);
	}
	srand((int)seed);
	i = 0;
	while (i < buff)
	{
		vetor[i] = (rand() % 100) + 1;
		i++;
	}
	i = 0;
	while (i < buff)
	{
		printf("Posicao %zu: valor = %i | Endereco = %p\n", i, vetor[i],
			(void *)&vetor[i]);
		i++;
	}
	free(vetor);
	return (0);
}
