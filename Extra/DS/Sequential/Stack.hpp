#include "List.hpp"

class Stack
{
	private:
	List data;

	public:

	// Empty constructor
	Stack ()
	{
		data.alloc(8);
	}

	// Constructor with parameters
	Stack (int size)
	{
		if (size > 0)
		{
			data.alloc(size);
		}
		else
		{
			std::cerr << "ERROR: Invalid size for constructor!\n";
		}
	}

	// Add elements to the stack
	void add (int value)
	{
		int len = data.getLength();
		if (len > 0 && len > data.getNum())
		{
			data.insert(value, 0);
		}
		else
		{
			std::cerr << "ERROR: Stack is full!\n";
		}
	}
	
	// Remove first element of the stack
	void remove ()
	{
		if (data.getNum() > 0)
		{
			data.remove(0);
		}
	}

	// Return value at the given index
	int get (int pos)
	{
		int result = 0;
		if (pos < data.getNum())
		{
			result = data.get(pos);
		}
		return (result);
	}

	// Print the whole stack
	void print ()
	{
		data.print();
	}

	void free ()
	{
		this->data.free();
	}

};
