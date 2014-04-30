#pragma once

#include  <cstdlib>
using namespace std;

class DLNode
{
    public:
        DLNode();
        DLNode(int newContents);
        virtual ~DLNode();
        
        int getContents() const;
        DLNode* getNextNode() const;
        
        DLNode* getPrevNode() const;
        
        void setNextNode(DLNode* newNextNode);
        
        void setPrevNode(DLNode* newPrevNode);
        
        void setContents(int newContents);
        
    private:
        DLNode* nextNode;
        DLNode* prevNode;
        int contents;
};