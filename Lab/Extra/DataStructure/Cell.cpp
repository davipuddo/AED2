// 853355 Davi Puddo

#include <iostream>
#include <cstddef>

class Cell
{
	private:
	Cell* link = NULL;
	int value = 0;

	public:
	Cell()
	{
		link = NULL;
		value = 0;
	}

	Cell (Cell* l, int v)
	{
		this->link = l;
		this->value = v;
	}

	void set (int v)
	{
		this->value = v;
	}

	void get ()
	{
		std::cout << this->value;
	}
};

int main (void)
{
	Cell* ptr = new Cell(NULL, 1);
	ptr->get();
	return (0);
}
