// 853355 Davi Puddo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Combinar duas strigs
char* join (char* x, char* y)
{
	char* result = NULL;
	if (x && y)
	{
		// Tamanhos
		int sizeX = (int)strlen(x);
		int sizeY = (int)strlen(y);
		int sizeR = sizeX+sizeY;
		
		// Alocar espaco para o resultado
		result = (char*)calloc(sizeR+1, sizeof(char));

		if (result)
		{
			int ix = 0;	// Index de x
			int iy = 0;	// Index de y

			for (int i = 0; i < sizeR; i++)
			{
				if ( (i % 2 == 0 && ix < sizeX) || iy >= sizeY)
				{
					result[i] = x[ix];
					ix++;
				}
				else
				{
					result[i] = y[iy];
					iy++;
				}
			}
		}

	}
	return (result);
}

int main (void)
{
	// Definir dados
	char* x = (char*)calloc(80,sizeof(char));
	char* y = (char*)calloc(80,sizeof(char));
	char* result = NULL;

	// Ler dados	
	while (scanf("%s", x) != EOF)
	{
		scanf("%s", y);
		
		// Combinar valores
		result = join(x, y);
		
		// Mostrar resultado
		printf ("%s\n", result);
	}

	return (0);
}
