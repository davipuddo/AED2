#include "util.h"

int getMax (int* data, int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (data[i] > res)
		{	
			res = data[i];
		}
	}
	return (res);
}

void sort (int* data, int n)
{
	int max = getMax(data, n);

	int tmp [n];

	int aS = max+1;
	int aux[aS];

	for (int i = 0; i < aS; i++)
	{
		aux[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		int x = data[i];
		if (x >= 0)
		{
			aux[x]++;
		}
	}

	int buffer = 0;
	for (int i = 0; i < aS; i++)
	{
		buffer += aux[i];
		aux[i] = buffer;
	}

	for (int i = n-1; i > -1; i--)
	{
		int	x = aux[data[i]]--;
		tmp[x-1] = data[i];
	}

	for (int i = 0; i < n; i++)
	{
		data[i] = tmp[i];
	}
}

int main (void)
{
	int* data = NULL;
	int n = readInt();

	data = (int*)malloc(n*sizeof(int));

	writeA(data, n);

	sort (data, n);

	printA(data, n);

	return (0);
}
