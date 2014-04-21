#pragma once
#include<cstdlib>
#include<iostream>
using namespace std;
template<class T>

class Box {


public:

    friend ostream& operator<< (ostream& out, Box& box){
        out << box.contents;
        
        return out;
    }
 
    Box();
  
    Box(T newContents){
        contents = newContents;
    }
  
    T getContents(){
        return contents;
    }
  
    void setContents(T newContents){
        contents = newContents;
    }
    
    

  
private:
  
    T contents;
};



// template<class T>
// T Box<T>::getContents(){
    
//     T value = contents;
    
//     return value;    
// }