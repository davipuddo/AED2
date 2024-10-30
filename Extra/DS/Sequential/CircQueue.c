#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct CQueue_s
{
	int* data;
	int length;
	int front;
	int rear;
}
Queue;

Queue* newQueue (int x)
{
	Queue* res = NULL;
	if (x > 0)
	{
		res = (Queue*)malloc(sizeof(Queue));
		if (res)
		{
			res->data = (int*)malloc(x*sizeof(int));
			res->length = x;
			res->rear = -1;
			res->front = -1;
		}
	}
	return (res);
}

bool fullQueue (Queue* q)
{
	bool res = false;
	if (q && q->data)
	{
		if ((q->front == 0 && q->rear == q->length-1) || (q->front == q->rear + 1))
		{
			res = true;
		}
	}
	return (res);
}

int Remove (Queue* array)
{
	int res = 0;
	if (array)
	{
		// Guardar dado
		res = array->data[array->front];

		// Esvaziar fila
		if (array->rear == array->front)
		{
			array->front = -1;
			array->rear = -1;
		}
		else
		{
			// Ciclar
			array->front = (array->front+1) % array->length;
		}
	}
	return (res);
}

void insert (Queue* array, int x)
{
	if (array && array->data)
	{
		if (fullQueue(array))
		{
			printf ("Cheio!\n");
			Remove(array);
			printf ("f:%d\nr:%d\n", array->front, array->rear);
		}
		if (array->front == -1)
		{
			array->front = 0;
		}

		array->rear = (array->rear+1) % array->length;
		array->data[array->rear] = x;	
	}
}


void print (Queue* array)
{
	if (array)
	{
		if (array->front <= array->rear)
		{
			for (int i = array->front; i <= array->rear; i++)
			{
				printf ("{%d} ", array->data[i]);
			}
			printf ("\n");
		}
		else
		{
			for (int i = array->front; i < array->length; i++)
			{	
				printf ("[%d] ", array->data[i]);
			}

			for (int i = 0; i <= array->rear; i++)
			{
				printf ("[%d] ", array->data[i]);
			}
			printf ("\n");
		}
	}
}

void p (Queue* a)
{
	for (int i = 0; i < a->length; i++)
	{
		printf("[%d] ", a->data[i]);
	}
	printf ("\n");
}

int main (void)
{
	Queue* a = newQueue(5);

	insert(a, 1);
	insert(a, 2);
	printf ("(R) %d\n", Remove(a));
	insert(a, 3);
	insert(a, 4);
	insert(a, 5);
	insert(a, 6);
	insert(a, 7);

	print(a);
	p(a);

	return (0);
}
