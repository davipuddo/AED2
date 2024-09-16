// 853355 Davi Puddo

#include <stdio.h>
#include <stdlib.h>

int* Insert (int* array, int size)
{
	int* result = NULL;
	if (array)
	{
		// Alloc result array
		result = (int*)malloc(size*sizeof(int));

		if (result)
		{
			// Copy array
			for (int i = 0; i < size; i++)
			{
				result[i] = array[i];
			}
			
			// Sort
			for (int i = 1; i < size; i++)
			{

				int tmp = result[i];
				int j = i-1;
				while (j >= 0 && array[j] > tmp)
				{
					result[j+1] = result[j];
					j--;
				}
				result[j+1] = tmp;
			}
		}
	}
	return (result);
}

int main (void)
{
	// Define data
	int size = 0;
	int* data = NULL;
	int* result = NULL;

	// Read size of int array
	scanf("%d", &size);
	getchar();

	// Alloc array
	data = (int*)malloc(size*sizeof(int));

	// Write values for the array
	for (int i = 0; i < size; i++)
	{
		int tmp = 0;
		scanf ("%d", &tmp);
		getchar();
		data[i] = tmp;
	}
	
	// Sort array
	result = Insert (data, size);

	// Show result
	if (result)
	{
		for (int i = 0; i < size; i++)
		{
			printf ("[%d]", result[i]);
		}
		printf ("\n");
	}
	return (0);
}


