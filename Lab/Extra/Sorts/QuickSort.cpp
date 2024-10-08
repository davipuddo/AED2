// 853355 Davi Puddo

#include "../util.h"
#include <iostream>

void QuickSort (int* data, int L, int R)
{
	int tmp = (int)((double)(L+R)/2.0);
	int pivo = data[tmp];

	int i = L;
	int y = R;

	while (i <= y)
	{
		// Find wrong number at the left
		while (data[i] < pivo)
		{
			i++;
		}

		// Find wrong number at the righ
		while (data[y] > pivo)
		{
			y--;
		}

		// Swap them
		if (i <= y)
		{
			swap (data, i, y);
			i++;
			y--;
		}
	}
	
	// Sort sides
	if (L < y)
	{
		QuickSort (data, L, y);
	}
	if (i < R)
	{
		QuickSort (data, i, R);
	}
}

int main (void)
{
	// Variables
	int* data = nullptr;
	int n = 0;

	// Read array size
	n = ReadInt();

	if (n > 0)
	{	
		// Init array
		data = new int[n];

		if (data)
		{
			// Fill array
			writeA (data, n);
			
			// Sort array
			QuickSort (data, 0, n-1);

			// Show result
			printA (data, n);
		}
	}
	return (0);
}
