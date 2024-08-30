// 853355 Davi Puddo

import java.io.*;

public class TP0108
{
	public static void main (String[] args)
	{
		// Read number of double elements to be read
		int max = MyIO.readInt();

		// File	
		try
		{
			// Open file
			RandomAccessFile raf = new RandomAccessFile ("TP0108.txt", "rw");

			// Write values on the file
			for (int i = max; i > 0; i--)
			{
				double buffer = MyIO.readDouble();
				raf.writeDouble(buffer);
			}
			
			int max2 = max+1;					// Otimization

			// Read file backwards
			for (int i = 1; i < max2; i++)
			{
				raf.seek(raf.length()-(i*8));
				double buffer = raf.readDouble();

				// Show values read
				if (buffer == (int)buffer)
				{
					System.out.println ((int)buffer);
				}
				else
				{
					System.out.println (buffer);
				}
			}
			raf.close();						// Close/Save file
		}
		catch (IOException e)					// If error occurs
		{
			System.err.println ("Error");
			e.printStackTrace();
		}
	}
}
