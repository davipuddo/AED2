#include "../util.h"

void inter (int* array, int L, int mid, int R)
{
	// Definir tamanho dos vetores auxiliares
	int nL = (mid+1)-L;
	int nR = (R-mid);

	// Criar vetorer
	int arrayL [nL+1];
	int arrayR [nR+1];

	// Definir dados
	int iL = 0;
	int iR = 0;
	int i = 0;

	arrayL[nL] = arrayR[nR] = INT_MAX;

	// Copiar dados do vetor original
	for (iL = 0; iL < nL; iL++)			// Esquerda
	{
		arrayL[iL] = array[L+iL];
	}

	for (iR = 0; iR < nR; iR++)			// Direita
	{
		arrayR[iR] = array[mid+1+iR];
	}

	// Juntar vetores
	for (iL = iR = 0, i = L; i <= R; i++)
	{
		if (arrayL[iL] <= arrayR[iR])
		{
			array[i] = arrayL[iL];
			iL++;
		}
		else
		{
			array[i] = arrayR[iR];
			iR++;
		}
	}
}

void MergeSort (int* array, int L, int R)
{
	if (L < R)
	{
		// Definir meio
		int mid = (int)((double)(L+R)/2.0);

		// Dividir vetor
		MergeSort (array, L, mid);
		MergeSort (array, mid+1, R);

		// Intercalar vetor
		inter (array, L, mid, R);
	}
}

// Encapsular metodo
void merge (int* array, int n)
{
	if (array && n > 0)
	{
		MergeSort (array, 0, n-1);
	}
}

int main (void)
{
	// Definir dados
	int* data = NULL;
	int n = 0;

	// Ler tamanho
	n = readInt();

	// Inicializar array
	data = (int*)malloc(n*sizeof(int));

	// Ler valores do array
	writeA (data, n);
	
	// Sort
	merge (data, n);

	// Mostrar resultado
	printA (data, n);

	return (0);
}
