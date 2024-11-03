#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <limits.h>

void println (char* x)
{
	printf ("%s\n", x);
}

int readInt ()
{
	int result = 0;
	scanf (" %d", &result);
	getchar();
	return (result);
}

char* readLine ()
{
	char* result = (char*)calloc(300,sizeof(char));
	scanf (" %300[^\n]", result);
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
		array[i] = readInt();
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
