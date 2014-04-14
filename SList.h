#pragma once

#include "SLNode.h"

#include <cstdlib>
#include <string>

using namespace std;
class SList {
    
  
public:
  
    SList();
  
    ~SList();
  
    void insertHead(int nodeContent);
  
    void insertTail(int nodeContent);
  
    void removeHead();
  
    void removeTail();
  
    void clear();
  
    unsigned int getSize() const;
  
    string toString() const;
  
private:
  
    SLNode* head;
  
    unsigned int size;
    
};