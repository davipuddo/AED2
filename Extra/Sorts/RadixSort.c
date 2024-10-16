#include "../util.h"

int getMax (int* data, int n)
{
	int max = 0;
	if (data && n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (max < data[i])
			{
				max = data[i];
			}
		}
	}
	return (max);
}

void cSort (int* data, int n, int p)
{
	int res[n];
	int* aux = (int*)malloc(10*sizeof(int));

	for (int i = 0; i < 10; i++)
	{
		aux[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		int tmp = (int)((double)data[i]/(double)p) % 10;
		aux[tmp]++;
	}

	for (int i = 1; i < 10; i++)
	{
		aux[i] += aux[i-1];
	}

	for (int i = n-1; i >= 0; i--)
	{
		int tmp = (int)((double)data[i]/(double)p) % 10;
		res[aux[tmp]-1] = data[i];
		aux[tmp]--;
	}
	
	for (int i = 0; i < n; i++)
	{
		data[i] = res[i];
	}

}

void RadixSort (int* data, int n)
{
	int m = getMax (data, n);

	for (int p = 1; m / p > 0; p *= 10)
	{
		cSort (data, n, p);
	}
}

int main (void)
{
	int* data = NULL;
	int n = 0;

	n = readInt();

	data = (int*)malloc(n*sizeof(int));

	writeA (data, n);

	RadixSort (data, n);

	printA (data, n);

	return (0);
}
