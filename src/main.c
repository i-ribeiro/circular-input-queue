/*
 * Course: 			CST8234 C Programming
 * Student name: 	Isaac Ribeiro
 * Professor: 		David Houtman
 */

/**** INCLUDES ****/
#include <stdio.h>
#include <stdlib.h>

/**** DEFINES ****/
#define BUFSZ 10

/**** MAIN ****/
int main(void)
{

	int buffer[BUFSZ] = {0};

	int sum = 0;
	int frameWidth = 0;
	int i = 0;

	printf("Enter the number of values to be averaged over (N): ");
	scanf("%d", &frameWidth);

	while (1) {

		/* calculate indices */
		unsigned short bAdvanceFrame = i >= frameWidth;			// should the frame advance with the new index or expand?
		unsigned newIndex = i % BUFSZ;
		unsigned oldIndex = (i - frameWidth) % BUFSZ;

		/* prompt value input */
		printf("Enter a value: ");
		scanf("%d", &buffer[newIndex]);


		/* calculate the sum */
		sum += (bAdvanceFrame)
			? buffer[newIndex] - buffer[oldIndex]		// if the frame is advancing, subtract the old value
			: buffer[newIndex];							// if the frame is expanding, just add the new value

		/* calculate the actual frame width */
		unsigned frameWidthActual = (bAdvanceFrame)
			? frameWidth								// if the frame is advancing, just use the full frame width
			: i+1;										// if the frame is expanding, use the number of values entered so far

		
		/* display buffer contents */
		printf("Buffer contents: ");
		for (int j = 0; j < BUFSZ; ++j) printf("%8d", buffer[j]);
		printf("\n");

		/* display values entered, frame width, and average */
		printf("Number of values entered: %-8d Average over: %-8d Average: %-8.2f \n\n", i+1, frameWidthActual, (float) sum / (float) frameWidthActual);

		/* continue to next value */
		++i;
	}

	return 0;
}