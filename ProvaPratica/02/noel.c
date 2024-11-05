#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort (char** data, int n)
{
	int bad = 0;
	int good = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (data[i][0] == '+')
		{
			good++;
		}
		else
		{
			bad++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < n-1; y++)
		{	
			if (((int)data[y][2] > (int)data[y+1][2]) || ((int)data[y][2] == (int)data[y+1][2] && (int)data[y][3] > (int)data[y+1][3]))
			{
				char* tmp = data[y];
				data[y] = data[y+1];
				data[y+1] = tmp;
			}	
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < strlen(data[i])-3; y++)
		{
			printf ("%c", data[i][y+2]);
		}
		printf ("\n");
	}
	printf ("Se comportaram: %d | Nao se comportaram: %d\n", good, bad);
}

int main (void)
{
	int n = 0;
	char** data = NULL;

	scanf (" %d", &n);
	getchar();

	data = (char**)malloc(n*sizeof(char*));

	for (int i = 0; i < n; i++)
	{
		char* buffer = (char*)calloc(80, sizeof(char));
		scanf (" %80[^\n]", buffer);
		getchar();	

		data[i] = buffer;
	}

	sort(data, n);

	return (0);
}
