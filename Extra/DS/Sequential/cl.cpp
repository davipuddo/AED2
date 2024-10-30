#include <iostream>

// Circular list
class CList
{
	private:
	int* data;
	int length;
	int n;
	int first;
	int last;

	public:
	
	// Constructor with parameters
	CList (int size)
	{
		n = 0;
		first = 0;
		last = 0;
		length = 0;
		data = nullptr;

		if (size > 0)
		{
			length = size;
			data = new int[length];
		}
	}

	// Empty constructor
	CList ()
	{
		new (this) CList(0);
	}

	// Print whole list
	void print (void)
	{
		if (data != nullptr)
		{
			for (int i = first; i < last; i++)
			{
				std::cout << "[" << data[i] << "]";
			}
			std::cout << "\n";
		}
		else
		{
			std::cerr << "ERROR: List not initialized!\n";
		}
	}

	void insert (int value, int pos)
	{
		if (pos > -1 && n < length)
		{
			
		}
	}

};

int main (void)
{
	CList data;
	data.print();

	return (0);
}
