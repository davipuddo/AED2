#include <iostream>

class List
{
	// Class values
	private:
	int* data;
	int length;
	int n;

	public:
	
	// Constructor
	List ()
	{
		length = 8;
		n = 0;
		data = new int[length];
	}

	// Constructor with parameter
	List (int size)
	{
		if (size > 0)
		{
			length = size;
			n = 0;
			data = new int[length];
		}
	}

	void alloc (int size)
	{	
		if (size > 0)
		{
			length = size;
			n = 0;
			data = new int[length];
		}
	}
	
	int get (int pos)
	{
		int result = 0;
		if (n > pos)
		{
			result = data[pos];
		}
		else
		{
			std::cerr << "ERROR: Invalid index at get function!\n";
		}
		return (result);
	}

	// Return total array length 
	int getLength (void)
	{
		int result = 0;
		if (data != NULL)
		{
			result = this->length;
		}
		else
		{
			std::cerr << "ERROR: No values on the list!\n";		
		}
		return (result);
	}

	// Return number of values on the array
	int getNum (void)
	{
		int result = 0;
		if (data != NULL)
		{
			result = this->n;
		}
		else
		{
			std::cerr << "ERROR: No values on the list!\n";		
		}
		return (result);
	}

	// Insert a value at a given position
	void insert (int value, int pos)
	{
		if (pos > -1 && pos <= n)
		{
			if (n < length)
			{
				for (int i = n; i > pos; i--)
				{
					data[i] = data[i-1];
				}
				data[pos] = value;
				n++;
			}
			else
			{
				std::cerr << "ERROR: No elements on the list!\n";
			}
		}
		else
		{
			std::cerr << "ERROR: Invalid index at insert method!\n";
		}
	}

	// Remove value at a given position
	void remove (int pos)
	{
		if (pos > -1 && pos <= n)
		{
			if (n > 0)
			{
				int tmpN = n-1;
				for (int i = pos; i < tmpN; i++)
				{
					data[i] = data[i+1];
				}
				data[tmpN] = 0;	// Remove/hide trash
				n--;
			}
			else
			{
				std::cerr << "ERROR: No elements on the list!\n";
			}
		}
		else
		{
			std::cerr << "ERROR: Invalid index at remove method!\n";
		}
	}

	// Set n values at the list
	void write (int qnt)
	{
		if (qnt > 0)
		{
			int buffer = 0;
			for (int i = 0; i < qnt; i++)
			{
				std::cin >> buffer;
				this->insert(buffer, i);
			}
		}
		else
		{
			std::cerr << "Warning: Invalid number!\nNo alteration done\n";
		}
	}

	// Print full list
	void print ()
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << "[" << data[i] << "]";
		}
		std::cout << "\n";
	}

	void free ()
	{
		if (data != NULL)
		{
			delete (data);
		}
	}
};
