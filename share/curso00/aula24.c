#include <stdio.h>
#include <stdlib.h> // Necessário para rand(), srand(), malloc() e free()
#include <time.h>   // Necessário para time()

int	main(void)
{
	size_t	i;
	size_t	j;
	int		seed;
	size_t	linhas;
	size_t	colunas;
	int		**matriz;

	printf("Insira o número de linhas da matriz: ");
	linhas = 0;
	if (scanf("%zu", &linhas) != 1)
		return (1);
	printf("Insira o número de colunas da matriz: ");
	colunas = 0;
	if (scanf("%zu", &colunas) != 1)
		return (1);
	matriz = (int **)malloc(sizeof(int *) * linhas);
	if (matriz == NULL)
		return (1);
	i = 0;
	while (i < linhas)
	{
		matriz[i] = (int *)malloc(sizeof(int) * colunas);
		if (matriz[i] == NULL)
		{
			while (i > 0)
				free(matriz[--i]);
			free(matriz);
			return (1);
		}
		i++;
	}
	printf("Insira uma chave para gerar os números: ");
	seed = 0;
	if (scanf("%i", &seed) != 1)
	{
		i = 0;
		while (i < linhas)
			free(matriz[i++]);
		free(matriz);
		return (1);
	}
	srand((int)seed);
	i = 0;
	while (i < linhas)
	{
		j = 0;
		while (j < colunas)
		{
			//matriz[i][j] = (rand() % 100) + 1;
			matriz[i][j] = rand() % 100;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < linhas)
	{
		j = 0;
		while (j < colunas)
		{
			printf("Linha %zu, Col %zu: valor = %i | Endereco = %p\n", i, j,
				matriz[i][j], (void *)&matriz[i][j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < linhas)
	{
		free(matriz[i]);
		i++;
	}
	
	free(matriz);
	return (0);
}
