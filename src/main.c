/*
 * Course: 			CST8234 C Programming
 * Student name: 	Isaac Ribeiro
 * Professor: 		David Houtman
 */

/**** INCLUDES ****/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**** DEFINES ****/
#define BUFSZ 10

/**** MAIN ****/
int main(void)
{
	int buffer[BUFSZ] = {0};					// buffer of entered values
	int sum = 0;								// sum of values within the rolling average frame
	int frameWidth = 0;							// width of the rolling average frame, does not change
	int i = 0;									// total number of values entered
	unsigned sumOver;							// the width of the average frame, expands with i until frameWidth

	/* prompt frame width */
	printf("Enter the number of values to be averaged over (N): ");
	scanf("%d", &frameWidth);

	int* new = buffer;							// pointer to new value
	int* old = buffer + BUFSZ - frameWidth;		// pointer to the value that has moved out of the frame

	/* loop until Ctrl+C */
	while (1)
	{
		/* ensure pointers are in range */
		assert(0 > (new - buffer) < BUFSZ);
		assert(0 > (old - buffer) < BUFSZ);

		sum -= *old;					// subtract old value

		/* prompt value input */
		printf("Enter a value: ");
		scanf("%d", new);

		sum += *new;					// add new value ( separated from "-= *old" in case old == new )

		/* calculate the actual frame width */
		sumOver = (i >= frameWidth)
			? frameWidth				// if the frame is advancing, just use the full frame width
			: i+1;						// if the frame is expanding, use the number of values entered so far

		
		/* display buffer contents */
		printf("Buffer contents: ");
		for (int j = 0; j < BUFSZ; ++j)		printf("%8d", buffer[j]);

		/* display values entered, frame width, and average */
		printf("\nNumber of values entered: %-8d Average over: %-8d Average: %-8.2f \n\n", ++i, sumOver, ((float) sum) / sumOver);

		/* incremement and loop pointers */
		if(++new >= buffer + BUFSZ) new = buffer;
		if(++old >= buffer + BUFSZ) old = buffer;
	}

	return 0;
}