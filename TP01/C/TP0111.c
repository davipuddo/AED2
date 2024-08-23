// 853355 Davi Puddo

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Descobrir se e um palindromo
bool palin (char* data, int i)
{
	bool result = false;
	if (data)
	{
		int size = strlen(data)-1;

		result = (data[i] == data[size-i]);

		if (i < (int)((double)size/2.0))
		{
			result = (result && palin (data, i+1));
		}
	}
	return (result);
}

int main (void)
{
	// Definir dados
	bool stop = false;
	bool result = false;
	char* data = NULL;

	// Alocar memoria para string
	data = (char*)calloc(400, sizeof(char));

	while (stop == false)
	{
		// Ler dados
		scanf (" %400[^\n]", data);
			
		if (strcmp(data, "FIM") == 0)
		{
			stop = true;
		}
		else
		{
			result = palin (data, 0);

			if (result)
			{
				printf ("SIM\n");
			}
			else
			{
				printf ("NAO\n");
			}
		}
	}

	return (0);
}
