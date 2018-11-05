//Paul Warmuth, warmu017, 5447548
//EE1301F18 Homework 5 Problem 1


#define FILENAME "sample-text.txt"

#include <stdio.h>
#include <stdlib.h>
//constructors
int readFile();
void Tabulate(int, int characterArray[], int*); //take a character and the pointer to a character array
void displayGraph(int characterArray[], int upperCaseCount);
int determineMaxValue(int characterArray[]);

//this function calls readFile(), and determines if it finished correctly.
int main()
{
	if(readFile() == 2)
	{
		printf("Unable to open file\n");
	}
	return 0;

}

//opens FILENAME in the local folder, reads the file character by character
// until it reads an EOF. Sends each character off to tabulate(). Returns 2 if
// the file was unable to be opened
int readFile()
{
	FILE* filePointer;
	filePointer = fopen(FILENAME, "r");
	if(filePointer == NULL) return 2; //unable to open file
	int characterArray[25] = {0}; //array for storing counts of lower case letters
	int upperCaseCount = 0;
	while(!feof(filePointer))
	{
		int character = fgetc(filePointer);
		Tabulate(character, characterArray, &upperCaseCount);
		//printf("%c", character);

	}
	fclose(filePointer);
	// printf("Reached EOF\n");
	displayGraph(characterArray, upperCaseCount);
	printf("Number of non-lower-case letters: %d\n", upperCaseCount);
}

//tabulates the characters passed to it into an array which counts their occurances
//if they are lower case.
// Takes an input character formatted as an integer a pointer to the characterArray[],
// and a pointer to upperCaseCount
void Tabulate(int character, int characterArray[], int* upperCaseCount)
{
	if(character >= 97 && character <= 122)
	{
		characterArray[character-97]++;
	}
	else if(character >= 65 && character <= 90)
	{
		(*upperCaseCount)++;
	}
}

//takes the pointer to the finished characterArray and displays a histogram
//scaled to maxValue. A non-zero count will at minimum give 1 # on output.
void displayGraph(int characterArray[], int upperCaseCount)
{
	float maxValue = determineMaxValue(characterArray);
	for(int i = 0; i < 26; i++)
	{
		float num1 = characterArray[i]; //the count for a lower case letter
		int xCount = 0; //the numnber of hashes to be displayed
		if (num1 > 0)
		{
			xCount = (int)((num1/maxValue) * 40);
			if(!xCount)
			{
				xCount = 1;
			}
		}
		else xCount = 0;
		//the extra variables in the below print are for debugging.
		printf("Number of occurances: %f, Max Occurances: %f, # of X to print: %d %c: ", num1, maxValue, xCount, 97 + i);
		for(int i = 0; i < xCount; i++)
		{
			printf("X");
		}
		printf("\n");
	}
}

//scans through characterArray[] and returns the maximum value in the array.
//the maximum value is used for scaling in displayGraph()
//takes a pointer to characterArray[]
int determineMaxValue(int characterArray[])
{
	int maxValue = 0; //holds the maximum value encountered in characterArray[]
	for(int i=0; i < 26; i++)
	{
		if(maxValue < characterArray[i])
		{
			maxValue = characterArray[i];
		}
	}
	return maxValue;
}
