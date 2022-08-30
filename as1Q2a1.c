/*
* Programmer: Kollin Labowski
* Date Completed: September 27, 2020
* Course: CS 350
* Description: This program includes a function isPrime(int a) that determines whether a number is prime or not (more description below), and a main method
* which tests this function on the numbers 1-10000, printing out all of the numbers for which the function evaluates as true. This specific version uses an
* upper bound to check primes of n/2, as stated in the programming assignment.
*/

//Include statements
#include <stdio.h>
#include <math.h>
#include <time.h>

//Function prototype
int isPrime(int a);

//Main method
void main()
{
	clock_t start = clock();//Used for timing the program

	//Variables (including constant 10000 which specifies amount of iterations)
	int format = 0;//Used to format the printed values
	const int LOOPS = 10000;

	for(int i = 1; i <= LOOPS; i++)
	{
		if(isPrime(i))
		{
			printf("%d ", i);
			if(format % 10 == 0)
				printf("\n");
			format++;
		}
	}

	//These methods determine the elapsed time and print it to the terminal
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n\nTime elapsed: %lf", time);
}

/*
* This function determines whether a number is prime or not by using loops. It first checks and evaluates the unique cases of 1 and 2 individually. It also
* is able to determine immediately that a number is not prime by checking if it is even. Otherwise, the function will loop and determine whether the input
* value is divisible by each odd integer that is <= the square root of the input number. This function uses a loop that terminates at n/2.
*/
int isPrime(int test)
{
	//1 evaluates as nonprime
	if(test == 1)
		return 0;

	//2 evaluates as prime
	if(test == 2)
		return 1;

	//All other even numbers evaluate as nonprime
	if(test % 2 == 0)
		return 0;

	//Loop used to determine whether the number is prime if not even or an extraneous case
	for(int i = 3; i <= test/2; i+=2)//The loop checks until n/2 is reached
	{
		if(test % i == 0)
			return 0;
	}
	return 1;
}