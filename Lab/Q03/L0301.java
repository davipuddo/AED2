// 853355 Davi Puddo

import java.util.Scanner;
import java.util.NoSuchElementException;

public class L0301
{
	// Test if a string has all brackets closed
	public static boolean brackets (String data)
	{
		boolean result = false;
		if (data != null)
		{
			int size = data.length();
			int buffer = 0;

			for (int i = 0; i < size; i++)
			{
				if (data.charAt(i) == '(')
				{
					buffer++;
				}
				else if (data.charAt(i) == ')')
				{
					if (buffer == 0)
					{
						i = size;
					}
					buffer--;
				}
			}
			if (buffer == 0)
			{
				result = true;
			}
		}
		return (result);
	}

	public static void main (String[] args)
	{
		// Define data
		Scanner sc = new Scanner (System.in);
		String data = null;	
		boolean stop = false;
		boolean result = false;
		
		// Stop condition 1	| nothing to read
		try 
		{	
			while (stop == false)
			{
				// Read data
				data = sc.nextLine();

				// Stop condition 2	| string read == null or "FIM"
				if (data == null | (data.length() == 3 && data.charAt(0) == 'F' && data.charAt(1) == 'I' && data.charAt(2) == 'M') )
				{
					stop = true;
				}
				else
				{
					// Test string
					result = brackets (data);
					
					// Show result
					if (result == true)
					{
						System.out.println ("correto");
					}
					else
					{
						System.out.println ("incorreto");
					}
				}
			}
		}
		catch (NoSuchElementException NSEE)
		{}
	}
}
