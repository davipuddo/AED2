// 853355 Davi Puddo

import java.util.Scanner;

public class TP0105
{
	public static boolean Abool (String dataE)
	{
		boolean result = false;
		if (dataE != null)
		{
			// Define data
			int vars = (int)(dataE.charAt(0) - '0');
			int[] values = new int [vars];
			int size = dataE.length();	
			String buffer = "";

			if (values != null)
			{
				// Read and save input values
				for (int i = 0; i < vars; i++)
				{
					values[i] = (dataE.charAt((i+1)*2) - '0');
				}
				
				// Read and save gates
				for (int i = 2*(vars+1); i < size; i++)
				{
					buffer += dataE.charAt(i);
				}
				
				String data = buffer;
				size = data.length();
				buffer = "";
				for (int i = size-1; i > -1; i--)
				{
					char c = data.charAt(i);	// Current caractere
					if (c == 'A' || c == 'B' || c == 'C')
					{
						int CharBuffer = values[(int)(c-'A')];
						if (data.charAt(i-2) == 't')
						{
							CharBuffer = (CharBuffer*-1)+1;
							i -= 5;
						}
						else if (data.charAt(i-2) == 'r')
						{
							System.out.println ("y: "+data.charAt(i+4));
							int aux = values[(int)(data.charAt(i+4)-'A')];
							if (aux == 1)
							{
								CharBuffer = 1;
							}
							i -= 4;
						}
						else if (data.charAt(i-2) == 'd')
						{
							System.out.println (data.charAt(i+4));
							int aux = values[(int)(data.charAt(i+4)-'A')];
							if (aux == 0)
							{
								CharBuffer = 0;
							}
							i -= 5;
						}
						buffer += CharBuffer;
					}
					else if (c != ')')
					{
						buffer += c;
					}
				}
				System.out.println (buffer);
			}
		}
		return (result);
	}

	public static void main (String[] args)
	{
		// Define data
		String data = null;
		boolean result = false;
		boolean stop = false;

		while (stop == false)
		{
			// Read data
			data = MyIO.readLine();
			
			if (data != null)
			{	
				// While stop condition
				if (data.charAt(0) == '0')
				{
					stop = true;
				}
				else
				{
					result = Abool(data);
					/*if (result == true)
					{
						System.out.println (1);
					}
					else
					{
						System.out.println (0);
					}*/
				}
			}
			else
			{
				System.err.println ("Couldnt read string");
			}
		}

	}
}
