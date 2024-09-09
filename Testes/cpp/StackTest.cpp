#include "Stack.hpp"

int main (void)
{
	// Create stack
	Stack data(5);

	// Add value to the stack
	data.add(5);
	data.print();

	// Add value to the stack
	data.add(6);
	data.print();

	// Remove value from the stack
	data.remove();
	data.print();

	// Delete stack
	data.free();
	//data.print();

	return (0);
}
