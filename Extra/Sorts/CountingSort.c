#include "../util.h"

int maxV (int* array, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

int* CountingSort (int* array, int n)
{
	int* res = NULL;
	if (array && n > 0)
	{
		res = (int*)malloc(n*sizeof(int));

		// Ler maior valor
		int max = maxV (array,n);

		// Criar vetor auxiliar e zerar valores
		int auxSize = (max+1);
		int* aux = (int*)malloc(auxSize*sizeof(int));	

		for (int i = 0; i < auxSize; i++)
		{
			aux[i] = 0;
		}

		// Contar valores
		for (int i = 0; i < n; i++)
		{
			int x = array[i];
			if (x >= 0)
			{
				aux[x]++;
			}
		}

		// Cumulativo
		int buffer = 0;
		for (int i = 0; i < auxSize; i++)
		{
			buffer += aux[i];
			aux[i] = buffer;
		}

		for (int i = n-1; i >= 0; i--)
		{
			int x = aux[array[i]];
			res[x-1] = array[i];
			aux[array[i]]--;
		}
	}
	return (res);
}

int main (void)
{
	// Variaveis
	int* array = NULL;
	int n = 0;

	// Ler entrada
	n = readInt();

	if (n > 0)
	{
		// Inicializar vetor
		array = (int*)malloc(n*sizeof(int));

		if (array)
		{
			// Ler entrada
			writeA (array, n);
			printA (array, n); // Printar array nao ordenado

			// Ordenar vetor
			array = CountingSort (array, n);	

			// Mostrar resultado
			printA (array, n);
		}
	}

	return (0);
}
