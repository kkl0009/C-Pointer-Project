/*
* Programmer: Kollin Labowski
* Date Completed: September 28, 2020
* Course: CS 350
* Description: This program generates all of the prime numbers from 1 to 10000 using a method called "The Sieve of Eratosthenes". This method uses an array
* of 1s and 0s which are used to indicate whether a number at the specified index is prime or not. It should be noted that each index (0-9999) is actually
* used to represent a number that is one greater than it (ie: index 0 corresponds to the number 1), thus giving the range 1-10000.
*/

//Include statements
#include <stdio.h>
#include <time.h>

//Main method
void main()
{
	//Used for timing the program
	clock_t start = clock();

	//Initialize the array at size set by the user, here is 10000
	const int ARRSIZE = 10000;
	int array[ARRSIZE]; 

	//Set each element of the array to 1 to begin
	for(int i = 0; i < ARRSIZE; i++)
	{
		array[i] = 1;
	}

	//Loops through all values in the array
	//When a 1 is found, print the value connected to that index and set the indexes of all multiples of that value to 0 so they are not checked again 
	int format = 0;
	for(int i = 1; i < ARRSIZE; i++)
	{
		if(array[i] == 1)
		{
			printf("%d ", i + 1);
			for(int j = i; j < ARRSIZE; j += (i + 1))
			{
				array[j] = 0;
			}
			if(format % 10 == 0)
				printf("\n");
			format++;
		}
	}

	//Methods used for measuring the time the program spends running
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n\nTime elapsed: %lf", time);
}