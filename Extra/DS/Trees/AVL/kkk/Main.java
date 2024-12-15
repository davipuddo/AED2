class Cell
{
	public int data;
	public Cell L;
	public Cell R;
	public int level;

	public Cell (int x)
	{
		this.data = x;
		this.L = null;
		this.R = null;
		this.level = 1;
	}

	public static int getLevel (Cell ptr)
	{
		int res = 0;
		if (ptr != null)
		{
			res = ptr.level;
		}
		return (res);
	}

	public void setLevel ()
	{
		int L = Cell.getLevel(this.L);
		int R = Cell.getLevel(this.R);
		this.level = Math.max(L, R) + 1;
	}
}

class AVL 
{
	private Cell root;

	public AVL ()
	{
		this.root = null;
	}

	public Cell rotL (Cell ptr)
	{
		Cell newRoot = ptr.R;
		Cell other = newRoot.L;

		newRoot.L = ptr;
		ptr.R = other;

		ptr.setLevel();
		newRoot.setLevel();
		return (newRoot);
	}

	public Cell rotR (Cell ptr)
	{
		Cell newRoot = ptr.L;
		Cell other = newRoot.R;

		newRoot.R = ptr;
		ptr.L = other;

		ptr.setLevel();
		newRoot.setLevel();
		return (newRoot);
	}

	public Cell balance (Cell ptr)
	{
		if (ptr != null)
		{
			int F = Cell.getLevel(ptr.R) - Cell.getLevel(ptr.L);

			if (F < 2)
			{
				ptr.setLevel();
			}
			else if (F == 2)
			{
				int F2 = Cell.getLevel(ptr.R.R) - Cell.getLevel(ptr.R.L);

				if (F2 == -1)
				{
					ptr.R = rotR (ptr.R);
				}
				ptr = rotL(ptr);
			}
			else if (F == -2)
			{	
				int F2 = Cell.getLevel(ptr.L.R) - Cell.getLevel(ptr.L.L);
				if (F2 == 1)
				{
					ptr.L = rotL (ptr.L);
				}
				ptr = rotR(ptr);
			}
			else
			{
				System.out.println ("ERRO");
				System.out.println ("F: "+F);
			}
		}
		return (ptr);
	}

	private Cell insert (Cell ptr, int x)
	{
		if (ptr == null)
		{
			ptr = new Cell(x);
		}
		else if (x < ptr.data)
		{
			ptr.L = insert(ptr.L, x);
		}
		else if (x > ptr.data)
		{
			ptr.R = insert(ptr.R, x);
		}
		return (balance(ptr));
	}

	public void insert (int x)
	{
		this.root = insert(this.root, x);
	}

	public void remove (int x)
	{
		this.root = remove(this.root, x);
	}

	private Cell remove (Cell ptr, int x)
	{
		if (ptr == null)
		{
			System.out.println ("ERRO");
		}
		else if (x < ptr.data)
		{
			ptr.L = remove(ptr.L, x);
		}
		else if (x > ptr.data)
		{
			ptr.R = remove(ptr.R, x);
		}
		else if (ptr.L == null)		// Se ptr.data == x
		{
			ptr = ptr.R;
		}
		else if (ptr.R == null)
		{
			ptr = ptr.L;
		}
		else 
		{
			ptr.L = bgL(ptr, ptr.L);
		}
		return (balance(ptr));
	}

	private Cell bgL (Cell x, Cell ptr)
	{
		if (ptr.R == null)
		{
			x.data = ptr.data;
			ptr = ptr.L;		// Deleta ptr
		}
		else 
		{
			ptr.R = bgL (x, ptr.R);
		}
		return (ptr);
	}	

	private void printC (Cell ptr)
	{
		if (ptr != null)
		{
			printC(ptr.L);
			System.out.println (ptr.data);
			printC(ptr.R);
		}
	}

	public void printC ()
	{
		printC(this.root);
		System.out.println ();
	}

	private void printPre (Cell ptr)
	{
		if (ptr != null)
		{
			System.out.println (ptr.data);
			printPre(ptr.L);
			printPre(ptr.R);
		}
	}

	public void printPre ()
	{
		printPre(this.root);
		System.out.println ();
	}
}

public class Main 
{
	public static void main(String[] args)
	{	
		AVL avl = new AVL();
		avl.insert(1);
		avl.insert(2);
		avl.insert(3);
		avl.printPre();
	}
}
