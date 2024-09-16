// 853355 Davi Puddo

#include <iostream>
#include "util.h"

// Alternative InsertionSort
void InsertStep (int* data, int n, int color, int step)
{
	for (int i = (step+color); i < n; i+=step)
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

void ShellSort (int* data, int n)
{
	// Find step for array size
	int h = 1;
	do
	{
		h = (3*h)+1;
	} while (h < n);
		
	// Sort
	do
	{
		h /= 3;	// Go in inverse order

		for (int i = 0; i < h; i++)
		{
			InsertStep (data, n, i, h);
		}

	} while (h != 1);
}

int main (void)
{
	// Variables
	int* data = nullptr;
	int n = 0;

	// Read array size
	std::cin >> n;

	if (n > 0)
	{
		// Init array
		data = new int[n];

		if (data)
		{
			// Read array values
			for (int i = 0; i < n; i++)
			{
				int buffer = 0;
				std::cin >> buffer;
				data[i] = buffer;
			}

			// Sort array
			ShellSort (data, n);
			
			// Print array
			
			for (int i = 0; i < n; i++)
			{
				std::cout << "[" << data[i] << "]";
			}
			std::cout << '\n';
		}
	}

	return (0);
}
