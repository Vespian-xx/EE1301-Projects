/*
Name: Paul Warmuth
Student ID Number: 5447548
Course Number: EE1301
Term: Fall 2018
Lab/Assignment Number: HW 1 Prob 1
Date: SEP 05 2018
*/
#include <stdio.h>
//----LOCAL VARIABLE DESCRIPTIONS AND DECLARATIONS----//
float distanceInMiles; // Distance in Miles

//CONVERSION FACTORS: MILES TO X

#define CFKILOMETERS 1.60934// Conversion factor for MILES to KILOMETERS
#define CFMETERS 1609.34// Conversion factor for MILES to METERS
#define CFFURLONGS 7.99998// Conversion factor for MILES to FURLONGS
#define CFFEET 5280// Conversion factor for MILES to FEET
#define CFINCHES 63360// Conversion factor for MILES to INCHES

//----Function Header----//

// Function: convert_distances
// ---------------------------
// Prompts the user for a distance in miles, converts that distance to various units, and then displays the results before exiting.
int main()
{
	printf("Enter a Distance in Miles: ");
	scanf("%f", &distanceInMiles);
	printf("Converting this distance to...\n");
	printf("Kilometers: %lf\n", distanceInMiles * CFKILOMETERS);
	printf("Meters: %lf\n", distanceInMiles * CFMETERS);
	printf("Furlongs: %lf\n", distanceInMiles * CFFURLONGS);
	printf("Feet: %lf\n", distanceInMiles * CFFEET);
	printf("Inches: %lf\n", distanceInMiles * CFINCHES);
	return 0; 
}