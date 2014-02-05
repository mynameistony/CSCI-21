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
void hello();
void printMessage(string message);
int getAnswer();
int findLarger(int n1, int n2);
int getStats(string s, int& alphaCount, int& digitCount);
string buildMessage(string s, bool allCaps);
string buildMessage(string s);
string buildMessage();


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
    cout << "Hello world!";
}

void printMessage(string message){
    cout << message;
}

int getAnswer(){
    return 42;
}

int findLarger(int n1, int n2){
    if (n1>=n2)
        return n1;
    if (n2>=n1)
        return n2;
}

int getStats(string s, int& alphaCount, int& digitCount){
    alphaCount = 0;
    digitCount = 0;
    
    int asciiChar = 0;
    for (int i = 0; i < s.length(); i++){
        asciiChar = s[i];
        if((asciiChar >= 65 && asciiChar <= 90) || (asciiChar >= 97 && asciiChar <= 122))
            alphaCount++;
        if(asciiChar >= 48 && asciiChar <=57)
            digitCount++;
    }
    return s.length();
}

string buildMessage(string s, bool allCaps){
    string message = "Message: ";
    
    if (s == "")
        return "Message: empty";
    else{
        if(allCaps){
            for (int i = 0; i < s.length(); i++)
                s[i] = toupper(s[i]);
            return message + s;
        }
        else
            return message + s;
    }
    
}

string buildMessage(string s){
    string message = "Message: ";
    return message + s;
}

string buildMessage(){
    return "Message: empty";
}
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