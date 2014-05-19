#pragma once

#include <string>
#include <sstream>

using namespace std;
class Item{
    
    public:
        
        ~Item(){}

        Item(string newName = "item", unsigned int newValue = 0){
            
            name = newName;
            
            value = newValue;
        }
        
        void setName(string newName){
            name = newName;
        }
        
        string getName(){
            return name;
        }
        
        void setValue(int newValue){
            value = newValue;
        }
        
        unsigned int getValue(){
            return value;
        }
        
        string toString(){
            
            stringstream stream;
            
            stream << name << ", $" << value;
            
            return stream.str();
            
            
        }
    
    private:
    
        string name;
        
        unsigned int value;
};