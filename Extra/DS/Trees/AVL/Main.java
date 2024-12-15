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
		int lvl = 0;
		int L = 0;
		int R = 0;

		L = Cell.getLevel (this.L);
		R = Cell.getLevel (this.R);

		lvl = (Math.max(L, R)) + 1;

		System.out.println ("newLvl: "+lvl);

		this.level = lvl;
	}
}

class Tree
{
	public Cell root;

	public Tree ()
	{
		this.root = null;
	}

	private Cell insert (Cell ptr, int x)
	{
		if (ptr == null)
		{
			ptr = new Cell(x);
		}
		else if (ptr.data > x)
		{
			ptr.L = insert(ptr.L, x);
		}
		else if (ptr.data < x)
		{
			ptr.R = insert(ptr.R, x);
		}
		else
		{
			System.out.println ("ERRO");
		}
		return (balance(ptr));
	}

	public void insert (int x)
	{
		this.root = insert(this.root, x);
	}

	public Cell balance (Cell ptr)
	{
		if (ptr != null)
		{
			int F = Cell.getLevel(ptr.R) - Cell.getLevel(ptr.L);
			System.out.println ("F: "+F);

			if (F < 2)
			{
				ptr.setLevel();
			}
			else if (F == 2)	// Rot L
			{
				int bg = Cell.getLevel(ptr.R.R) - Cell.getLevel(ptr.R.L);

				if (bg == -1)	// Rot R-L
				{
					ptr.R = rotR(ptr.R);
				}
				ptr = rotL(ptr);
			}
			else if (F == -2)	// Rot R
			{
				int bg = Cell.getLevel(ptr.L.R) - Cell.getLevel(ptr.L.L);

				if (bg == 1)	// Rot L-R
				{
					ptr.L = rotL(ptr.L);
				}
				ptr = rotR(ptr);
			}
			else
			{
				try
				{
					throw new Exception(":(");
				}
				catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		}
		return (ptr);
	}

	private Cell rotR (Cell ptr)
	{
		System.out.println ("rotR");
		Cell newRoot = ptr.L;
		Cell other = newRoot.R;

		newRoot.R = ptr;
		ptr.L = other;

		ptr.setLevel();
		newRoot.setLevel();
		return(newRoot);
	}	

	private Cell rotL (Cell ptr)
	{
		System.out.println ("rotL");
		Cell newRoot = ptr.R;
		Cell other = newRoot.L;

		newRoot.L = ptr;
		ptr.R = other;

		ptr.setLevel();
		newRoot.setLevel();
		return(newRoot);
	}

	public void print (Cell ptr)
	{
		if (ptr != null)
		{
			print(ptr.L);
			System.out.println (ptr.data);
			print(ptr.R);
		}
	}

	public void print ()
	{
		print(root);
	}

}

public class Main 
{
	public static void main (String[] args)
	{	
		Tree t = new Tree();
		t.insert(1);
		System.out.println ();
		t.insert(2);
		System.out.println ();
		t.insert(3);
		System.out.println ();
		t.print();

	}
}
