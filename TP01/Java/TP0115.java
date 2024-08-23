// 853355 Davi Puddo

import java.util.Scanner;

public class TP0115
{
	// Test if a char is a letter
	public static boolean isLetter (char c)
	{
		boolean result = false;
		result = ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') );
		return (result);
	}

	public static boolean isNumber (char c)
	{
		boolean result = false;
		result = (c >= '0' && c <= '9');
		return (result);
	}

	// Test if a char is a vogal
	public static boolean isVogal (char c)
	{
		return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	}
	
	// Test if a whole string is made of vogals
	public static boolean vogalE (String data, boolean result, int i)
	{
		result = isVogal(data.charAt(i));
		if (i < data.length()-1 && result)
		{	
			result = vogalE(data, result, i+1);
		}
		return (result);
	}

	// Encapsulate vogalE
	public static boolean vogal (String data)
	{
		return (vogalE(data, false, 0));
	}

	// Test if a char is a consonant
	public static boolean isConsonant (char c)
	{
		boolean result = false;
		result = (isLetter(c) && !isVogal(c) && !isNumber(c));
		return (result);
	}

	// Test if a whole string is made of consonants
	public static boolean consonantE (String data, boolean result, int i)
	{
		result = isConsonant(data.charAt(i));
		if (i < data.length()-1 && result)
		{
			result = consonantE (data, result, i+1);
		}
		return (result);
	}
	
	// Encapsulate consoantE
	public static boolean consonant (String data)
	{
		return (consonantE(data, false, 0));
	}
	
	// Test if a string is a whole number
	public static boolean IntNE (String data, boolean result, int i)
	{
		result = isNumber(data.charAt(i));

		if (i < data.length()-1 && result)
		{
			result = IntNE (data, result, i+1);
		}
		return (result);
	}

	// Encapsulate IntNE
	public static boolean IntN (String data)
	{
		return (IntNE(data, true, 0));
	}

	// Test if a string is a real number
	public static boolean DoubleNE (String data, boolean result, int i, boolean dot)
	{
		char buffer = data.charAt(i);

		if ( (buffer == '.' || buffer == ',') && !dot)
		{
			result = true;
			dot = true;
		}
		else
		{
			result = (isNumber(buffer));
		}

		if (i < data.length()-1 && result)
		{
			result = DoubleNE (data, result, i+1, dot);
		}
		return (result);
	}

	//	Encapsulate DoubleNE
	public static boolean DoubleN (String data)
	{
		return (DoubleNE(data, true, 0, false));
	}
	
	public static void main (String[] args)
	{
		// Define data
		Scanner sc = new Scanner (System.in);	// Input-reading obj
		String data = null;						// Value read

		String r1 = null;	// Vogal
		String r2 = null;	// Consonant
		String r3 = null;	// Whole number
		String r4 = null;	// real number

		boolean stop = false;		// Stop condition
		boolean result = false;		// Function result
	
		while (stop == false)
		{
			// Read data
			data = sc.nextLine();

			// Stop condition
			if (data != null && data.length() == 3 && data.charAt(0) == 'F' && data.charAt(1) == 'I' && data.charAt(2) == 'M')
			{
				stop = true;
			}
			else
			{
				r1 = "NAO";
				r2 = "NAO";
				r3 = "NAO";
				r4 = "NAO";

				result = vogal (data);
				if (result == true)
				{
					r1 = "SIM";
				}

				result = consonant (data);
				if (result)
				{
					r2 = "SIM";
				}
				
				result = IntN (data);
				if (result)
				{
					r3 = "SIM";
				}
	
				result = DoubleN (data);
				if (result)
				{
					r4 = "SIM";
				}

				System.out.println (r1 + " " + r2 + " " + r3 + " " + r4);
			}
		}
	}
}
