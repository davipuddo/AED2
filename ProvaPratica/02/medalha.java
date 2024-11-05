import java.util.Scanner;

public class medalha
{
	public static int findN (String data, int y)
	{
		int r = 0;
		String buffer = "";

		while (y < data.length() && (data.charAt(y) < '0' || data.charAt(y) > '9'))
		{
			y++;
		}
		
		for (int i = y; i < data.length(); i++)
		{
			char c = data.charAt(i);
			if (c >= '0' && c <= '9')
			{
				buffer += c;
			}
			else if (c == ' ')
			{
				i = data.length();
			}
		}
		r = Integer.parseInt(buffer);
		return (r);
	}

	public static void sort (String[] data)
	{
		int n = data.length;
		for (int i = 0; i < n; i++)
		{
			for (int y = 0; y < n-1; y++)
			{
				int yP = findN(data[y], 0);
				int jP = findN(data[y+1], 0);
				
				if (yP < jP)
				{
					String tmp = data[y];
					data[y] = data[y+1];
					data[y+1] = tmp;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			System.out.println (data[i]);
		}
	}

	public static void main (String[] args)
	{
		String[] data;
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		sc = new Scanner(System.in);

		data = new String[n];

		for (int i = 0; i < n; i++)
		{
			data[i] = sc.nextLine();
		}
		System.out.println ("");
		sort (data);

	
	}
}
