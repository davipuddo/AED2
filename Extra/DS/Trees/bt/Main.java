
class Cell
{
	public int data;
	public Cell L;
	public Cell R;

	public Cell (int x)
	{
		this.data = x;
		this.R = null;
		this.L = null;
	}

	public Cell ()
	{
		this(0);
	}
}

class Tree
{
	private Cell root;

	public Tree()
	{
		this.root = null;
	}

	private Cell insert(Cell ptr, int x)
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
			System.out.println ("Dados invalidos");
		}
		return (ptr);
	}

	public void insert(int x)
	{
		root = insert(root, x);
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
		if (this.root != null)
		{
			printC(this.root);
		}
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
		if (this.root != null)
		{
			printPre(this.root);
		}
	}

	private void printPos (Cell ptr)
	{
		if (ptr != null)
		{
			printPos(ptr.L);
			printPos(ptr.R);
			System.out.println (ptr.data);
		}
	}

	public void printPos ()
	{
		if (this.root != null)
		{
			printPos(this.root);
		}
	}

	private boolean search (Cell ptr, int x)
	{
		boolean res = false;
		if (ptr != null)
		{
			if (ptr.data == x)
			{
				res = true;
			}
			else if (ptr.data > x)
			{
				res = search(ptr.L, x);
			}
			else
			{
				res = search(ptr.R, x);
			}
		}
		return (res);
	}

	public boolean search (int x)
	{
		return (search(this.root, x));
	}

	private int height (Cell ptr)
	{
		int res = 0;
		if (ptr != null)
		{
			int hl = height(ptr.L);
			int hr = height(ptr.R);
			res = Math.max(hl, hr)+1;
		}
		return (res);
	}

	public int height ()
	{
		return(height(this.root));
	}
}

public class Main 
{
	public static void main(String[] args)
	{	
		Tree t = new Tree();

		t.insert(3);
		t.insert(2);
		t.insert(1);
		t.insert(4);
		t.insert(5);

		t.printC();
		System.out.println ("---");

		t.printPos();
		System.out.println ("---");

		t.printPre();
		System.out.println ("---");

		System.out.println (t.search(4));
		System.out.println ("---");

		System.out.println (t.height());
	}
}
