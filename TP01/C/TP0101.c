// 853355 Davi Puddo

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Descobrir se uma cadeia de caraceteres e um palindromo
bool pali (char* s, int n)
{
	bool result = false;
	if (s)
	{
		int i = 0;
		int y = n-1;
		int w = n;

		while (i < w && s[i] == s[y])
		{
			i++;
			y--;
		}
		if (i == w)
		{
			result = true;
		}
	}
	return (result);
}

int main ()
{
	// Definir dados
	char* data = calloc(5,sizeof(char));
	bool result = false;

	// Ler dados
	scanf ("%s", data);
	getchar();

	// Verificar se e palindromo
	result = pali(data, 5);

	// Mostrar dados
	printf ("%d\n", result);

	return (0);
}
