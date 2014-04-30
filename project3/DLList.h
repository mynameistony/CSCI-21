#pragma once

#include <sstream>
#include <string>
#include "DLNode.h"
#include  <cstdlib>


using namespace std;


class DLList
{
    public:
        DLList();
        virtual ~DLList();
        
        void insert(int value);
        
        void pushFront(int value);
        void popFront();
        int getFront();
        
        void pushBack(int content);
        void popBack();
        int getBack();
        
        void clear();
        
        unsigned int getSize() const;
        
        string toString () const;
        
        bool get(int value);
        
        bool removeFirst(int value);
        
        bool removeAll(int value);
        
        //NEED TO FIX
        friend ostream& operator<< (ostream& out, DLList& list){
        out << list.toString();
        return out;
    	}
    	//NEED TO FIX
    
    private:
        DLNode* head;
        DLNode* tail;
        unsigned int size;
};