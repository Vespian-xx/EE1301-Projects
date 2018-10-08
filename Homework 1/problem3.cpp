/*
Name: Paul Warmuth
Student ID Number: 5447548
Course Number: EE1301
Term: Fall 2018
Lab/Assignment Number: Assignment 1 Problem 3
Date: SEP 06 2018
*/
#include <math.h>
#include <stdio.h>

//----LOCAL VARIABLE DESCRIPTIONS----//
double sideA = 0; //One of the two sides to the traingle. 
double sideB = 0; //The second of two sides of the triangle. 

//NOTE: These sides need to be the sides adjacent to the right angle for this program to compute the hypotenuse correctly. 

//This function promts the user to enter two sides of a right triangle, then computes and displays the hypotenuse to the user. 
int main(){
	printf("Please enter the length of one leg of the right triangle.\n");
	scanf("%lf", &sideA);
	printf("Enter the length of the other leg.\n");
	scanf("%lf", &sideB);
	printf("The length of the hypotenuse is: %f\n", sqrt(sideA*sideA + sideB*sideB));
	return 0;
}
