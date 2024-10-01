#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int ReadInt ()
{
	int result = 0;
	scanf (" %d", &result);
	getchar();
	return (result);
}

void printA (int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("[%d]", array[i]);
	}
	printf ("\n");
}

int* writeA (int* array, int n)
{	
	for (int i = 0; i < n; i++)
	{
		array[i] = ReadInt();
	}
	return (array);
}

int* swap (int* array, int x, int y)
{
	if (array)
	{
		int tmp  = array[x];
		array[x] = array[y];
		array[y] = tmp;
	}
	return (array);
}
