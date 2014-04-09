#pragma once

#include <string>
#include <iostream>

using namespace std;

class Prize {
    
    friend class Box;

public:
    
   	friend bool operator== (Prize& prize1, Prize& prize2);

   	friend bool operator> (Prize& prize1, Prize& prize2);

   	friend bool operator< (Prize& prize1, Prize& prize2);

    ~Prize();

    Prize(string prizeName = "No name", int prizeValue = 0);

    string getPrizeName();

    int getPrizeValue();

    void setPrizeName(string newName);

    void setPrizeValue(int newValue);
    
    

private:

    string _prizeName;

    unsigned int _prizeValue;
};
