//Paul Warmuth, 5447548
//EE1301
//September 19, 2018
//Homework 2 Problem 1

#include <stdio.h>

//This function takes the users input and displays a series of integers based on that input.
//Exits when the user enters 0.
int main()
{
	int userInput = 0; //This variable will be used to store user input. 
	int currentInt = 0; //Stores the current integer within the for loops. 
	while(1)
	{
		printf("Enter a number between -50 and 50, enter 0 to exit.");
		scanf("%d", &userInput);
		/* This section is for positive numbers. It prints a pattern that has 1 on the first line, 22 on the second line, 
		 * 333 on the third line, and so on up to the value of the number entered. */ 
		if((userInput > 0) && (userInput <= 50)) 
			/* IF POSITIVE: Will print like this up to the number the user entered
			1
			22
			333
			4444
			55555
			*/
		{
			for(int i = 1; i <= userInput; i++) 
			{
				for(int j = 1; j <= i; j++) 
				{
					printf("%d", i);
				}
				printf("\n");
			continue;
			}
		}
		/* IF NEGATIVE: Will print the pattern from the previous section in the opposite direction.*/
		if((userInput < 0) && (userInput > -50))
		{
			for(int i = userInput * (-1); i>0; i--)
			{
				for(int j = i; j > 0; j--) 
				{
					printf("%d", i);
				}
				printf("\n");
			continue;
			}
		}
		if(userInput == 0)
		{
			printf("Goodbye\n");
			break;
		}
	}
	return 0;
}
