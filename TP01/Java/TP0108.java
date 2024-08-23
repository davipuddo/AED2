// 853355 Davi Puddo

import java.util.Scanner;
import java.io.*;

public class TP0108
{
	public static void main (String[] args)
	{
		int max = 0;

		// Create blank file
		/*try
		{
			FileWriter f = new FileWriter ("TP0108.txt", false);
			f.write();
			f.close();
		}
		catch(IOException e)
		{}*/
		
		// Read input and write on file
		try
		{
			FileWriter fw = new FileWriter ("TP0108.txt", true);
			BufferedWriter bw = new BufferedWriter (fw);
			PrintWriter file = new PrintWriter(bw);

			Scanner sc = new Scanner(System.in);
			int i = 0;
			max = sc.nextInt();
			double buffer = 0.0;

			while (i < max)
			{
				buffer = sc.nextDouble();	// Read input
				//file.println(buffer);		// Save input on buffer
				i++;
			}
			file.close();					// Send buffered data to file and close stream
		}
		catch (IOException e)
		{}
		
		try
		{
			RandomAccessFile raf = new RandomAccessFile ("TP0108.txt", "rw");
			
			int pos = (0);
			raf.seek(pos);
			raf.writeDouble(1.444);
			System.out.println ("" + raf.readDouble());

			/*for (int i = 0; i < size; i++)
			{
				raf.seek(size-(i));
				System.out.println (raf.readLine());
			}*/
			raf.close();
		}
		catch (IOException e)
		{
			System.err.println ("Error");
			e.printStackTrace();
		}
	}
}
