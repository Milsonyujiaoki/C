#include <stdio.h>
#include <stdlib.h> // Necessário para rand(), srand(), malloc() e free()
#include <time.h>   // Necessário para time()
#include <stdint.h> // OBRIGATÓRIO para usar uint16_t

int	main(void)
{
	size_t	i;
	size_t	j;
	int		seed;
	size_t	linhas;
	size_t	colunas;
	uint16_t **matriz; // Alterado de int** para uint16_t** (economiza 50% de memória)

	printf("Insira o número de linhas da matriz: ");
	linhas = 0;
	if (scanf("%zu", &linhas) != 1)
		return (1);
	printf("Insira o número de colunas da matriz: ");
	colunas = 0;
	if (scanf("%zu", &colunas) != 1)
		return (1);
        
	// Aloca o array de ponteiros para as linhas
	matriz = (uint16_t **)malloc(sizeof(uint16_t *) * linhas);
	if (matriz == NULL)
		return (1);
	i = 0;
	while (i < linhas)
	{
		// Aloca cada linha com o tamanho exato de uint16_t
		matriz[i] = (uint16_t *)malloc(sizeof(uint16_t) * colunas);
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
	srand((unsigned int)seed);
	i = 0;
	while (i < linhas)
	{
		j = 0;
		while (j < colunas)
		{
			// Gera números de 0 a 999
			matriz[i][j] = (uint16_t)(rand() % 1000);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < linhas) {
		j = 0;
		while (j < colunas) {
			// Alterado %i para %u (unsigned short/int)
			printf("Linha %zu, Col %zu: valor = %u | Endereco = %p\n", i, j,
				matriz[i][j], (void *)&matriz[i][j]);
			j++; 
		}
		i++;
	}

	// Exibição em formato de matriz real (grelha)
	printf("\n--- Matriz %zux%zu ---\n", linhas, colunas);
	i = 0;
	while (i < linhas)
	{
		j = 0;
		while (j < colunas)
		{
			printf("%3u ", matriz[i][j]);
			j++;
		}
		printf("\n"); 
		i++;
	}
	printf("---------------------\n\n");

	i = 0;
	while (i < linhas)
	{
		free(matriz[i]);
		i++;
	}
	
	free(matriz);
	return (0);
}
