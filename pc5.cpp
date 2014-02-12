/*
 * Programming Challenge 5
 */
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <streambuf>
using namespace std;

// CODE HERE -- FUNCTION DECLARATIONS/PROTOTYPES

// No return or param, only prints "Hello world!" to std out
void hello();

// @param message: the message that will be printed to std out
// No return
void printMessage(string message);

// @return: Returns the number 42
int getAnswer();

// @param n1: the 1st number to compare
// @param n2: the 2nd number to compare
// @return: the larger of n1 and n2
int findLarger(int n1, int n2);

// @param s: the string to test
// @param &alphaCount: the number of alphabetical characters in "s"
// @param &digitCount: the number of numerical characters in "s"
// @return: the length of "s"
int getStats(string s, int& alphaCount, int& digitCount);

// @param s: the string to build from
// @param allCaps: if true, make the whole string caps
// @return: "s" concatenated to "Message: "
string buildMessage(string s = "", bool allCaps = false);


/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[])
{
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS
void hello(){
    
    //Print "Hello World!"
    cout << "Hello world!";
}

void printMessage(string message){
    
    // Print "message"
    cout << message;
}

int getAnswer(){
    
    // Return the answer to life, the universe, and everything
    return 42;
}

int findLarger(int n1, int n2){
    // If the first number is greater than or equal to the second, return it
    if (n1>=n2)
        return n1;
    // If the second number is greater than or equal to the first, return it
    if (n2>=n1)
        return n2;
}

int getStats(string s, int& alphaCount, int& digitCount){
    // Set the counts to zero
    alphaCount = 0;
    digitCount = 0;
    
    // Variable to hold the current char as an int, to read the ascii value 
    int asciiChar = 0;
    
    // Loop thru the string
    for (int i = 0; i < s.length(); i++){
        
        // Set the current char to its ascii value
        asciiChar = s[i];
        
        // If its in the alphabetical range...
        // ..Increase alphaCount
        if((asciiChar >= 65 && asciiChar <= 90) || (asciiChar >= 97 && asciiChar <= 122))
            alphaCount++;
            
        // If its in the number range...
        // ...Increase digitCount
        if(asciiChar >= 48 && asciiChar <=57)
            digitCount++;
    }
    
    // Still have to return the length
    return s.length();
}

string buildMessage(string s, bool allCaps){
    
    // Initialize string to hold the message
    string message = "Message: ";
    
    // Check if the string is empty...
    // ... If it is return "Message empty"
    if (s == "")
        return "Message: empty";
    // If it not empty
    else{
        
        // If message should be all caps...
        if(allCaps){
            // ...Make it so...
            for (int i = 0; i < s.length(); i++)
                s[i] = toupper(s[i]);
            // ... and return    
            return message + s;
        }
        
        // Otherwise return the message
        else
            return message + s;
    }
    
}

// string buildMessage(string s){
//     string message = "Message: ";
//     return message + s;
// }

// string buildMessage(){
//     return "Message: empty";
// }
/*
 * Unit testing functions. Do not alter.
 */

void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";
	
	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;
	cout.rdbuf(captureCout.rdbuf());
	
	hello();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(captureCout.str() == "Hello world!");
		cout << "Passed TEST 1: hello()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 1 hello() #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	printMessage("Hello again!");
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(captureCout.str() == "Hello again!");
		cout << "Passed TEST 2: printMessage(\"Hello again!\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 2 printMessage(\"Hello again!\") #\n";
	}
	
	try {
		btassert<bool>(getAnswer() == 42);
		cout << "Passed TEST 3: getAnswer()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 3 getAnswer() #\n";
	}
	
	try {
		btassert<bool>(findLarger(-1, 1) == 1);
		cout << "Passed TEST 4: findLarger(-1, 1)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 4 findLarger(-1, 1) #\n";
	}
	
	try {
		btassert<bool>(findLarger(1, -1) == 1);
		cout << "Passed TEST 5: findLarger(1, -1)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 5 findLarger(1, -1) #\n";
	}
	
	try {
		btassert<bool>(findLarger(1, 1) == 1);
		cout << "Passed TEST 6: findLarger(1, 1)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 6 findLarger(1, 1) #\n";
	}
	
	int alpha=0, digit=0;
	try {
		btassert<bool>(getStats("abc 123", alpha, digit) == 7 && alpha == 3 && digit == 3);
		cout << "Passed TEST 7: getStats(\"abc 123\", alpha, digit)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 7 getStats(\"abc 123\", alpha, digit) #\n";
	}
	
	try {
		btassert<bool>(getStats("abc", alpha, digit) == 3 && alpha == 3 && digit == 0);
		cout << "Passed TEST 8: getStats(\"abc\", alpha, digit)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 8 getStats(\"abc\", alpha, digit) #\n";
	}
	
	try {
		btassert<bool>(getStats("123", alpha, digit) == 3 && alpha == 0 && digit == 3);
		cout << "Passed TEST 9: getStats(\"123\", alpha, digit)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 9 getStats(\"123\", alpha, digit) #\n";
	}
	
	try {
		btassert<bool>(getStats("", alpha, digit) == 0 && alpha == 0 && digit == 0);
		cout << "Passed TEST 10: getStats(\"\", alpha, digit)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 10 getStats(\"\", alpha, digit) #\n";
	}
	
	try {
		btassert<bool>(buildMessage("hello") == "Message: hello");
		cout << "Passed TEST 11: buildMessage(\"hello\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 11 buildMessage(\"hello\") #\n";
	}
	
	try {
		btassert<bool>(buildMessage("hello", true) == "Message: HELLO");
		cout << "Passed TEST 12: buildMessage(\"hello\", true)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 12 buildMessage(\"hello\", true) #\n";
	}
	
	try {
		btassert<bool>(buildMessage("HELLO", false) == "Message: HELLO");
		cout << "Passed TEST 13: buildMessage(\"HELLO\", false)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 13 buildMessage(\"HELLO\", false) #\n";
	}
	
	try {
		btassert<bool>(buildMessage("HELLO", true) == "Message: HELLO");
		cout << "Passed TEST 14: buildMessage(\"HELLO\", true)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 14 buildMessage(\"HELLO\", true) #\n";
	}
	
	try {
		btassert<bool>(buildMessage() == "Message: empty");
		cout << "Passed TEST 15: buildMessage()\n";
	} catch (bool b) {
		cout << "# FAILED TEST 15 buildMessage() #\n";
	}
	
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}