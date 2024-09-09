// 853355 Davi Puddo

import java.util.Scanner;

public class TP0113
{
	public static int seek (String data, int i)
	{
		int limit = 0;
		int size = data.length();
		for (int y = 0; y < size; y++)
		{
			int c = data.charAt(y);
			if (c == '(')
			{
				limit++;
			}
			else if (c == ')')
			{
				limit--;
			}

			if (c == ',' && limit == 0)
			{
				i = y;
				y = size;
			}
		}
		return (i);
	}

	public static int AlgB (String data, int[] values, int i)
	{
		char c = data.charAt(i);
		int result = 0;

		if (c == '(')
		{
			// Find inner value
			int inner = AlgB(data, values, i+1);

			char bf = data.charAt(i-1); // Find operator

			if (bf == 't')	// NOT
			{
				result = (inner*-1)+1;				// Invert 0 & 1
			}
			else if (bf == 'd')	 // AND
			{
				// Seek ','
				i = seek (data, i);	
			
				int other = AlgB (data, values, i+1);

				// Get other's value
				int other2 = 0;
				if (values.length > 2)
				{
					// Seek ','
					i = seek (data, i);
					other2 = AlgB (data, values, i+1);
				}
				else
				{
					other2 = 1;
				}
				
				// Operation
				if (inner == 1 && other == 1 && other2 == 1)
				{
					result = 1;
				}
				else
				{
					result = 0;
				}
			}
			else if (bf == 'r')  // OR
			{
				// Seek ','
				i = seek (data, i);

				// Get other's value
				int other = AlgB(data, values, i+1);
				int other2 = 0;
	
				if (values.length > 2)
				{
					// Seek ','
					i = seek (data, i);
					other2 = AlgB(data, values, i+1);
				}

				// Operation
				if (inner == 1 || other == 1 || other2 == 1)
				{
					result = 1;
				}
				else
				{
					result = 0;
				}
			}
		}
		else if (c >= 'A' && c <= 'Z')	// Get variables value
		{
			result = values[(int)(c-'A')];
		}
		else if (i < data.length()-1)	// Keep repeating
		{
			result = AlgB(data, values, i+1);
		}
		return (result);
	}

	public static void main (String[] args)
	{
		// Variables
		String data = null;
		int result = 0;
		boolean stop = false;
		int[] values = null;
		int n = 0;
		Scanner sc = new Scanner (System.in);

		while (stop == false)
		{
			// Read String
			data = sc.nextLine();

			if (data != null)
			{
				if (data.charAt(0) == '0')	// Stop condition
				{
					stop = true;
				}
				else
				{
					// Get variables qnt
					n = (data.charAt(0)-'0');

					// Alloc array
					values = new int[n];
					
					// Save variables value
					for (int i = 0; i < n; i++)
					{
						values[i] = (data.charAt((i+1)*2) - '0');
					}

					// Test String
					result = AlgB(data, values, 0);

					// Show result
					System.out.println (result);
				}
			}
		}
	}
}
