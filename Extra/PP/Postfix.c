#include "Stack.h"

bool isNum(char x)
{
	bool res = false;
	if (x >= '0' && x <= '9')
	{
		res = true;
	}
	return (res);
}

bool isOp (char x)
{
	bool res = false;
	if (x == '*' || x == '+' || x == '-' || x == '/')
	{
		res = true;
	}
	return (res);
}

int prio (char x)
{
	int res = 0;

	if (x == '+' || x == '-')
	{
		res = 1;
	}
	else if (x == '/' || x == '*')
	{
		res = 2;
	}
	return (res);
}

char* toPostFix (char* exp)
{
	char* res = NULL;
	Stack* st = NULL;

	if (exp)
	{
		int size = (int)strlen(exp);
		res = (char*)calloc(size+1, sizeof(char));
		st = newStack();

		if (st)
		{
			int y = 0;
			for (int i = 0; i < size; i++)
			{
				char c = exp[i];

				if (!isOp(c))
				{
					res[y] = c;
					y++;
				}
				else
				{
					while (st->head && (prio(st->head->data) >= prio(c)))
					{
						res[y] = rmv(st);
						y++;
					}
					insert(st, c);
				}
			}
			while (st->head)
			{
				res[y] = rmv(st);
				y++;
			}
		}
	}
	return (res);
}


int CalcPF (char* exp)
{
	int res = 0;
	Stack* st = NULL;

	if (exp)
	{
		st = newStack();

		if (st)
		{
			int size = strlen(exp);
			for (int i = 0; i < size; i++)
			{
				char tmp = exp[i];
				int c = (int)(tmp - '0');
				int aux = 0;

				if (isNum(tmp))
				{
					inserTI(st, c);
				}
				else
				{
					int op1 = rmVI(st);
					int op2 = rmVI(st);

					if (tmp == '+')
					{
						aux = (op1 + op2);
					}
					else if (tmp == '-')
					{
						aux = (op2 - op1);
					}
					else if (tmp == '*')
					{
						aux = (op1 * op2);
					}
					else if (tmp == '/')
					{
						aux = ((int)((double)op1 / (double)op2));
					}
					inserTI(st, aux);
				}
			}
			res = (int)st->head->dx;
		}
	}
	return (res);
}

int main (void)
{
	char* exp = NULL;
	char* pos = NULL;
	int res = 0;

	exp = readLine();
	printf ("exp: %s\n\n", exp);

	pos = toPostFix(exp);
	printf ("pos: %s\n\n", pos);

	res = CalcPF(pos);
	printf ("res: %d\n\n", res);

	return (0);
}
