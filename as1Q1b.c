/*
* Programmer: Kollin Labowski
* Date Completed: September 27, 2020
* Course: CS 350
* Description: This program includes a function integerPower(int a, int b) and the main method to test this function. The program prompts the
* user for two inputs, a base number and an exponent to raise the base number to. This program accomplished the task using a recursive function.
*/

# include <stdio.h>

//Function prototype
int integerPower(int a, int b);

//Main method
void main()
{
	int x, y;

	printf("What is your base number?\n");
	scanf("%d", &x);

	printf("What is your exponent?\n");
	scanf("%d", &y);

	int answer = -1;
	if(y <= 0)
		printf("Invalid input: Exponent must be a positive nonzero integer");
	else
		answer = integerPower(x, y);

	if(answer != -1)
		printf("The result of %d^%d is %d", x, y, answer);
}

/*
* This method accepts 2 parameters, a base number and an exponent, and raises the base number to the exponent using recursion. It returns a
* value of type integer.
*/
int integerPower(int base, int exponent)
{
	if(exponent <= 0)
		return 1;

	return base * integerPower(base, exponent - 1);
}