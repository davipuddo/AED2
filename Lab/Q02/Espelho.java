// 853355 Davi Puddo

import java.util.Scanner;
import java.util.NoSuchElementException;

public class Espelho
{
	public static String invert (int value)
	{
		String result = "";
		int pow = 0;
		int buffer = value;

		// Discover power
		while (value >= Math.pow(10, pow))
		{
			pow++;
		}

		// Transform the value to string
		for (int i = 0; i < pow; i++)
		{
			int tmp = (int)((double)buffer%Math.pow(10, i+1));
			tmp = (int)((double)tmp / Math.pow(10, i));
			result += (char)(tmp + 48);
		}
	
		return (result);
	}

	// Print a sequence of numbers from i to target and print the same sequence mirrored
	public static void mirror (int i, int target)
	{
		System.out.print (i);
		if (i < target)
		{
			mirror (i+1, target);
		}
		System.out.print (invert(i));
	}

	public static void main (String[] args)
	{
		// Define data
		Scanner sc = new Scanner (System.in);
		int target = 0;
		int i = 0;
		boolean stop = false;

		while (stop == false)
		{
			try
			{			
				i = sc.nextInt();
				target = sc.nextInt();

				mirror(i, target);
				System.out.println("");
			}
			catch(NoSuchElementException nsee)	// Stop while
			{
				stop = true;
			}
		}
	}
}
