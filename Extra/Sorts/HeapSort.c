#include "../util.h"

void construct (int* array, int size)
{
	for (int i = size; i > 1 && array[i] > array[(int)(i/2.0)]; i /= 2.0)
	{
		swap (array, i, i/2.0);
	}
}

int getBiggestSon (int* array, int i, int size)
{
	int result = 0;
	if (2*i == size || array[2*i] > array[(2*i)+1])
	{
		result = 2*i;
	}
	else
	{
		result = (2*i)+1;
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
	int tmp[n+1];
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
		swap (tmp, 1, size--);
		reconstruct (tmp, size);
	}

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
