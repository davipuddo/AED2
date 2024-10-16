#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Ler inteiro
int readInt()
{
	int x = 0;
	scanf (" %d", &x);
	getchar();
	return(x);
}

// Ler vetor
void writeA (int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = readInt();
	}
}

// Mostrar vetor
/*void printA (int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("%d ", array[i]);
	}
	printf ("\n");
}*/

void swap (int* array, int x, int y)
{
	int tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}

// Contar ultrapassagens
int countShift (int* end, int* start, int n)
{
	int res = 0;
	if (end && start && n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			int p1 = start[i];
			int p2 = end[i];

			// Se a posicao inicial for diferente da final
			if (p1 != p2)
			{
				int y = 0;
				// Encontrar posicao inicial
				while (y < n && start[y] != p2)
				{
					y++;
				}

				// Fazer shift
				while (y > i)
				{
					swap(start, y, y-1);
					y--;
					res++; // Contador
				}
			}
		}
	}
	return (res);
}

int main (void)
{
	// Dados locais
	int* end = NULL;
	int* start = NULL;
	int n = 0;
	int x = 0;

	// Ler entrada
	while (scanf (" %d", &n) != EOF)
	{
		getchar();
		
		// Inicializar vetores
		start = (int*)malloc(n*sizeof(int));
		end = (int*)malloc(n*sizeof(int));

		// Ler vetores
		writeA(start,n);
		writeA(end, n);

		// Contar ultrapassagens
		x = countShift (end, start, n);

		// Mostrar resultado
		printf ("%d\n", x);
	}

	return (0);
}
