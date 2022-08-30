/*
* Programmer: Kollin Labowski
* Date Completed: October 1, 2020
* Course: CS 350
* Description: This program allows the user to control a "turtle" by inputting a variety of commands that allow the
* turtle to draw shapes and lines when indicated by the user. Commands include the ability to raise and lower a pen
* that is used to draw the lines and shapes, the ability to turn either right or left, the ability to move forward
* a number of spaces, the ability to print out the grid, and the ability to exit the program. Additionally, 2 extra
* functions were added that were not required in the assignment document, these functions being the ability to display
* a help menu and the ability to display the current position and direction of the "turtle".
*/

//Include Statements
#include <stdio.h>

//Constants used to indicate direction
const int EAST = 0;
const int SOUTH = 1;
const int WEST = 2;
const int NORTH = 3;

//Constants used to indicate size of grid
const int ROW_SIZE = 20;
const int COL_SIZE = 20;

//Function prototypes
void rightTurn();
void leftTurn();
void draw(int[][COL_SIZE]);
int moveForward(int numSpaces, int[][COL_SIZE]);
void drawGrid(int[][COL_SIZE]);

//Variables that are modified
int penIsDown = 0;
int xPos = 0;
int yPos = 0;
int direction = EAST;

//Main method
void main()
{
	//The grid to be modified throughout the program
	int grid[ROW_SIZE][COL_SIZE];

	//Initialize the array to have all zeroes
	for(int i = 0; i < ROW_SIZE; i++)
		for(int j = 0; j < COL_SIZE; j++)
			grid[i][j] = 0;

	//Loops until a sentinel values is reached, in which case the loop is broken out of
	while(1)
	{
		//Variables to track the input command and number of spaces if command 5 is input
		int command;
		int spaces;
		printf("Please input a command: ");
		scanf("%d, %d", &command, &spaces);

		//If statements used to ensure the correct command is performed based on the input
		if(command == 1)
		{
			//Brings pen up
			penIsDown = 0;
			printf("\nThe pen is now up...\n\n");
		}
		else if(command == 2)
		{
			//Puts pen down
			penIsDown = 1;
			draw(grid);
			printf("\nThe pen is now down...\n\n");
		}
		else if(command == 3)
		{
			//Performs a right turn
			rightTurn();
			printf("\nTurned to the right...\n\n");
		}
		else if(command == 4)
		{
			//Performs a left turn
			leftTurn();
			printf("\nTurned to the left...\n\n");
		}
		else if(command == 5)
		{
			//Moves forward a number of spaces if possible
			if((spaces >= ROW_SIZE && spaces >= COL_SIZE) || spaces < 0)
				printf("\nInvalid input for number of spaces...\n\n");
			else
			{
				int actualMovement = moveForward(spaces, grid);
				printf("\nMoved forward %d spaces...\n\n", actualMovement);
			}
		}
		else if(command == 6)
		{
			//Prints out the full grid
			printf("\nPrinting the grid below...\n\n");
			drawGrid(grid);
		}
		else if(command == 7)
		{
			//Displays a help menu
			printf("\n - Input 1 to move pen up");
			printf("\n - Input 2 to move pen down");
			printf("\n - Input 3 to turn right");
			printf("\n - Input 4 to turn left");
			printf("\n - Input 5 followed be a comma and a # to move a # of spaces forward");
			printf("\n - Input 6 to print out the grid");
			printf("\n - Input 7 to print this help menu");
			printf("\n - Input 8 to print the current location and direction of \"turtle\"");
			printf("\n - Input 9 to exit the program\n\n");
		}
		else if(command == 8)
		{
			//Displays the position and direction of the "turtle"
			printf("\nCurrent position is (%d,%d)", xPos, yPos);
			if(direction == EAST)
				printf("\nCurrent direction is EAST\n\n");
			else if(direction == SOUTH)
				printf("\nCurrent direction is SOUTH\n\n");
			else if(direction == WEST)
				printf("\nCurrent direction is WEST\n\n");
			else if(direction == NORTH)
				printf("\nCurrent direction is NORTH\n\n");
			else
				printf("\nCurrent direction is UNKNOWN\n\n");
		}
		else if(command == 9)
		{
			//Exits the program
			printf("\nExiting the program...\n");
			break;
		}
		else
		{
			//Invalid input was received
			printf("\nPlease enter a valid input (input 7 for help)...\n\n");
		}
	}
}

/*
* This method allows the "turtle" to turn right by resetting the direction based on the current direction
*/
void rightTurn()
{
	if(direction == EAST)
	{
		direction = SOUTH;
	}
	else if(direction == SOUTH)
	{
		direction = WEST;
	}
	else if(direction == WEST)
	{
		direction = NORTH;
	}
	else if(direction == NORTH)
	{
		direction = EAST;
	}
}

/*
* This method allows the "turtle" to turn left by resetting the direction based on the current direction
*/
void leftTurn()
{
	if(direction == EAST)
	{
		direction = NORTH;
	}
	else if(direction == SOUTH)
	{
		direction = EAST;
	}
	else if(direction == WEST)
	{
		direction = SOUTH;
	}
	else if(direction == NORTH)
	{
		direction = WEST;
	}
}

/*
* This is a simple method which sets a position to 1 based on the current x and y position of the "turtle"
*/
void draw(int grid[ROW_SIZE][COL_SIZE])
{
	grid[yPos][xPos] = 1;
}

/*
* Allows the "turtle" to move forward a number of spaces as input by the user. If the pen is down, also draw along this line
*/
int moveForward(int numSpaces, int grid[ROW_SIZE][COL_SIZE])
{
	//Used to keep track of the amount of spaces ACTUALLY moved, which may differ from numSpaces if a bound is reached
	int movementCount = 0;

	//If statements used to output based on the current direction
	if(direction == EAST)
	{
		for(int i = 0; i < numSpaces; i++)
		{
			if(xPos + 1 >= ROW_SIZE)
				return movementCount;

			xPos += 1;
			if(penIsDown)
				draw(grid);
			movementCount++;
		}
	}
	else if(direction == SOUTH)
	{
		for(int i = 0; i < numSpaces; i++)
		{
			if(yPos + 1 >= COL_SIZE)
				return movementCount;

			yPos += 1;
			if(penIsDown)
				draw(grid);
			movementCount++;
		}
	}
	else if(direction == WEST)
	{
		for(int i = 0; i < numSpaces; i++)
		{
			if(xPos - 1 < 0)
				return movementCount;

			xPos -= 1;
			if(penIsDown)
				draw(grid);
			movementCount++;
		}
	}
	else if(direction == NORTH)
	{
		for(int i = 0; i < numSpaces; i++)
		{
			if(yPos - 1 < 0)
				return movementCount;

			yPos -= 1;
			if(penIsDown)
				draw(grid);
			movementCount++;
		}
	}
	return movementCount;
}

/*
* Prints out the entire grid, using * to indicate positions of 1 and + to indicate the current location of the "turtle"
*/
void drawGrid(int grid[ROW_SIZE][COL_SIZE])
{
	for(int i = 0; i < ROW_SIZE; i++)
	{
		for(int j = 0; j < COL_SIZE; j++)
		{
			if(i == yPos && j == xPos)
				printf(" + ");
			else
			{
				if(grid[i][j] == 1)
					printf(" * ");
				else
					printf("   ");
			}
		}
		printf("\n");
	}
}
//End of program