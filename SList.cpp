#include "SList.h"
#include "SLNode.h"
#include <sstream>
#include <iostream>

SList::SList(){
head = NULL;
size = 0;
}


SList::~SList(){
    clear();
}

void SList::insertHead(int nodeContents){
    SLNode* newNode = new SLNode(nodeContents);
    
    newNode->setNextNode(head);
    
    head = newNode;
    
    size++;
    
}

void SList::insertTail(int nodeContents){
    
    if(head == NULL){
        insertHead(nodeContents);
    }
    else{
        SLNode* temp = new SLNode(nodeContents);
        
        SLNode* i = head;
        
        while(i->getNextNode() != NULL){
            i = i->getNextNode();
        }
        
        i->setNextNode(temp);
        size++;
    }
    
}
  
void SList::removeTail(){
    

    if(head != NULL){
        SLNode* i = head;
        SLNode* trail = head;
        
        while (i->getNextNode() != NULL){
            trail = i;
            i = i->getNextNode();
        }
        
        if(i == trail){
            delete i;
            
            head = NULL;
            
            size--;
        }else{
        
        delete i;
        
        trail->setNextNode(NULL);
        size--;
        }
    }
    
}
void SList::removeHead(){
    
    if(head != NULL){
        SLNode* temp = head;
        head = head->getNextNode();
        delete temp;
        size--;
    }
    
}
  
void SList::clear(){
    while(head != NULL){
        removeHead();
    }
}
  
unsigned int SList::getSize() const{
    return size;
}
  
string SList::toString() const{
    string theString = "";
    stringstream stream;
    int currNum;
    if(head != NULL){
    SLNode* i = head;
        
    while(i->getNextNode() != NULL){
        i = i->getNextNode();
        
        currNum = i->getContents();
        
        stream << currNum << ',';
    }
    theString = stream.str();
    
    // cout <<"\n" << "The String: " << theString << "\n";
    
    return theString;
    }
    else
    return "";
}