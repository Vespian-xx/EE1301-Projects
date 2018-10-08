/*
Name: Paul Warmuth
Student ID Number: 5447548
Course Number: EE1301
Term: Fall 2018
Lab/Assignment Number: Assignment 1 Problem 4
Date: SEP 06 2018
*/
#include <stdio.h>
#include <math.h>
//----LOCAL VARIABLE DESCRIPTIONS----//
double factorialNumber = 0; //this variable stores user input and is later used to store the intermediate values as the factorial is being calculated. 

// Function: main()
// ---------------------------
//Continually prompts the user for a number, and then returns the factorial of that number. 

int main(){
	while(1){ //this will run until broken
		printf("Please enter a decimal number: ");
		scanf("%lf", &factorialNumber);
		//printf("\n%lf\n", userInput);
		//factorialNumber = userInput;
		for(int i = factorialNumber; i > 1; --i) { //this will loop as many times as needed to calculate the factorial of the number the user entered. 
			factorialNumber = factorialNumber*(i - 1);
		}
		printf("The factorial of this number is: %lf\n", factorialNumber);
	}
	return 0;
}