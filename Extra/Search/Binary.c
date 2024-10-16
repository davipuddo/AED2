#include "../util.h"

bool search (int* data, int L, int R, int x)
{
	bool res = 0;
	int mid = ((double)(R+L)/2.0);

	if (L > R)
	{
		res = false;
	}
	else if (data[mid] == x)
	{
		res = mid;
	}
	else if (data[mid] > x)
	{
		res = search (data, L, mid-1, x);
	}
	else
	{
		res = search (data, mid+1, R, x);
	}	
	return (res);
}

int main (void)
{
	int* data = NULL;
	int n = 0;
	int x = 0;

	n = readInt();
	
	if (n > 0)
	{
		data = (int*)malloc(n*sizeof(int));

		if (data)
		{
			writeA (data, n);
			
			printf ("x = ");
			x = readInt();

			int res = search (data, 0, n-1, x);
			printf ("res = %d\n", res);
		}
	}
	return (0);
}
