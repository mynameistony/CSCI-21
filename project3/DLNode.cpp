#include "DLNode.h"

DLNode::DLNode()
: nextNode(NULL), prevNode(NULL), contents(0)
{
}

DLNode::DLNode(int newContents)
: nextNode(NULL), prevNode(NULL), contents(newContents)
{
}

DLNode::~DLNode(){
    nextNode = NULL;
    prevNode = NULL;
}

int DLNode::getContents() const{
    return contents;
}

DLNode* DLNode::getNextNode() const{
    return nextNode;
}

DLNode* DLNode::getPrevNode() const{
    return prevNode;
}

void DLNode::setNextNode(DLNode* newNextNode){
	prevNode = nextNode;
    nextNode = newNextNode;
}

void DLNode::setPrevNode(DLNode* newPrevNode){
    prevNode = newPrevNode;
}

void DLNode::setContents(int newContents){
    contents = newContents;
}