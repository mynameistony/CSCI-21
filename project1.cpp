/*
 * Project1
 * 
 *
 * Tony Rogers
 * Date created: 1/27/14
 * Last date modified: 1/31/14
 *
 * SOURCES USED
 * My Brain
 */

#include <iostream>
#include <cstring>
using namespace std;

void countCharacters (string theString, int& alpha, int& count);

string upAndDown (string theString);

int countWords (string theString);

int computeAverage (int values [], int arraySize);

int findMinValue (int values [], int arraySize);

int findMaxValue (int values [], int arraySize);

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int array2[] = {123,543,215,235,234,234,634,223,234,453};
    
    int alpha = 0;
    int count = 0;
    
    countCharacters("this is a test 123", alpha, count);
    
    cout << alpha << "\t" << count << endl;
    
    cout << upAndDown ("tHiS IS A tEsT") << endl;
    
    cout << countWords ("How many words is this?") << endl;
    
    cout << computeAverage(array, 10) << endl;
    
    cout << findMinValue(array2, 10) << endl;
    
    cout << findMaxValue(array2, 10) << endl;
    
}



// Returns the highest value in an array
//
// @param values[]: the array to use
// @param arraySize: the size of the array
// @return: returns the highest value in the array
int findMaxValue(int values[], int arraySize){

//Set the variable storing the max to zero
int max = 0;

        //Loop thru the array
        for ( int i = 0;  i < arraySize;  ++i){
                //If the current value is higher than the stored highest...
                if ( values[i] > max)
                //Set it as the new highest
                max = values[i];
        }
//Return the highest value
return max;
}


// Returns the lowest value in an array
//
// @param values[]: the array to use
// @param arraySize: the size of the array
// @return: returns the smallest value in the array
int findMinValue(int values[], int arraySize){

//Set the variable to a high value (if set to zero no value will be smaller than it)
int min = 1000000;
    
    //Loop thru the array
	for ( int i = 0;  i < arraySize;  ++i){
    		//If the current value is less than the stored lowest
    		if ( values[i] < min)
    		//Set it as the new lowest
         	min = values[i];
	}
//Return the smallest value
return min;
}

// Calculates the average number in an array
//
//@param values[]: the array to find the average of
//@param arraySize: the size of the array (Imagine that!)
//@return: the calculated average
int computeAverage(int values[], int arraySize){
//Set variables to zero
int average = 0;
int total = 0;

//Loop thru array
for (int i = 0;i < arraySize; i++){
//Add the current value to the total
total+=values[i];
}

//Calculate the average
average = total/arraySize;

//Return the average
return average;
}


// Counts the words in a given string (seperated by spaces)
//
// @param theString: the string to use
// @return: the number of words in theString
int countWords (string theString){

//Assume at least one word is in the string
int count = 1;

//Store the length of the string
int length = theString.length();

//Variable to hold the current character
char currChar;

//Loop thru the string
for (int i = 0; i < length; i++){

//Set the current character
currChar = theString.at(i);

//If the character is a space increment the word count
if (currChar == ' ')
count++;
}

//Return the count
return count;
}


// Counts the number of Alpabetic and Numerical characters in a string
//
// @param theString: The string to use
// @param alpha: the variable holding the number of alphabetical characters
// @param num: the variable holding the number of numerical characters
void countCharacters(string theString, int& alpha, int& num){
    //Store the length of the string
    int length = theString.length();
    
    //Store the current char as an Integer to compare its ascii values
    int currentChar;
    
    //Loop thru the array
    for (int i = 0; i < length; i++){
        
        //Set the current character
        currentChar = theString.at(i);

        //If the ASCII value is in the range of alphabetic characters...
        if ((currentChar >= 65 && currentChar <= 90) || (currentChar >= 97 && currentChar <= 122))
        //Increment the alphabetic count
        alpha++;
        
        else 
        //If the ASCII value is in the range of numerical characters....
        if (currentChar >= 48 && currentChar <= 57)
        //Increment the numerical count
        num++;
    }
}

// Capitalizes the first letter of a string and lowercases the rest
// 
// @param theString: theString to capitalize
// @return: @theString capitalized
string upAndDown(string theString){

//Store th length of the string    
int length = theString.length();

//Variable holding the current character
char currChar;

//Loop the array
for(int i = 0; i < length; i++){

//Set current character
currChar = theString.at(i);

//If its the first iteration (the first character of the string)
if(i == 0)
//Capitalize the character
theString[i] = toupper(currChar);


//Otherwise lowercase the current character 
else 
theString[i] = tolower(currChar);
}
    //Return the modified string
    return theString;
}