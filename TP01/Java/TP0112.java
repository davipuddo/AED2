// 853355 Davi Puddo

public class TP0112
{
	public static String encode (String data, int i)
	{
		String result = "";
		if (data != null)
		{
			result += (char)(data.charAt(i) + 3);
			if (i < data.length()-1)
			{
				result += encode (data, i+1);
			}
		}
		return (result);
	}

	public static void main (String[] args)
	{
		String data = null;
		String result = null;
		boolean stop = false;

		while (stop == false)
		{
			data = MyIO.readLine();

			if (data != null && data.length() == 3 && data.charAt(0) == 'F' && data.charAt(1) == 'I' && data.charAt(2) == 'M')
			{
				stop = true;
			}
			else
			{
				result = encode(data, 0);

				MyIO.println (result);
			}
		}
	}
}
