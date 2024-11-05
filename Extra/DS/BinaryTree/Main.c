#include <stdio.h>
#include <stlib.h>

typedef struct Cell_s
{
	int data;
	struct Cell_s* L;
	struct Cell_s* R;
}
Cell;

Cell* newCell(int x)
{
	Cell* this = (Cell*)malloc(sizeof(Cell));
	if (this)
	{
		this->data = x;
		this->L = NULL;
		this->R = NULL;
	}
	return (this);
}

typedef struct Tree_s
{
	Cell* root;
}
Tree;

Tree* newTree()
{
	Tree* this = (Tree*)malloc(sizeof(Tree));
	if (this)
	{
		this->root = NULL;
	}
}

void insert (Tree* root, int x)
{
	if (root)
	{

	}
}
