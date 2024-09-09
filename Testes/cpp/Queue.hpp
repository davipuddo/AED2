// 853355 Davi Puddo

#include "List.hpp"

class Queue
{
	private:
	List data;

	public:

	// Empty constructor
	Queue ()
	{
		data.alloc(8);
	}

	// Constructor with parameters
	Queue (int size)
	{
		if (size > 0)
		{
			data.alloc(size);
		}
		else
		{
			std::cerr << "ERROR: Invalid size at queue constructor!\n";
		}
	}

	// Add element to the queue
	void add (int value)
	{
		int len = data.getLength();
		if (len > 0 && len > data.getNum())
		{
			data.insert(value, 0);
		}
		else
		{
			std::cerr << "ERROR: The queue is full!\n";
		}
	}

	// Remove first element
	void remove (void)
	{
		if (data.getNum() > 0)
		{
			data.remove(data.getNum());
		}
		else
		{
			std::cerr << "ERROR: No elements in the queue!\n";
		}
	}

	// Return value at the given position
	int get (int pos)
	{
		int result = 0;
		if (data.getNum() > pos)
		{
			result = data.get(pos);
		}
		return (result);
	}
	
	// Print full queue
	void print ()
	{
		data.print();
	}

	void free ()
	{
		data.free();
	}

};
