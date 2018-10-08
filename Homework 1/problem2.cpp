/*
Name: Paul Warmuth
Student ID Number: 5447548
Course Number: EE1301
Term: Fall 2018
Lab/Assignment Number: HW 1 Prob 2
Date: SEP 06 2018
*/

#include <stdio.h>

//----LOCAL VARIABLE DESCRIPTIONS AND DECLARATIONS----//
float purchaseAmount = 0; //the original purchase amount, in dollars
float taxRate = 0; //the tax rate, suppied as a percentage and converted to decimal by the program. 

//function: main() 
//requests the purchase price and the sales tax percentage, the computes the amount taxed and the final purhcase price before
//providing the user with those values. 

int main() {
	printf("Enter the amount of the purchase: ");
	scanf("%f", &purchaseAmount);
	printf("Enter the tax rate: ");
	scanf("%f", &taxRate);
	printf("The amount of tax that you paid was: %f\n", purchaseAmount * taxRate / 100);
	printf("The total amount that you paid was: %f\n", purchaseAmount * (1 + taxRate / 100));
}
