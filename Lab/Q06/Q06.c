#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Elementos globais
static clock_t start, end;
static int* array;
static int n;

// Util

int readInt()
{
	int x = 0;
	scanf (" %d", &x);
	getchar();
	return (x);
}

void writeA()
{
	srand(time(NULL));
	if (array)
	{
		for (int i = 0; i < n; i++)
		{
			array[i] = rand();
		}
	}
}

void printA ()
{
	if (array)
	{
		for (int i = 0; i < n; i++)
		{
			printf ("[%d]", array[i]);
		}
		printf ("\n");
	}
}

void swap (int x, int y)
{
	int tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}

void TotalTime ()
{
	double time = ((double)(end-start)/CLOCKS_PER_SEC);
	printf ("%lfms\n",time);
}

// Sorts

void QuickSortMiddle (int L, int R)
{
	int buffer = (int)((L+R)/2.0);
	int pivo = array[buffer];
	int i = L;
	int y = R;

	while (i <= y)
	{
		while (array[i] < pivo)
		{
			i++;
		}
		while (array[y] > pivo)
		{
			y--;
		}
		if (i <= y)
		{
			swap (i, y);
			i++;
			y--;
		}
	}

	if (i < R)
	{
		QuickSortMiddle (i, R);
	}
	if (y > L)
	{
		QuickSortMiddle (L, y);
	}
}

int main (void)
{
	array = NULL;
	n = readInt();
	if (n > 0)
	{
		array = (int*)malloc(n*sizeof(int));

		if (array)
		{
			writeA ();
			start = clock();
			QuickSortMiddle (0, n-1);
			end = clock();
			TotalTime();
		}
	}

	return (0);
}
