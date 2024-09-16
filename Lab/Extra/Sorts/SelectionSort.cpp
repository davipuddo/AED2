#include <iostream>

int* Select (int* array, int n)
{
	int c = 0;
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
			c++;
		}
		int tmp = array[sm];
		array[sm] = array[i];
		array[i] = tmp;
	}

	std::cout << c << '\n';
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

	array = Select (array, n);

	for (int i = 0; i < n; i++)
	{
		std::cout << "[" << array[i] << "]";
	}
	std::cout << "\n";

	return (0);
}
