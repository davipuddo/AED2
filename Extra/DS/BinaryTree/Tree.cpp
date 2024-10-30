#include "Cell.hpp"

void println (const char* x)
{
	if (x)
	{
		std::cout << x << std::endl;
	}
}

class Tree
{
	public:
	Cell* raiz;

	Tree()
	{
		raiz = nullptr;
	}

    void insertP (int x, Cell* ptr)
	{
		if (!ptr)
		{
			ptr = new Cell(x);
			std::cout << ptr->data << std::endl;
		}
		else if (ptr->data > x)
		{
			insertP (x, ptr->L);
		}
		else if (ptr->data < x)
		{
			insertP (x, ptr->R);
		}
	}

	void insert (int x)
	{
		insertP(x, raiz);
	}

	bool searchP (int x, Cell* ptr)
	{
		bool res = false;
		if (ptr)
		{
			if (ptr->data == x)
			{
				res = true;
			}
			else if (ptr->data > x)
			{
				res = searchP (x, ptr->L);
			}
			else
			{
				res = searchP (x, ptr->R);
			}
		}
		return (res);
	}

	bool search (int x)
	{
		return (searchP (x, raiz));
	}


	void print (Cell* ptr)
	{
		if (ptr)
		{
			print(ptr->L);
			print(ptr->R);
			std::cout << ptr->data << std::endl;
		}
	}

};

int main (void)
{
	Cell* c = new Cell(2);
	Tree* tr = new Tree();
	tr->insert(1);

	if (tr)
	{
		if (tr->raiz)
		{
			std::cout << "teste\n";
		}
		else
		{
			println ("raiz!");
		}
	}
	std::cout << c->data << std::endl;

	return(0);
}
