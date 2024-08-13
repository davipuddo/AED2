// 853355 Davi Puddo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Criptografar dados em cifra de cesar | Chave = 3
char* encode (char* data)
{
	char* result = NULL;
	if (data)
	{
		int size = strlen(data);
		result = calloc(size, sizeof(char));
		
		if (result)
		{
			for (int i = 0; i < size; i++)
			{
				result[i] = (data[i] + 3);
			}
			result[size-1] = '\0';
		}
	}
	return (result);
}

int main (void)
{
	// Definir dados
	char* data = NULL;
	char* result = NULL;
	bool stop = false;
	
	// Alocar espaco para a leitura
	data = calloc(400, sizeof(char));

	if (data)
	{
		while (stop == false)
		{
			// Ler dados
			fgets(data, 400, stdin);
			data[strlen(data)-1] = '\0';	// Remover \n

			result = encode(data);

			if (strcmp(data, "FIM") != 0)
			{
				// Mostrar dados
				int n = strlen(result);
				for (int i = 0; i < n; i++)
				{
					printf ("%c", result[i]);
				}
				printf ("\n");
			}
			else
			{
				stop = true;	// Condicao de parada
			}
		}
	}
	return (0);
}
