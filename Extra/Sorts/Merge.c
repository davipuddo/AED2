#include "../util.h"

void inter (int* array, int L, int mid, int R)
{
	int nL = (mid+1)-L;
	int nR = (R-mid);

	int* arrayL = (int*)malloc((nL+1)*sizeof(int));
	int* arrayR = (int*)malloc((nR+1)*sizeof(int));

	arrayL[nL] = arrayR[nR] = 0x7FFFFFFF; // INT_MAX

	int iL;
	int iR;
	int i;

	for (iL = 0; iL < nL; iL++)
	{
		arrayL[iL] = array[L+iL];
	}

	for (iR = 0; iR < nR; iR++)
	{
		arrayR[iR] = array[(mid+1)+iR];
	}

	for (iL = iR = 0, i = L; i <= R; i++)
	{
		array[i] = (arrayL[iL] <= arrayR[iR]) ? arrayL[iL++] : arrayR[iR++];
	}
}

void MergeSort (int* array, int L, int R)
{
	if (L < R)
	{
		int mid = (int)((double)(L+R)/2.0);
		MergeSort (array, L, mid);
		MergeSort (array, mid+1, R);
		inter (array, L, mid, R);
	}
}

// Encapsule
void merge (int* array, int n)
{
	if (array && n > 0)
	{
		MergeSort (array, 0, n-1);
	}
}

int main (void)
{
	// Variables
	int* data = NULL;
	int n = 0;

	// Read Size
	n = readInt();

	// init array
	data = (int*)malloc(n*sizeof(int));

	// Give values to array
	writeA (data, n);
	
	// Sort
	merge (data, n);

	// Show result
	printA (data, n);

	return (0);
}
