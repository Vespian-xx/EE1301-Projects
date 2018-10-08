//Paul Warmuth, 5447548
//EE1301, Fall 2018
//Homework 2 Problem 2
#include <stdio.h>



//this function takes two user supplied values (x and a) as input, the second of which is repeatedly asked for
//This input is then run through an algorithm that calculates a*x^n + f(n-1), where n is the current iteration 
// f(0)=0

int main()
{
	int count = 0; //Keeps track of how many time the calulation has been run. 
	float x = 0; //this holds the first of two values entered by the user.
	float a = 0; //this holds the second, and all subsequent values entered by the user.
	float previousValue = 0; //keeps track of the output from the previous calculation. 
	float nthExponentialOfX = 0; //this is used to store the output of a for loop that calculates x^n.

	printf("Enter a non-zero value for x: ");
	scanf("%f", &x);
	printf("To exit the program, enter -999999\n");
	while(1)
	{		
		count++;
		nthExponentialOfX = x; // we need to preserve the original input. This will be used to calculate the exponential.
		printf("Enter a floating-point value for a: ");
		scanf("%f", &a);
		if(a < 0) //Because of the absolute values in relative error, we need a case for both pos and neg numbers. 
		{
			if(((a + 999999) / -999999) > 1E-7 ) //Checking if a = -999999 +/- 0.1
			{
				break;
			}
		}
		else
			if(((a - 999999)/ -999999) < 1E-7 )
			{
				break;
			}
		//f(0)= 0 ; We do not need a special case for it. 
		if(count == 1) //Only runs on the first time through this for loop. 
		{
			previousValue = a * x; // a*x^1
			printf("The value of f(%d): %lf\n", count, previousValue);
		}
		if(count >= 2) //On the second time through we can start calculating x^count 
		{
			for(int j = count; j > 1; j--) //finds x^count
			{
				nthExponentialOfX *= x;
			}
			previousValue = (a * nthExponentialOfX) + previousValue; // is is now 
			printf("The value of f(%d): %lf\n", count, previousValue);
		}

	}
	return 0;
}