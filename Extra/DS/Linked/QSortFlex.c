#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct cell_s
{
	int data;
	struct cell_s* front;
	struct cell_s* back;
}
Cell;

Cell* newCell (int x)
{
	Cell* this = (Cell*)malloc(sizeof(Cell));

	if (this)
	{
		this->data = x;
		this->front = NULL;
		this->back = NULL;
	}
	return (this);
}

typedef struct queue_s
{
	Cell* head;
	Cell* tail;
}
Queue;

Queue* newQueue ()
{
	Queue* this = (Queue*)malloc(sizeof(Queue));

	if (this)
	{
		this->head = NULL;
		this->tail = NULL;
	}
	return (this);
}

void insert (Queue* queue, int x)
{
	if (queue)
	{
		if (!queue->head)
		{
			queue->head = newCell(x);
			queue->tail = queue->head;
		}
		else
		{
			Cell* tmp = newCell(x);
			queue->tail->front = tmp;
			tmp->back = queue->tail;
			queue->tail = tmp;
		}
	}
}

void rm (Queue* queue)
{
	if (queue && queue->head)
	{	
		Cell* tmp = queue->head;
		queue->head = queue->head->front;
		free (tmp);
	}
}

void printR (Cell* ptr)
{
	printf ("[%d] ", ptr->data);
	if (ptr->front)
	{
		printR(ptr->front);
	}
}

void print (Queue* queue)
{
	if (queue && queue->head)
	{
		printR(queue->head);
		printf ("\n\n");
	}
}

int size (Queue* q)
{
	int res = 0;
	if (q && q->head)
	{	
		Cell* ptr = q->head;
		res = 1;

		while (ptr->front)
		{
			ptr = ptr->front;
			res++;
		}
	}
	return (res);
}

Cell* atPos (Queue* q, int x)
{
	Cell* ptr = NULL;
	if (q && q->head)
	{
		ptr = q->head;
		for (int i = 0; ptr && i < x; i++, ptr = ptr->front);
	}
	return (ptr);
}

void swap (Queue* q, int px, int py)
{
	if (q)
	{
		Cell* x = atPos(q, px);
		Cell* y = atPos(q, py);

		if (x && y)
		{
			int tmp = x->data;
			x->data = y->data;
			y->data = tmp;
		}
	}
}

void qs (Queue* q, int L, int R)
{
	int tmp = (int)((L+R)/2.0);
	int pivo = atPos(q, tmp)->data;
	int i = L;
	int y = R;
	
	while (i <= y)
	{
		while (atPos(q, i)->data < pivo)
		{
			i++;
		}

		while (atPos(q, y)->data > pivo)
		{
			y--;
		}

		if (i <= y)
		{
			swap (q, i, y);
			i++;
			y--;
		}
	}

	if (i < R)
	{
		qs (q, i, R);
	}
	if (y > L)
	{
		qs (q, L, y);
	}
}

void QuickSort (Queue* q)
{
	if (q && q->head && q->tail)
	{
		qs (q, 0, size(q)-1);
	}
}

int main (void)
{
	Queue* queue = newQueue();
	int x = 0;
	bool stop = false;

	while (stop == false)
	{
		scanf (" %d", &x);

		if (x == -1)
		{
			stop = true;
		}
		else
		{
			insert(queue, x);
		}
	}

	print(queue);

	QuickSort(queue);

	print(queue);
	
	return (0);
}
