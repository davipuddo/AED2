#include "Queue.hpp"

int main (void)
{
	// Create queue
	Queue data(5);

	// Add value to the queue
	data.add(3);
	data.print();

	// Add value to the queue
	data.add(5);
	data.print();

	// Remove value from the queue
	data.remove();
	data.print();

	// Delete queue
	//data.free();
	//data.print();

	return (0);
}
