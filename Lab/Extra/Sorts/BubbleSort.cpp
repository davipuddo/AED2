#include <iostream>

void Bubble (int* array, int n)
{
	int size = n-1;	// Otimization
	for (int i = 0; i < n; i++)
	{
		int o = 0;						
		for (int y = 0; y < size; y++)
		{
			int bY = y+1; // Otimization
			if (array[bY] < array[y])
			{
				int tmp = array[y];
				array[y] = array[bY];
				array[bY] = tmp;
				o++;
			}
		}

		if (o == 0)	// Otimization
		{
			i = n;
		}
	}
}

int main (void)
{
	// Variables
	int n = 0;
	int* array = nullptr;

	// Read array size
	std::cin >> n;
	
	// Init array
	array = new int[n];

	// Read array values
	for (int i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}

	// Sort array
	Bubble (array, n);

	// Print array
	for (int i = 0; i < n; i++)
	{
		std::cout << "[" << array[i] << "]";
	}
	std::cout << "\n";

	return (0);
}
