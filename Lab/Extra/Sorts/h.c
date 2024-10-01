#include "util.h"

void sort (int* array, int n)
{
	if (array && n > 0)
	{
		for (int i = 1; i < n && array[]i
	}
}

int main (void)
{
	int* data = NULL;
	int n = 0;

	n = ReadInt();

	if (n > 0)
	{
		data = (int*)malloc((n+1)*sizeof(int));

		if (data)
		{
			writeA (data, n);

			sort (data, n);

			printA (data, n);		
		}
	}
	return (0);
}
