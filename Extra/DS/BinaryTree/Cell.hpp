#include <iostream>

#define null nullptr

class Cell
{
	public:

	int data;
	Cell* L;
	Cell* R;

	Cell (int x)
	{
		data = x;
		L = nullptr;
		R = nullptr;
	}
};
