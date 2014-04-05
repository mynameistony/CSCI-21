#include <string>

#include <iostream>

using namespace std;

#include "prize.h"
#include "box.h"
Prize::~Prize(){}

Prize::Prize(string newName, int newValue){
    _prizeName = newName;
    _prizeValue = newValue;
}

string Prize::getPrizeName(){
    return _prizeName;
}

void Prize::setPrizeName(string newName){
    _prizeName = newName;
}

int Prize::getPrizeValue(){
    return _prizeValue;
}

void Prize::setPrizeValue(int newValue){
    _prizeValue = newValue;
}

bool operator== (Prize& prize1, Prize& prize2){
	if(prize1.getPrizeValue() == prize2.getPrizeValue()){
		return true;
	}
		else 
		return false;
}



// bool operator== (Box& box1(unsigned int index), Prize& prize){
// 	if(box1.getPrize(index) == prize.getPrizeValue()){
// 		return true;
// 	}
// 		else 
// 		return false;
// }

bool operator> (Prize& prize1, Prize& prize2){
	if(prize1.getPrizeValue() > prize2.getPrizeValue()){
		return true;
	}
		else 
		return false;
}

bool operator< (Prize& prize1, Prize& prize2){
	if(prize1.getPrizeValue() < prize2.getPrizeValue()){
		return true;
	}
		else 
		return false;
}


