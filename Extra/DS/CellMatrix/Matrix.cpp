#include "Cell.hpp"

void println (const char* line)
{
	if (line)
	{
		std::cout << line << std::endl;
	}
}

class Matrix
{
	public:

	Cell* head;
	Cell* start;
	int rows;
	int cols;
	int rn;
	int cn;

	void init (int r, int c)
	{
		if (r > 0 && c > 0)
		{
			this->head = nullptr;	
			this->start = nullptr;
			this->rows = r;
			this->cols = c;
			this->rn = 0;
			this->cn = 0;
		}
	}

	Matrix (int r, int c)
	{
		init(r, c);
	}

	Matrix ()
	{
		init(3, 3);
	}

	void insertRow (Cell* ptr, int x)
	{
		if (!ptr->R)
		{
			ptr->R = new Cell(x);
			ptr->R->L = ptr;
		}
		else if (ptr->R)
		{
			insertRow(ptr->R, x);
		}
	}

	void in (Cell* ptr, int x)
	{
		if (cn == 1 && ptr)
		{
			Cell* cursor = ptr;
			while (cursor->R)
			{
				cursor = cursor->R;
			}
			cursor->R = new Cell(x);
			rn++;
		}
		else if (cn > 1)
		{
			Cell* pU = ptr;
			Cell* pD = ptr->D;

			if (pD)
			{
				while (pD->R)
				{
					pD = pD->R;
				}

				while (pU->D)
				{
					pU = pU->R;
				}
			}

			pU->D = new Cell(x);
			pU->D->U = pU;
			pU->D->L = pD;

			rn++;
		}
	}

	void insertCol (Cell* cursor, int x)
	{
		Cell* pU = cursor;
		Cell* pD = cursor->D;

		if (pD)
		{
			while (pD->R != nullptr)
			{
				pD = pD->R;
			}
	
			while (pU->D != nullptr)
			{
				pU = pU->R;
			}
		}

		pU->D = new Cell(x);
		pU->D->U = pU;
		pU->D->L = pD;
	}

	void insert (int x)
	{
		if (!head)
		{
			head = new Cell(x);
			start = head;
			rn++;
			cn++;
		}
		else if (rn < rows)
		{
			insertRow (start, x);
			rn++;
		}
		else if (cn < cols)
		{
			insertCol (head, x);
			rn = 1;
			start = start->D;
			cn++;
		}
		else
		{
			println ("Matriz cheia");
		}
	}

	void ins (int x)
	{
		if (!head)
		{
			head = new Cell(x);
			start = head;
			rn++;
			cn++;
		}
		else
		{
			in(start, x);
		}
	}

	void printR (Cell* ptr)
	{
		if (ptr)
		{
			std::cout << "[" << ptr->data << "] ";

			if (ptr->R)
			{
				printR(ptr->R);
			}
		}
	}

	void printC (Cell* ptr)
	{
		if (ptr)
		{
			printR (ptr);
			std::cout << std::endl;

			if (ptr->D)
			{
				printC (ptr->D);
			}
		}
	}

	void print ()
	{
		printC (head);
	}

};

int main (void)
{
	Matrix* m = new Matrix();
	m->ins(0);
	m->ins(1);
	m->ins(2);
	m->ins(3);
	m->ins(4);
	m->ins(5);
	m->ins(6);
	m->ins(7);
	m->ins(8);
	
	m->print();

	std::cout << m->head->R->D->data << "\n";

	return (0);
}
