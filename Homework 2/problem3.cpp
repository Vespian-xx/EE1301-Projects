/*Program needs: psudorandomnumber generation. Does not need all to be to be stored as a variable (if possible). 
Use logic to check if it was the same as the last number. Continuously prompt user for a number. Generate random
 number between 1 and that number, and return 4of these random numbers in a X X X X pattern. Like a slot machine.
*/

/*Paul Warmuth, 5447548
EE1301 Fall 2018
Homework 2 - Problem 3*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*This function acts as a slot machine, returning 4 random values between 1 and numRange. The user wins if
the numbers all match. */
int main()
{

	//--- BEGIN LOCAL VARIABLE DECLARATIONS---//
	int numRange = 0;  //Stores user's preference for the range of numbers from 1-numRange on the wheels 
	int previousNum = 0; //This stores the value of the previous columns number. It is used in the logic for determining a win condition. 
	int currentNum = 0;
	int winCondition = 1; //Used for the storing the logic result for the win condition.
	//---END LOCAL VARIABLE DECLARATIONS---//

	srand(time(NULL)); //Generates seed for rand() with the current unix time as an argument. 
	printf("How many numbers do you want on each wheel? ");
	scanf("%d", &numRange);
	while(1)
	{
		if (numRange < -1)
		{
			printf("Enter a number greater than -2. ");
			scanf("%d", &numRange);
			continue;
		}
		if (numRange == -1)
		{
			printf("OK, Goodbye.\n");
			break;
		}
		if (numRange == 0)
		{
			printf("Zero is not an option. Try again. ");
			scanf("%d", &numRange);
			continue;
		}
	previousNum = ((int)rand() % numRange) + 1; //Provides the first columns number, and feeds this into following for() loop
	printf("The wheels spin to give: %d", previousNum);
		for(int i = 0; i < 3; i++) // generates the next 3 random numbers, and provides the logic for a win condition by comparing the current number to the last. 
		{
			currentNum = ((int)rand() % numRange) + 1;
			if ((currentNum == previousNum) && (winCondition == 1)) //Only continues flagging the win if the previous numbers all match as well. 
			{
				previousNum = currentNum;
			}
			else 
			{
				winCondition = 0;
				previousNum = currentNum;
			}
			printf(" %d", currentNum);
		}
		if(winCondition == 1)
		{
			printf(". Eureka!\n");
			previousNum = ((int)rand() % numRange) + 1; //We've finished the previous set of four. We now need a new starting number. 
			break;
		}
		else
		{
			printf(". You lose!\n");
			winCondition = 1; //resetting for next loop. 
			previousNum = ((int)rand() % numRange) + 1; //Same reason here as the previous. 
		}
	}
}
