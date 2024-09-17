// 853355 Davi Puddo

#include <stdio.h>
#include <stdlib.h>

int* Insert (int* array, int size)
{
	if (array && size > 0)
	{
		for (int i = 1; i < size; i++)
		{
			int tmp = array[i];
			int j = i-1;

			while (j >= 0 && array[j] > tmp)
			{
				array[j+1] = array[j];
				j--;
			}
			array[j+1] = tmp;
		}
	}
}

int main (void)
{
	// Define data
	int size = 0;
	int* data = NULL;

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
	Insert (data, size);

	// Show result
	if (data)
	{
		for (int i = 0; i < size; i++)
		{
			printf ("[%d]", data[i]);
		}
		printf ("\n");
	}
	return (0);
}


