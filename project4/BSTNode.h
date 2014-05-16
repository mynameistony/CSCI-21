#pragma once
#include <string>

template <class T>
class BSTNode{

	public:
		
	BSTNode()
	:data(0), leftChild(NULL), rightChild(NULL)
	{
	}
	
	BSTNode(T newData)
	:data(newData), leftChild(NULL), rightChild(NULL)
	{
	}
	
	virtual ~BSTNode()
	{
	}
		
	void setData(T newData)
	{
		data = newData;
	}
	
	void setLeftChild(BSTNode<T>* newLeftChild)
	{
		leftChild = newLeftChild;
	}
	
	void setRightChild(BSTNode<T>* newRightChild)
	{
		rightChild = newRightChild;
	}
	
	T getData() const
	{
		return data;
	}

	T& getData(){
		return data;
	}	
	
	BSTNode<T>* getLeftChild() const
	{
		return leftChild;
	}
	
	BSTNode<T>* getRightChild()const
	{
		return rightChild;
	}
	
	
	BSTNode<T>*& getLeftChild(){
		return leftChild;
	}
			
	BSTNode<T>*& getRightChild(){
		return rightChild;
	}
	
	private:
	
	BSTNode<T>* leftChild;
	
	BSTNode<T>* rightChild;
	
	T data;
	
};

