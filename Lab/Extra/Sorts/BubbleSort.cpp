#include <iostream>

int* Bubble (int* array, int n)
{
	int c = 0;
	int size = n-1;
	for (int i = 0; i < n; i++)
	{
		int o = 0;
		for (int y = 0; y < size; y++)
		{
			if (array[y+1] < array[y])
			{
				int tmp = array[y];
				array[y] = array[y+1];
				array[y+1] = tmp;
				o++;
			}
			c++;
		}
		if (o == 0)
		{
			i = n;
		}
	}
	std::cout << "c: " << c << "\n";
	return (array);
}

int main (void)
{
	int n = 0;
	int* array = nullptr;

	std::cin >> n;
	
	array = new int[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}

	array = Bubble (array, n);

	for (int i = 0; i < n; i++)
	{
		std::cout << "[" << array[i] << "]";
	}
	std::cout << "\n";

	return (0);
}
