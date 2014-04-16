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

bool SList::removeFirst(int target){
    
    if(head == NULL)
        return false;
    else{
        SLNode* trail = NULL;
        SLNode* spot = head;
        
        while((spot != NULL) && (spot->getContents() != target)){
            trail = spot;
            spot = spot->getNextNode();
        }
        
        if(spot == NULL)
            return false;
        else if(spot == head){
                removeHead();
                return true;
            }
            
        else{
            //spots thinkin' Uh-Oh right about now
            trail->setNextNode(spot->getNextNode());
            delete spot;
            size--;
        }
    }
    
}

void SList::insert(int data){
    
    //Empty List
    if(head == NULL)
    {
        insertHead(data);
    }
        //Only One Node
        else if(head->getNextNode() == NULL)
        {
            
            //Check if DATA is greater or less than only Node
            if(data < head->getContents())
                insertHead(data);
            else
               insertTail(data);
        }
        else 
        {
            SLNode* trail = NULL;
            SLNode* spot = head;
            
            while((spot->getNextNode() != NULL) && (data > spot->getContents()))
            {
                trail = spot;
                spot = spot->getNextNode();
            }
            if((spot->getNextNode() == NULL) && (data > spot->getContents()))
                insertTail(data);
            else 
            {
                SLNode* nodee = new SLNode(data);
                nodee->setNextNode(spot);
                trail->setNextNode(nodee);
                size++;
            }
        }
                
        
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


    if(head == NULL){
        return "";
    } else 
        
        if(head->getNextNode() == NULL){
        stream << head->getContents();   
        
        theString = stream.str();
        
    } else{
    SLNode* i = head;
    int loop;
    while(i->getNextNode() != NULL){
        
        currNum = i->getContents();
        
        stream << currNum; 
        
        if(loop < size)
            stream << ',';
            
        i = i->getNextNode();
        loop++;
        
    }
    theString = stream.str();
    }
    // cout <<"\n" << "The String: " << theString << "\n";
    
    return theString;
    
    
}