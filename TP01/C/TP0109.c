// 853355 Davi Puddo

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int max = 0;	// Qnt of values to be read

	// Read Qnt
	scanf("%d", &max);
	getchar();			// Flush /n

	// Open file in writing mode
	FILE *file;
	file = fopen("TP0109.txt", "wt");
	
	// Read values and write then in the file
	if (file != NULL)
	{
		float buffer = 0.0;
		for (int i = 0; i < max; i++)
		{
			scanf("%f", &buffer);
			getchar();				// Flush /n
			
			// Write on file
			fprintf (file, "%f\n", buffer);
		}
		fclose (file);				// Close/Save file
		buffer = 0.0;				// Flush buffer
	
		// Open file in reading mode
		file = fopen ("TP0109.txt", "rt");
								
		fseek (file, 0, SEEK_END);			// Go to end of the file	
		int ptr = ftell(file)-8;

		// Read values from the file backwards
		for (int i = 0; i < max; i++)
		{
			// Find and point to \n
			while (ptr >= 0 && fgetc(file) != '\n')
			{
				ptr--;
				fseek (file, ptr, SEEK_SET);
			}

			fseek  (file, -1, SEEK_CUR);		// Point to number

			fscanf (file, "%f", &buffer);
			printf ("%g\n", buffer);			// Show value at the pointer
			
			ptr--;
			fseek  (file, ptr, SEEK_SET);		// Correct fscanf offset
		}
		fclose(file);
	}	
	return (0);
}
