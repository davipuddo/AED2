// 853355 Davi Puddo

public class Sort
{
	// Sort the array
	public static int[] sort (int mod, int[] data)
	{
		if (data != null)
		{
			// Variables
			int size = data.length-1;
			int tmp = 0;

			for (int i = 0; i < size; i++)
			{
				int y = i+1;					// Cursor
				int cmod = (data[i] % mod);		// Current module
				int omod = 0;					// Other module

				// Move cursor
				while (y < data.length)
				{
					omod = (data[y] % mod);

					// If other module is smaller
					if (cmod > omod)
					{
						// Swap
						tmp = data[i];
						data[i] = data[y];
						data[y] = tmp;

						// Update current module
						cmod = (data[i] % mod);
					}
					else if (cmod == omod)	// If they are the same
					{
						// If both numbers are odd
						if (data[i] % 2 == 1 && data[y] % 2 == 1)
						{
							// if other value is bigger than the current
							if (data[y] > data[i])
							{	
								// Swap
								tmp = data[i];
								data[i] = data[y];
								data[y] = tmp;
							}
							// Swap to the front
							tmp = data[y];
							data[y] = data[i+1];
							data[i+1] = tmp;
						}
						else if (data[y] % 2 == 1) // If current is even and odd is odd
						{
							// Swap
							tmp = data[i];
							data[i] = data[y];
							data[y] = tmp;

							// Swap front
							tmp = data[y];
							data[y] = data[i+1];
							data[i+1] = tmp;
						}
						else if (data[i] % 2 == 0) // If both are even
						{
							// Swap the smaller one
							if (data[y] < data[i])
							{
								// Swap
								tmp = data[i];
								data[i] = data[y];
								data[y] = tmp;
							}
							// Swap front
							tmp = data[y];
							data[y] = data[i+1];
							data[i+1] = tmp;
						}
					}
					y++;
				}
			}
		}
		return (data);
	}

	// Print the array
	public static void print (int i, int mod, int[] data)
	{
		if (data != null)
		{
			System.out.println (i+" "+mod);
			for (int y = 0; y < data.length; y++)
			{
				System.out.println(data[y]);
			}
		}
	}

	public static void main (String[] args)
	{
		// Variables
		int[] data = null;
		int[] result = null;
		int i = 0;
		int mod = 0;
		boolean stop = false;
		
		while (stop == false)
		{
			// Read initial parameters
			i = MyIO.readInt();
			mod = MyIO.readInt();

			// Stop condition
			if (i <= 0 && mod <= 0)
			{
				stop = true;
				System.out.println ("0 0");	// Print special condition
			}
			else
			{
				// Alloc array
				data = new int [i];
				
				// Read numbers
				for (int y = 0; y < i; y++)
				{
					data[y] = MyIO.readInt();
				}
				
				// Sort array
				result = sort (mod, data);

				// Print sorted array
				if (result != null) 
				{	
					print (i, mod, result);
				}
			}
		}
	}
}

