import java.util.Scanner;

class Cell
{
	public int data;
	public Cell U;
	public Cell D;
	public Cell L;
	public Cell R;

	public Cell (int x)
	{
		this.data = x;
		this.U = null;
		this.D = null;
		this.L = null;
		this.R = null;
	}

	public Cell ()
	{
		this(0);
	}

}

class Matrix
{
	public Cell top;
	public int n;

	public Matrix (int n)
	{
		if (n > 1)
		{
			this.top = newRow(n);

			Cell start = this.top;

			for (int i = 0; i < n; i++)
			{
				Cell New = newRow(n);
				Cell tmp = New;

				for (Cell y = start; y != null; y = y.R)
				{
					y.D = tmp;
					tmp.U = y;
					tmp = tmp.R;
				}

				start = start.D;
			}
			this.n = n;
		}
		else
		{
			System.out.println ("Tamanho invalido");
		}
	}

	public Cell newRow(int n)
	{
		Cell res = null;
		if (n > 1)
		{
			res = new Cell();
			Cell ptr = res;

			for (int i = 0; i < n-1; i++)
			{
				Cell tmp = new Cell();
				ptr.R = tmp;
				tmp.L = ptr;
				ptr = tmp;
			}
		}
		return (res);
	}

	public void insert (int x, int c, int r)
	{
		if (r > -1 && r < this.n && c > -1 && c < this.n)
		{
			Cell ptr = this.top;

			for (int i = 0; i < r; i++)
			{
				ptr = ptr.R;
			}

			for (int i = 0; i < c; i++)
			{
				ptr = ptr.D;
			}

			ptr.data = x;
		}
		else
		{
			System.out.println ("Posicao invalida");
			System.out.println ("n="+this.n);
			System.out.println ("r="+r+"\nc="+c);
		}
	}
	
	public void print ()
	{
		if (this.top != null)
		{
			Cell row = this.top;
			Cell ptr = row;
			
			for (int i = 0; i < this.n; i++)
			{
				for (int y = 0; y < this.n; y++)
				{
					System.out.print (ptr.data+" ");
					ptr = ptr.R;
				}
				System.out.println ("");

				row = row.D;
				ptr = row;
			}
		}
	}

	private void pMD (Cell ptr)
	{
		System.out.print (ptr.data+" ");

		if (ptr.R != null && ptr.R.D != null)
		{
			pMD(ptr.R.D);
		}
	}

	public void MainDiagonal()
	{
		if (this.top != null)
		{
			pMD(this.top);
			System.out.println ("");
		}
	}

	private void pSD (Cell ptr)
	{
		System.out.print (ptr.data+" ");
		if (ptr.L != null && ptr.L.D != null)
		{
			pSD(ptr.L.D);
		}
	}

	public void SecondaryDiagonal()
	{
		if (this.top != null)
		{
			Cell tmp = this.top;
			while (tmp.R != null)
			{
				tmp = tmp.R;
			}
			pSD(tmp);
			System.out.println ("");
		}
	}

	public int get (int c, int r)
	{
		int res = 0;
		if (this.top != null && r > -1 && r < this.n && c > -1 && c < this.n)
		{
			Cell ptr = this.top;

			for (int i = 0; i < r; i++)
			{
				ptr = ptr.R;
			}

			for (int i = 0; i < c; i++)
			{
				ptr = ptr.D;
			}

			res = ptr.data;
		}
		return (res);
	}

	public Matrix sum (Matrix other)
	{
		Matrix res = null;
		if (this.top != null && other.top != null)
		{
			if (this.n == other.n)
			{
				res = new Matrix(this.n);
				Cell r1 = this.top;
				Cell r2 = other.top;
				Cell c1 = r1;
				Cell c2 = r2;

				for (int i = 0; i < this.n; i++)
				{
					for (int y = 0; y < this.n; y++)
					{
						int x = c1.data + c2.data;
						res.insert(x, i, y);
						c1 = c1.R;
						c2 = c2.R;
					}
					r1 = r1.D;
					c1 = r1;
					r2 = r2.D;
					c2 = r2;
				}
				
			}
		}
		return (res);
	}


	public Matrix multiply (Matrix other)
	{
		Matrix res = null;
		if (this.top != null && other.top != null)
		{
			if (this.n == other.n)
			{
				res = new Matrix(this.n);

				Cell s2 = other.top;

				Cell r1 = this.top;
				Cell r2 = s2;
				Cell r3 = res.top;

				Cell c1 = r1;
				Cell c2 = r2;
				Cell c3 = r3;

				int tmp = 0;

				for (int x = 0; x < this.n; x++)
				{
					for (int y = 0; y < this.n; y++)
					{
						tmp = 0;
						for (int z = 0; z < this.n; z++)
						{
							tmp += c1.data * r2.data;
							c1 = c1.R;
							r2 = r2.D;
						}
						c3.data = tmp;
						c3 = c3.R;
						c1 = r1;
						c2 = c2.R;
						r2 = c2;
					}
					r1 = r1.D;
					c1 = r1;
					r2 = s2;
					c2 = r2;
					r3 = r3.D;
					c3 = r3;
				}

			}	
		}
		return (res);
	}

	public void write (Scanner sc)
	{
		for (int i = 0; i < this.n; i++)
		{
			for (int y = 0; y < this.n; y++)
			{
				int x = sc.nextInt();
				this.insert(x, i, y);
			}
		}
	}
}

public class Main 
{
	public static void main(String[] args)
	{	
		Scanner sc = new Scanner(System.in);
		Matrix m1 = null;
		Matrix m2 = null;
		Matrix m3 = null;
		int n = 0;
		int r = 0;
		int c = 0;

		n = sc.nextInt();

		for (int i = 0; i < n; i++)
		{
			r = sc.nextInt();
			c = sc.nextInt();
			m1 = new Matrix(r);
			m1.write(sc);

			r = sc.nextInt();
			c = sc.nextInt();

			m2 = new Matrix(r);
			m2.write(sc);
		
			m1.MainDiagonal();
			m1.SecondaryDiagonal();

			m3 = m1.sum(m2);
			m3.print();

			m3 = m1.multiply(m2);
			m3.print();
		}
	}
}
