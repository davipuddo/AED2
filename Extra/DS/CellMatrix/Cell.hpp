#include <iostream>

class Cell
{
	public:

	int data;
	Cell* U;
	Cell* D;
	Cell* L;
	Cell* R;
		
	void init (int x, Cell* Up, Cell* Down, Cell* Left, Cell* Right)
	{
		this->data = x;
		this->U = Up;
		this->D = Down;
		this->L = Left;
		this->R = Right;
	}

	Cell ()
	{
		init (-1, nullptr, nullptr, nullptr, nullptr);
	}

	Cell (int x)
	{
		init (x, nullptr, nullptr, nullptr, nullptr);
	}

	Cell (int x, Cell* Up, Cell* Dn, Cell* Lf, Cell* Rg)
	{
		init (x, Up, Dn, Lf, Rg);
	}

	~Cell ()
	{
		if (this->U != nullptr)
		{
			delete (this->U);
		}
		else if (this->D != nullptr)
		{
			delete (this->D);
		}
		else if (this->L != nullptr)
		{
			delete (this->L);
		}
		else if (this->R != nullptr)
		{
			delete (this->R);
		}
	}
};
