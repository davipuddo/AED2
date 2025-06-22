#include "util.h"

void isort (int* data, int n, int seed, int step)
{
	for (int i = seed+step; i < n; i+=step)
	{
		int tmp = data[i];
		int y = i-step;

		while (y >= 0 && data[y] > tmp)
		{
			data[y+step] = data[y];
			y -= step;
		}
		data[y+step] = tmp;
	}
}

void sort (int* data, int n)
{
	int h = 1;
	do
	{
		h = (3*h)+1;
	} while (h < n);

	do
	{
		h /= 3;

		for (int i = 0; i < n; i++)
		{
			isort (data, n, i, h);	
		}

	} while (h != 1);
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
