#include "../util.h"

void SelectionSortKth (int* data, int n, int k)
{
	for (int i = 0; i < k; i++)
	{
		int sm = i;
		for (int y = i+1; y < n; y++)
		{
			if (data[sm] > data[y])
			{
				sm = y;
			}
		}
		swap (data, i, sm);
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

	printf ("k=");
	k = readInt();

	SelectionSortKth (data, n, k);

	printA (data, n);
	return (0);
}
