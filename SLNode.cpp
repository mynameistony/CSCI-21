#include "SLNode.h"
#include <cstdlib>
using namespace std;

SLNode::SLNode(){
    
    nextNode = NULL;
    
    contents = 0;
}

SLNode::SLNode(int newContents){
 
    nextNode = NULL;
    
    contents = newContents;
}

SLNode::~SLNode(){
    
    nextNode = NULL;
}

void SLNode::setContents(int newContents){
    contents = newContents;
}

int SLNode::getContents() const{
    
    return contents;
    
}

void SLNode::setNextNode(SLNode* setNode){
    
    nextNode = setNode;
}

SLNode* SLNode::getNextNode() const{
    return nextNode;
}
