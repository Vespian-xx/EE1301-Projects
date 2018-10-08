/*Paul Warmuth, 5447548
EE1301 Fall 2018
Homework 2 - Problem 4*/

#include <stdio.h> /*Needed for printf() and scanf()*/
#include <stdlib.h> /*Needed for rand() and srand()*/
#include <time.h> /*This is used to provide a seed for srand()*/

/*This function calculates the mathematical probability of all wheels (number given by columnwidth) having a matching number (ranges from 1-digitRange*/
double calculateProbability(double digitRange, int columnWidth) //columnWidth = numbrerof columns digitRange = number of possibilities per column
{
	double probability = 1; /*The probability of the first row being correct is 100%, and subsequent rows are 1/digitRange. */
	for(int i = 0; i < (columnWidth - 1); i++) /*calculate probability for the remaining rows*/
	{
		probability *= (1/digitRange);
	}
	return probability;
}

/*This "Rolls the wheels" per say. Returns 0 if the roll is a loss, returns 1 if it's a win. */
int roll_the_wheels(int digitRange, int columnWidth) /*Simulates a singe roll of [columnWidth] numbers, returns 1 if all numbers match*/
{
	int previousNum = (rand() % digitRange) + 1; /*Provides the first columns number, and feeds this into following for() loop*/
	
	for(int i = 1; i < columnWidth; i++) /*generates the next w-1 random numbers. Returns 1 if all numbers match*/
	{
		int currentNum = (rand() % digitRange) + 1;
		if (currentNum == previousNum) /*Only continues the loop if the numbers match. */
		{
			previousNum = currentNum;
		}
		else 
		{
			return 0; 
		}
	}
	return 1; /*only happens if all numbers matched. */
}

/*This function runs a simulation to calculate the probability that all numbers on a slot machine (with columnIndex rows and digitIndex numbers per column) match, and then compares that with the calculated probabity in a display to the user*/
int main()
{
	srand(time(NULL)); /*Generates seed for rand(). */

	/* BEGIN LOCAL VARIABLE DECLARATIONS */
	double winCount = 0; /*Stores the number of times the result has been a loss*/
	double loseCount = 0; /*Stores the number of times the result has been a win*/
	/* END LOCAL VARIABLE DECARLATIONS */

	for(int columnIndex = 3; columnIndex < 7; columnIndex++) //columnIndex will range from 3-6
	{
		for(int digitIndex = 9; digitIndex < 28; digitIndex += 3) //digitIndex will range from 9-27 in increments of 3
		{
			for(int runNum = 0; runNum < 1E6; runNum++)
			{
				if(roll_the_wheels(digitIndex,columnIndex) == 1)
				{
					winCount++;
				}
				else
					loseCount++;
			}
			printf("w = %d, d = %d: Simulated Probability m/n = %lf%%. Mathematical Probability = %lf%%\n", columnIndex, digitIndex, 100*winCount/(winCount+loseCount), 100*calculateProbability(digitIndex, columnIndex));
			winCount = 0;
			loseCount = 0; /*We need to reset these values after each simulation*/
		}
	}
}




