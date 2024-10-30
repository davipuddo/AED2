#include "../util.h"

void InsertionSortKth (int* data, int n, int k)
{
	for (int i = 1; i < n; i++)
	{
		int tmp = data[i];
		int y = i-1;

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
	int n = 0;
	int k = 0;

	n = readInt();

	data = (int*)malloc(n*sizeof(int));

	writeA (data, n);

	k = readInt();

	InsertionSortKth (data, n, k);

	printA (data, n);

	return (0);
}
