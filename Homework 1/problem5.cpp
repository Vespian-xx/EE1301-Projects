/*
Name: Paul Warmuth
Student ID Number: 5447548
Course Number: EE1301
Term: Fall 2018
Lab/Assignment Number: Assignment 1 Problem 4
Date: SEP 06 2018
*/

#include <stdio.h>
//#include <math.h>

//----LOCAL VARIABLE DESCRIPTIONS----//

float sum = 0; //a running sum of all values entered
int min = 0; //the smallest value encountered
int max = 0; //the largest value encountered
//float average = 0;
int count = 0; //the number of entries made
int userInput = 0; //used for storing user input

//function: main() 
	//continually takes user input until the user enters -1. When this value is encountered, displays current min, max, # of values, and average.
int main()
{
	printf("Enter numbers >= 0. Enter -1 when finished for single variable statistics.\n");
	while(1)//this will run until broken
	{
		scanf("%d", &userInput);
		if (userInput >= 0)
		{
			if (count == 0) //this only occurs once, immediately after the first value is entered and before the couter is incremented. 
			{
				min = userInput;
				max = userInput;
			}
			if (userInput < min)
			{
				min = userInput;
			}
			if (userInput > max)
			{
				max = userInput;
			}
			sum = sum + userInput;
			++count;

		}
		if (userInput == -1) //run the calculations and exit
		{
			printf("Computing values...\n");
			printf("Total Numbers Entered: %d\n", count);
			printf("Average Value: %lf\n", sum / count);
			printf("Minimum Value: %d\n", min);
			printf("Maximum Value: %d\n", max);
			break;
		}
		if (userInput < -1) //error checking
		{
			printf("Please enter a value greater than -2. A value of -1 will run calculations and exit.\n");
		}
	}
}