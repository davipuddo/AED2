#include "../util.h"

// Construir heap
void construct (int* array, int size)
{
	for (int i = size; i > 1 && array[i] > array[(int)(i/2.0)]; i /= 2.0)
	{
		swap (array, i, i/2.0);
	}
}

// Encontrar maior filho
int getBiggestSon (int* array, int i, int size)
{
	int result = 0;
	int I = 2*i;
	if (I == size || array[I] > array[(I)+1])
	{
		result = I;
	}
	else
	{
		result = (I)+1;
	}
	return (result);
}

void reconstruct (int* array, int size)
{
	int i = 1;
	while (i <= (int)(size/2.0))
	{
		int son = getBiggestSon (array, i, size);
		if (array[i] < array[son])
		{
			swap (array, i, son);
			i = son;
		}
		else
		{
			i = size;
		}
	}
}

void HeapSort (int* array, int n)
{
	// Vetor auxiliar
	int tmp[n+1];
	tmp[0] = 0;
	
	// "Mover" dados para a direita
	for (int i = 0; i < n; i++)
	{
		tmp[i+1] = array[i];
	}

	// Construir heap
	for (int size = 2; size <= n; size++)
	{
		construct (tmp, size);
	}

	int size = n;
	while (size > 1)
	{
		swap (tmp, 1, size);
		size = size - 1;
		reconstruct (tmp, size);
	}

	// "Mover" dados para a esquerda
	for (int i = 0; i < n; i++)
	{
		array[i] = tmp[i+1];
	}
}

int main (void)
{
	int n = 0;
	int* array = NULL;

	n = readInt();

	array = (int*)malloc(n*sizeof(int));

	writeA (array, n);

	HeapSort (array, n);

	printA (array, n);

	return (0);
}
