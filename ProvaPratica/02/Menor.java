import java.util.Scanner;

class Cell
{
	public int data;
	public Cell link;

	public Cell(int x)
	{
		this.data = x;
		this.link = null;
	}
}

class Stack
{
	private Cell top;

	public Stack ()
	{
		top = null;
	}

	public void insert (int x)
	{
		if (top == null)
		{
			top = new Cell(x);
		}
		else
		{
			Cell tmp = new Cell(x);
			if (tmp != null)
			{
				tmp.link = top;
				top = tmp;
			}
		}
	}

	public void remove ()
	{
		if (top != null)
		{
			Cell tmp = top;
			top = top.link;
			tmp = null;
		}
	}

	public void print ()
	{
		Cell ptr = top;
		System.out.println (top.data); 

		while (ptr.link != null)
		{
			ptr = ptr.link;
			System.out.println (ptr.data); 
		}
	}

	public void smallest ()
	{
		if (top != null)
		{
			Cell ptr = top;
			int sm = ptr.data;
			
			while (ptr.link != null)
			{
				ptr = ptr.link;
				if (ptr.data < sm)
				{
					sm = ptr.data;
				}
			}
			System.out.println (sm);
		}
	}

	public void printTop ()
	{
		if (top != null)
		{
			System.out.println (top.data);
		}
	}
}

public class Menor 
{
	public static void main(String[] args)
	{	
		Scanner sc = new Scanner(System.in);
		Stack pilha = new Stack();
		String line = "";
		int n = 0;
		int i = 0;

		n = sc.nextInt();

		while (i < n+1)
		{
			line = sc.nextLine();
			String[] bk = line.split(" ");

			if (bk.length == 2)
			{
				int x = Integer.parseInt(bk[1]);
				pilha.insert(x);
			}
			else if (line.equals("POP"))
			{
				pilha.remove();
			}
			else if (line.equals("MIN"))
			{
				pilha.smallest();
			}
			else
			{
			}
			i++;
		}
	}
}
