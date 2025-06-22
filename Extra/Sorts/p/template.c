#include "util.h"

void sort (int* data, int n)
{

}

int main (void)
{
	int* data = NULL;
	int n = readInt();

	data = (int*)malloc(n*sizeof(int));

	writeA(data, n);

	sort (data, n);

	printA(data, n);

	return (0);
}
