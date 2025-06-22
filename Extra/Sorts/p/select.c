#include "util.h"

void sort (int* data, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int sm = i;
		for (int y = i+1; y < n; y++)
		{
			if (data[sm] > data[y])
			{
				sm = y;
			}
		}
		swap (data, sm, i);
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
