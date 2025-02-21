#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int readInt (void)
{
	int tmp = 0;
	scanf (" %d", &tmp);
	getchar();
	return (tmp);
}

void writeA (int* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		data[i] = readInt();
	}
}

void printA (int* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("[%d]", data[i]);
	}
	printf("\n");
}

void swap (int* data, int x, int y)
{
	int tmp = data[x];
	data[x] = data[y];
	data[y] = tmp;
}
