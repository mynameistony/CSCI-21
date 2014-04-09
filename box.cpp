#include <string>
#include <iostream>
using namespace std;

#include "box.h"
#include "prize.h"

Box::~Box(){

}

Box::Box(int boxNumber, string boxColor, int prizeCapacity, int prizeCount){
    
    _boxNumber = boxNumber;
    _boxColor = boxColor;
    _prizeCapacity = prizeCapacity;
    _prizeCount = prizeCount;
    _prizes = createPrizeArray(prizeCapacity);
    
}

void Box::clearPrizeArray(){
   delete [] _prizes;
   
   _prizes = NULL;
}

Prize* Box::createPrizeArray(unsigned int size){
    Prize* array = new Prize[size];
    
    return array;
}

int Box::getPrizeCount(){
    return _prizeCount;
}

int Box::getPrizeCapacity(){
    return _prizeCapacity;
}

void Box::setBoxColor(string color){
    _boxColor = color;
}

string Box::getBoxColor(){
    return _boxColor;
}

void Box::setBoxNumber(unsigned int number){
    _boxNumber = number;
}

int Box::getBoxNumber(){
    return _boxNumber;
}

Prize& Box::getPrize(unsigned int index){
    if(index < _prizeCapacity){
        return _prizes[index];
    }
    else
        return _scratch;
}

bool Box::addPrize(Prize prize){
    if(_prizeCount < _prizeCapacity){
        _prizes[_prizeCount++] = prize;
        
        return true;
    }   
        else
        return false;
}

// bool operator== (Box::getPrize(unsigned int index), Prize& testPrize){
   
// 	if(getPrize(index) == prize1){
//     // if(true){
// 		return true;
// 	}
// 		else 
// 		return false;
// }

