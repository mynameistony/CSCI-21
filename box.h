#pragma once

#include <string>

#include <iostream>

#include "prize.h"

using namespace std;

class Box {
    
    friend class Prize;
    public:

        ~Box();

        Box(int boxNumber = 0, string boxColor = "NO COLOR", int prizeCapacity = 5, int prizeCount = 0);

        int getBoxNumber();

        Prize* createPrizeArray(unsigned int size);

	    void clearPrizeArray();

        void setBoxNumber(unsigned int boxNumber);

        string getBoxColor();

        void setBoxColor(string boxColor);

        int getPrizeCapacity();

        void setPrizeCapacity(unsigned int newCapacity);

        int getPrizeCount();

        bool addPrize(Prize prize);

        Prize& getPrize(unsigned int index);

        Prize removePrize(unsigned int index);

        // friend bool operator== (Bo:getPrize(unsigned int index), testPrize);
    private:

        unsigned int _boxNumber, _prizeCapacity, _prizeCount;

        string _boxColor;

        Prize _scratch;

        Prize* _prizes;
};
