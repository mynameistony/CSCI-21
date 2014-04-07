#pragma once


class SLNode {
    public:
  
    SLNode();

    SLNode(int contents);

    ~SLNode();
    
    void setContents(int contents);
    
    int getContents() const;
    
    void setNextNode(SLNode* nextNode);
    
    SLNode* getNextNode() const;

  private:
  
  SLNode* nextNode;
  
  int contents;
};