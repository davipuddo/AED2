// 853355 Davi Puddo

#include "../util.h"

bool Sequencial (int* data, int n, int x)
{
	bool result = false;
	if (data && n > 0)
	{
		int i = 0;
		while (i < n && data[i] != x)
		{
			i++;
		}
		if (i < n)
		{
			result = true;
		}
	}
	return (result);
}

int main (void)
{
	int* data = NULL;
	int n = 0;
	int x = 0;
	bool result = false;

	n = ReadInt();

	if (n > 0)
	{
		data = (int*)malloc(n*sizeof(int));

		if  (data)
		{
			writeA (data, n);
			
			println ("Search = ");
			x = ReadInt();

			result = Sequencial (data, n, x);

			if (result)
			{
				println ("SIM");
			}
			else
			{
				println ("NAO");
			}
	

		}
	}

	return (0);
}
