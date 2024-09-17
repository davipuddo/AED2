#include <iostream>

void Select (int* array, int n)
{
	int N = n-1;
	for (int i = 0; i < N; i++)
	{
		int sm = i;
		int y = i+1;
		while (y < n)
		{
			if (array[y] < array[sm])
			{
				sm = y;
			}
			y++;
		}
		int tmp = array[sm];
		array[sm] = array[i];
		array[i] = tmp;
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
	Select (array, n);

	// Print array
	for (int i = 0; i < n; i++)
	{
		std::cout << "[" << array[i] << "]";
	}
	std::cout << "\n";

	return (0);
}
