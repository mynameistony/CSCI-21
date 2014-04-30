#include "DLNode.h"
#include "DLList.h"
#include <iostream>

using namespace std;

DLList::DLList()
: head(NULL), size(0)
{
}

DLList::~DLList()
{
    clear();
}

void DLList::pushFront(int value)
{
    DLNode* nodie = new DLNode(value);
    nodie -> setNextNode(head);
    head = nodie;
    size++;
}

void DLList::pushBack(int content)
{
    if(head == NULL)
    {
        pushFront(content); //this will increment the count, no need for size++ etc.
    }
    else
    {
        DLNode* temp(new DLNode(content));
        DLNode* i = head;
        while (i -> getNextNode() != NULL)
        {
            i = i -> getNextNode();
        }
        i -> setNextNode(temp);
        size++;
    }
}

void DLList::popFront()
{
	
    if (head != NULL)
    {
    
        DLNode* temp = head;
        head = head -> getNextNode();
        delete temp;
        size--;
    }
}

void DLList::popBack()
{
    if(head != NULL)
    {
        DLNode* i = head;
        DLNode* trailer = NULL;
        while(i->getNextNode() != NULL)
        {
            trailer = i;
            i = i -> getNextNode();
        }
        delete i;
        size--;
        if(trailer == NULL)
        {
            head = NULL;
        }
        else
        {
            trailer -> setNextNode(NULL);
        }
    }
}

void DLList::clear()
{
    while (head != NULL)
        popFront();
}

unsigned int DLList::getSize() const
{
    return size;
}

string DLList::toString () const {
    stringstream ss;
    
    for (DLNode* i = head; i != NULL; i = i -> getNextNode()) {
        ss << i ->getContents();
        if ((i -> getNextNode()) != NULL)
            ss << ',';
    }
    return ss.str();
}

void DLList::insert(int contents){
    if(head == NULL)
    {
        pushFront(contents);
    }
        //Only One Node
        else if(head->getNextNode() == NULL)
        {
            
            //Check if DATA is greater or less than only Node
            if(contents < head->getContents())
                pushFront(contents);
            else
               pushBack(contents);
        }
        else 
        {
            DLNode* trail = NULL;
            DLNode* spot = head;
            
            while((spot->getNextNode() != NULL) && (contents > spot->getContents()))
            {
                trail = spot;
                spot = spot->getNextNode();
            }
            if((spot->getNextNode() == NULL) && (contents > spot->getContents()))
                pushBack(contents);
            else 
            {
                DLNode* nodee = new DLNode(contents);
                nodee->setNextNode(spot);
                trail->setNextNode(nodee);
                size++;
            }
        }
                
        
}

int DLList::getFront(){
	return head->getContents();
}

int DLList::getBack(){
    if(head != NULL)
    {
        DLNode* i = head;

        while(i->getNextNode() != NULL)
        {

        	i = i -> getNextNode();
        }
        return i->getContents();
    }
    else
    	return head->getContents();
}

bool DLList::get(int value){
    if(head != NULL)
    {
        DLNode* i = head;
//        DLNode* trailer = NULL;
        while(i->getNextNode() != NULL)
        {
        	if(i->getContents() == value)
        		return true;
        	else
        	{
//            trailer = i;
            i = i -> getNextNode();
            }
        }
        
        	if(i->getContents() == value)
        		return true;
    }
    else
    	return false;	
}

bool DLList::removeFirst(int value){

	if(head == NULL)
		return false;
	else
	{
		DLNode* i = head;
		DLNode* trail = head;
		
		while (i -> getNextNode() != NULL)
		{
			if(i -> getContents() == value)
			{	

				trail->setNextNode(i->getNextNode());
				delete i;
				size--;
				
				
				return true;
					
			}
			trail = i;
			i = i->getNextNode();
		}
		
		return false;
	}
}

bool DLList::removeAll(int value){
	bool isFound = false;
        DLNode* prevNode = head;
        DLNode* currentNode = head;

        while(currentNode != NULL)
        {
               if(currentNode->getContents() == value)
               {
               		isFound = true;
                    if(currentNode == head)
                    {
                           head = currentNode->getNextNode();
                           delete currentNode;
                           prevNode = head;
                           currentNode = head;
                           size--;
                    }
                    else
                    {
                           prevNode->setNextNode(currentNode->getNextNode());
                           delete currentNode;
                           currentNode = prevNode->getNextNode();
                           size--;
                    }
   
               }
               else
               {
                       prevNode = currentNode;
                       currentNode = currentNode->getNextNode();
               }
         }
         
         if(isFound)
         	return true;
         else
         	return false;
}
/*
if(head == NULL)
		return false;
	else
	{
		DLNode* i = head;
		DLNode* trail = head;
		//DLNode* deleter = head;
		
		while (i -> getNextNode() != NULL)
		{

			if(i -> getContents() == value)
			{	trail 
				trail->setNextNode(i->getNextNode());

				isFound = true;

			}
			//trail = i;
			i = trail->getNextNode();
		}
		

		if(isFound)
			return true;
		else
			return false;
	}
	*/
