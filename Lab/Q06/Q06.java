// 853355 Davi Puddo

import java.util.Scanner;
import java.util.Random;

public class Q06
{
	// Elementos globais
	static Random rand = new Random();
	static long start;
	static long end;
	static int[] data;
	static int n;

	public static void swap (int x, int y)
	{
		int tmp = data[x];
		data[x] = data[y];
		data[y] = tmp;
	}

	public static int median (int L, int R)
	{
		int buffer = (int)((L+R)/2.0);
		int a = data[L];
		int b = data[R];
		int c = data[buffer];
		int result = 0;
		
		if (data != null)
		{
			if (a > b)
			{
				if (b > c)
				{
					result = b;
				}
				else
				{
					result = c;
				}
			}
			else
			{
				if (a > c)
				{
					result = a;
				}
				else
				{
					result = c;
				}
			}
		}
		return (result);
	}

	// Sorts
	public static void QuickSortFirst (int L, int R)
	{
		int pivo = data[L];
		int i = L;
		int y = R;

		while (i <= y)
		{
			while (data[i] < pivo)
			{
				i++;
			}
			while (data[y] > pivo)
			{
				y--;
			}
			if (i <= y)
			{
				swap(i, y);
				i++;
				y--;
			}
		}

		if (i < R)
		{
			QuickSortFirst (i, R);
		}
		if (L < y)
		{
			QuickSortFirst (L, y);
		}
	}

	public static void QuickSortLast (int L, int R)
	{
		int pivo = data[R];	
		int i = L;
		int y = R;

		while (i <= y)
		{
			while (data[i] < pivo)
			{
				i++;
			}
			while (data[y] > pivo)
			{
				y--;
			}
			if (i <= y)
			{
				swap(i, y);
				i++;
				y--;
			}
		}

		if (i < R)
		{
			QuickSortLast (i, R);
		}
		if (L < y)
		{
			QuickSortLast (L, y);
		}
	}

	public static void QuickSortRand (int L, int R)
	{
		int buffer = rand.nextInt(R-L)+L;
		int pivo = data[buffer];
		int i = L;
		int y = R;

		while (i <= y)
		{
			while (data[i] < pivo)
			{
				i++;
			}
			while (data[y] > pivo)
			{
				y--;
			}
			if (i <= y)
			{
				swap(i, y);
				i++;
				y--;
			}
		}

		if (i < R)
		{
			QuickSortRand (i, R);
		}
		if (L < y)
		{
			QuickSortRand (L, y);
		}
	}

	public static void QuickSortMedian (int L, int R)
	{
		int pivo = median(L, R);
		int i = L;
		int y = R;

		while (i <= y)
		{
			while (data[i] < pivo)
			{
				i++;
			}
			while (data[y] > pivo)
			{
				y--;
			}
			if (i <= y)
			{
				swap(i, y);
				i++;
				y--;
			}
		}

		if (i < R)
		{
			QuickSortMedian (i, R);
		}
		if (L < y)
		{
			QuickSortMedian (L, y);
		}
	}
	
	public static void writeA ()
	{
		int i = 0;

		int max = Integer.MAX_VALUE;
		//int max = 99;
		int val = rand.nextInt(max);
		for (i = 0; i < n; i++)
		{
			data[i] = val;
		//	data[i] = n-i;
		}
	}
	
	public static void printA ()
	{
		if (data != null)
		{
			for (int i = 0; i < n; i++)
			{
				System.out.print ("["+data[i]+"]");
			}
			System.out.println ();
		}
	}

	public static double TotalTime ()
	{
		double buffer = (end-start);
		buffer /= 1000000;
		//System.out.println (buffer+"");
		return (buffer);
	}

	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		data = new int[n];
		
		System.out.println("n="+n+"\n");
		if (data != null)
		{
			int qnt = sc.nextInt();
			double[][] rs = new double[4][qnt];
			for (int i = 0; i < qnt; i++)
			{
				// Escrever vetor
				writeA();

				int[] buffer = data.clone();

				// Primeiro
				data = buffer.clone();
			//	System.out.println ("Pivo no inicio");
				start = System.nanoTime();
				QuickSortFirst(0, n-1);
				end = System.nanoTime();
				rs[0][i] = TotalTime(); 

				// Ultimo
				data = buffer.clone();
			//	System.out.println ("\nPivo no fim");
				start = System.nanoTime();
				QuickSortLast(0, n-1);
				end = System.nanoTime();
				rs[1][i] = TotalTime();

				// Aleatorio
				data = buffer.clone();
			//	System.out.println ("\nPivo aleatorio");
				start = System.nanoTime();
				QuickSortRand(0, n-1);
				end = System.nanoTime();
				rs[2][i] = TotalTime();

				// Mediana
				data = buffer.clone();
			//	System.out.println ("\nPivo na mediana");
				start = System.nanoTime();
				QuickSortMedian(0, n-1);
				end = System.nanoTime();
				rs[3][i] = TotalTime();
			}
			for (int i = 0; i < 4; i++)
			{
				double x = 0.0;
				for (int y = 0; y < qnt; y++)
				{
					x += rs[i][y];
				}
				System.out.println (x/(double)qnt);
			}
		}
	}
}
