// 853355 Davi Puddo

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

char* Rando (char* data, char* result, int i)
{
	if (data && result)
	{
		char x = (char)('a' + (rand() % 26));
		char y = (char)('a' + (rand() % 26));

		if (data[i] == x)
		{
			result[i] = y;
		}
		else
		{
			result[i] = data[i];
		}
		if (i < strlen(data)-1)
		{
			result = Rando (data, result, i+1);
		}
	}
	return (result);
}

char* Rand (char* data)
{
	char* result = NULL;
	if (data)
	{
		result = (char*)calloc(301, sizeof(char));
		if (result)
		{
			result = Rando(data, result, 0);
		}	
	}
	return (result);
}

int main (void)
{
	// Definir seed
	srand(12344321);

	// Definir dados
	char* data = NULL;
	char* result = NULL;
	bool stop = false;

	// Alocar espaco para string
	data = (char*)calloc(300, sizeof(char));

	while (stop == false)
	{
		// Ler dados
		scanf (" %300[^\n]", data);
		
		// Condicao de parada
		if (data && strcmp(data, "FIM") == 0)
		{
			stop = true;
		}
		else
		{
			// Aleatorizar 
			result = Rand (data);

			// Mostrar resultado
			printf ("%s\n", result);
		}
	}

	return (0);
}
