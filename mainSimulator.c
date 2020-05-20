/*
 *
 *  Created on: Mar 20, 2018
 *      Author: Gilbert Alvarado
 *  Compiler Used: Eclipse Neon and CodeEnvy
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//ADDED LIBRARIES
#include <ctype.h>//TO UPPER AND TO LOWER

//GLOBAL VARIABLES
const char LETTERS[27] = {'A','B','C','D','E','F','G','H','I','J',
                          'K','L','M','N','O','P','Q','R','S','T',
						  'U','V','W','X','Y','Z', ' '};
const char ROTOR_VALUES[10] = {7, 3, 0, 1, 9, 5, 2, 6, 4, 8};
//ex: user enters: rotor1 = 4 --> index 4 = 9
//ex: user enters: rotor2 = 1 --> index 1 = 3
//ex: user enters: rotor3 = 7 --> index 7 = 6

const int ROTOR_SIZE = 10;
const int TEXT_SIZE = 256;
int rotorPosition1, rotorPosition2, rotorPosition3;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* findCharIndex:  Finds the location(index) of a character in the
    Letters array
 * Input:  Character to find in Letters Array
 * Output: Index location in the Letters Array
 * Note:  Returns -1 if not found
 */
int findCharIndex(char c)
{
    //TODO: Need to implement this function

	int i = 0;//start at first index of LETTERS[]
	int location = 0;//location returning
	bool looping = true;//for the while loop

	while(looping)//while looping = true, go through every element
	{
		//to prevent going beyond the actual size of the LETTERS array
		if(i == 27)
		{
			location = -1;//return -1 if not found
			looping = false;//end loop
		}
		else if(LETTERS[i] == c)//character located
		{
			location = i;
			looping = false;//stop looping/exit loop and return position
		}
		else
			++i;
	}

	return location;//either returning -1 or CHAR location
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*  mod:  Implements a true modulus function
 *  INPUT: original number (a) and dividor (b)
 *  OUTPUT: remainder
 *  NOTE:  Required since in C (%) does not implement true modulus
 *         function for negative remainders   */
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* encryptLetter:  Returns an encrypted letter (character)
 * INPUT:  unencrypted letter (character) and key
 * OUTPUT:  encrypted letter
 * return LETTERS[mod(findCharIndex(encrypted)+key, 27)];
 * this can be done in a single line
 * */
char encryptLetter(char unencrypted, int key)
{
	//TODO: Need to implement this function
	int location = findCharIndex(unencrypted);//locating letter location
	int eLetterIndex = mod((location + key), 27);//calculating encrypted letter index

	return LETTERS[eLetterIndex];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* decryptLetter:  Returns an decrypted letter (character)
 * INPUT:  encrypted letter (character) and key
 * OUTPUT:  decrypted letter
 *
 * return LETTERS[mod(findCharIndex(encrypted)-key, 27)];
 * this can be done in a single line
 * */
char decryptLetter(char encrypted, int key)
{
    //TODO: Need to implement this function
    int location = findCharIndex(encrypted);//locating letter location
	int eLetterIndex = mod((location - key), 27);//calculating decrypted letter index

	return LETTERS[eLetterIndex];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* getKey: returns key based on current positions of the rotors  */
int getKey()
{
	return ROTOR_VALUES[rotorPosition1]+ROTOR_VALUES[rotorPosition2]+ROTOR_VALUES[rotorPosition3];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* incrementRotors: Advances rotor positions by one
 * USAGE: Used after every letter is encrypted or decrypted  */
void incrementRotors()
{
	rotorPosition1++;
	if (rotorPosition1 == ROTOR_SIZE){//if r1 is at the last index
		rotorPosition1 = 0;
		rotorPosition2++;
	}
	if (rotorPosition2 == ROTOR_SIZE){//if r2 is at the last index
		rotorPosition2 = 0;
		rotorPosition3++;
	}
	if (rotorPosition3 == ROTOR_SIZE)//if r3 is at the last index
		rotorPosition3 = 0;
}
/*
 *function: bool validateRotors(int,int,int)
 *Pre:  rotor values are passed to determine if they're out of range
 *
 *Post: returns TRUE if the rotor's are out of range
 *		else returns false
 */
bool validateRotors(int r1, int r2 , int r3)//return true if rotors are out of range
{
	return ((r1 < 0 || r1 > 9) ||//checking each rotor
			(r2 < 0 || r2 > 9) ||//if any of the rotor's are out of range
			(r3 < 0 || r3 > 9));//the function returns true
}
/*
 * function: bool validateChar(char)
 * Pre: letter input is passed to determine if the letter is an option
 *
 * Post: return FALSE if user enters proper letter
 * 		else returns TRUE
 */
bool validateChar(char letter)//check if letter input is e or d
{
	return ((letter != 'e') && (letter != 'd'));
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main( int argc, char *argv[] )
{
	//##################################
		setbuf(stdout, NULL);//eclipse issue
	//##################################

	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~ASSIGNMENT 3~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~ENIGMA MACHINE~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("For testing: SECRET MESSAGE for ENCRPYTING [Set rotors to: 4 1 7]\n");
	printf("For testing: JSNFRJMVKZGLOQ for DECRYPTING\n\n");
	printf("Input 4 arguments: int int int char[e or d]\n");
	printf("int must be between 0 <= int <= 9\n\n");

	//STEP #1: Get and check Command Line Arguments
	//TODO:  Implement this step
	char letter;
	//if the user doesn't the correct amount of command lines, have them enter them

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//execute from CMD
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	if(argc != 5)
//	{
//		printf("ENTER CORRECT AMOUNT OF ARGUEMENTS...: ");
//
//		//assign them to their respective variable
//		scanf("%d %d %d %c", &rotorPosition1, &rotorPosition2, &rotorPosition3, &letter);
//		//ASSUMING USER ENTERS CORRECT DATA TYPE VALUES
//	}
//	else
//	{//assign argv's to their respective variable
//
//		rotorPosition1 = atoi(argv[1]);//assuming user enters numbers
//		rotorPosition2 = atoi(argv[2]);
//		rotorPosition3 = atoi(argv[3]);
//		letter = tolower(*argv[4]);//assign char[4] to letter
//					//NOTE: dereference argv[4] to access data!
//	}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//end of CMD
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*
     * for program readability, I created two functions
     * 1: validateRotors: this function determines whether the rotor's that the
     * 	    user input is in range. If it's OUT of range, the function returns true.
     *
     * 2: validateChar: determines whether the user entered a correct letter to execute
     *      the appropriate function. It returns true IF the letter doesn't match
     *      letter's e AND/or d
     */

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//eclipse IDE
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	scanf("%d %d %d %c", &rotorPosition1, &rotorPosition2, &rotorPosition3, &letter);//USER INPUT
	letter = tolower(letter);

    //if rotor's are out of range OR the letter doesn't match 'e' AND/OR 'd'
    //the user will have to enter valid input's until the conditions are met.
    if((validateRotors(rotorPosition1, rotorPosition2, rotorPosition3)||
    		validateChar(letter)) == true)
    {
      do
    	{
			printf("\n\nERROR: invalid inputs... enter proper values:\n");

			//letting the user know what's wrong with their inputs...
			if(validateRotors(rotorPosition1, rotorPosition2, rotorPosition3) == true)
				printf("HINT: rotor's are out of range...\n");

			if(validateChar(letter) == true)
				printf("HINT: invalid letter...\n");

			scanf("%d %d %d %c", &rotorPosition1, &rotorPosition2, &rotorPosition3, &letter);
			letter = tolower(letter);
    	}//keep prompting user until valid inputs are entered
    	while(validateRotors(rotorPosition1, rotorPosition2, rotorPosition3)||
    			validateChar(letter) == true);
    }

    //once the data meets the conditions, the values of each input is displayed
	printf("\nRotor #1 Position is set to %d\n", rotorPosition1);
	printf("Rotor #2 Postion is set to %d\n", rotorPosition2);
	printf("Rotor #3 Position is set to %d\n", rotorPosition3);

	//letting the user know which action is going to execute
	printf("char value: %c ", letter);
	if(letter == 'e')
        printf("-- Action: Encrypting\n");
	else
		printf("-- Action: Decrypting\n");

    //STEP #2: Get text string from user
	char inputText[TEXT_SIZE];
	char outputText[TEXT_SIZE];

	printf("\nEnter text: ");
	//NOTE: YOU MUST PLACE A SPACE BEFORE %c or %s WHEN YOU'RE
	//EXPECTING A STRING INPUT
	scanf( " %[^\n]s" , inputText ); //%20 includes spaces

	for(int i = 0; inputText[i] != '\0'; ++i)
    	inputText[i] = toupper(inputText[i]);//Capitalizing each letter
					 //touper() is from the ctype.h library

	printf("\nInput text supplied: %s\n\n", inputText);//displaying string from user input

	int input_text_size = strlen(inputText) - 1;//minus 1 to ignore \n char


    //STEP #3: For each letter, encrypt or decrypt

    //within the loop, assign values to outputText
	if(letter == 'e')
		for (int i = 0;i <= input_text_size; i++)
		{
    		outputText[i] =  encryptLetter(inputText[i], getKey());
			incrementRotors();//increment rotors for every loop/letter
		}
    else
    	for (int i = 0;i <= input_text_size; i++)
    	{
    		outputText[i] = decryptLetter(inputText[i], getKey());
    		incrementRotors();//increment rotors for every loop/letter
    	}


    //STEP #4: Print result
    outputText[input_text_size+1] = '\0';//adding NULL char at the end of string

	if(letter == 'e')//printing crypted string
		for(int i = 0; outputText[i] != '\0'; ++i)
			printf("unecrypted Letter: %c | encrypted Letter: %c\n",inputText[i], outputText[i]);
	else//printing decrypted string
		for(int i = 0; outputText[i] != '\0'; ++i)
			printf("encrypted Letter: %c | decrypted Letter: %c\n",inputText[i], outputText[i]);

	printf("\nOutput text: %s\n\n", outputText);//printing final result


	return EXIT_SUCCESS;
}
