#include "util.h"

void sort (int* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool sw = false;
		for (int y = 0; y < n-1; y++)
		{
			if (data[y] > data[y+1])
			{
				sw = true;
				swap(data, y, y+1);	
			}
		}
		if (!sw)
		{
			i = n;
		}
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
