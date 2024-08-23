// 853355 Davi Puddo

import java.util.Scanner;

public class TP0106
{
	// Verificar se o caractere e uma vogal
	public static boolean isVogal (char c)
	{
		return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
	}

	// Verificar se o caractere e uma letra qualquer
	public static boolean isLetter (char c)
	{
		return ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
	}

	// Descobrir se a string apresenta apenas vogais
	public static boolean onlyVogal (String data)
	{
		boolean result = false;
		if (data != null)
		{
			int size = data.length();
			int i = 0;

			while (i < size && isLetter(data.charAt(i)) && isVogal(data.charAt(i)))
			{
				i++;
			}

			if (i == size)
			{
				result = true;
			}
		}
		return (result);
	}
	
	// Descobrir se a string apresenta apenas consoantes
	public static boolean onlyConsonant (String data)
	{
		boolean result = false;
		if (data != null)
		{
			int i = 0;
			int size = data.length();

			while (i < size && isLetter(data.charAt(i)) && !isVogal(data.charAt(i)))
			{
				i++;
			}

			if (i == size)
			{
				result = true;
			}
		}
		return (result);
	}

	public static boolean isInt (String data)
	{
		boolean result = false;
		if (data != null)
		{
			result = true;
			int i = 0;
			int size = data.length();

			while (i < size && result == true)
			{
				char buffer = data.charAt(i);
				if (buffer < '0' || buffer > '9')
				{
					result = false;
				}
				i++;
			}
		}
		return (result);
	}

	public static boolean isDouble (String data)
	{
		boolean result = false;
		if (data != null)
		{
			result = true;
			int i = 0;
			int size = data.length();
			boolean point = false;


			while (i < size && result == true)
			{	
				char buffer = data.charAt(i);
				if (buffer == '.' || buffer == ',')
				{
					if (point == true)
					{
						result = false;
					}
					point = true;
				}

				if ( !( (buffer >= '0' && buffer <= '9') || buffer == '.' || buffer == ','))
				{
					result = false;
				}
				i++;
			}
		}
		return (result);
	}

	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String data = null;
		boolean stop = false;
		boolean result = false;

		String X1 = "NAO";
		String X2 = "NAO";
		String X3 = "NAO";
		String X4 = "NAO";

		while (stop == false)
		{
			data = MyIO.readLine();
			result = false;

			if (data.length() == 3 && data.charAt(0) == 'F' && data.charAt(1) == 'I' && data.charAt(2) == 'M')
			{
				stop = true;
			}
			else
			{
				result = onlyVogal (data);
				if (result == true)
				{
					X1 = "SIM";
				}
				else
				{
					X1 = "NAO";
				}

				result = onlyConsonant (data);

				if (result == true)
				{
					X2 = "SIM";
				}
				else
				{
					X2 = "NAO";
				}

				result = isInt(data);
				if (result == true)
				{
					X3 = "SIM";
				}
				else
				{
					X3 = "NAO";
				}

				result = isDouble(data);
				if (result == true)
				{
					X4 = "SIM";
				}
				else
				{
					X4 = "NAO";
				}
				MyIO.println (X1 + ' ' + X2 + ' ' + X3 + ' ' + X4);
			}
		}
	}
}
