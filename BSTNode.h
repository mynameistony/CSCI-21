#pragma once
#include <string>

class BSTNode{

	public:
		
	BSTNode()
	:data(0), leftChild(NULL), rightChild(NULL)
	{
	}
	
	BSTNode(int newData)
	:data(newData), leftChild(NULL), rightChild(NULL)
	{
	}
	
	virtual ~BSTNode()
	{
	}
		
	void setContents(int newData)
	{
		data = newData;
	}
	
	void setLeftChild(BSTNode* newLeftChild)
	{
		leftChild = newLeftChild;
	}
	
	void setRightChild(BSTNode* newRightChild)
	{
		rightChild = newRightChild;
	}
	
	int getContents() const
	{
		return data;
	}

	int& getContents(){
		return data;
	}	
	
	BSTNode* getLeftChild() const
	{
		return leftChild;
	}
	
	BSTNode* getRightChild()const
	{
		return rightChild;
	}
	
	
	BSTNode*& getLeftChild(){
		return leftChild;
	}
			
	BSTNode*& getRightChild(){
		return rightChild;
	}
	
	private:
	
	int data;
	
	BSTNode* leftChild;
	
	BSTNode* rightChild;
	

	
};



/*
class Word{

	public:

	Word();
	
	Word(string newWord)
	:word(newWord)
	{
	}
	
	virtual ~Word();
	
	string getWord()
	{
		return word;
	}
	
	void setWord(string newWord)
	{
		word = newWord;
	}
	
	unsigned int getCount()
	{
		return count;
	}
	
	void incrementCount()
	{
		count++;
	}
		
	private:
	
	string word;
	
	unsigned int count;
};

*/
