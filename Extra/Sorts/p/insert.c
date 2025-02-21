#include "util.h"

void sort (int* data, int n)
{
	for (int i = 1; i < n; i++)
	{
		int y = i-1;
		int tmp = data[i];
		while (y >= 0 && data[y] > tmp)
		{
			data[y+1] = data[y];
			y--;
		}
		data[y+1] = tmp;
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
