#pragma once
#include "BSTNode.h"
#include "Word.h"
using namespace std;

template <class T>
class BSTree {

	public:
	
	BSTree()
	:root(NULL), size(0)
	{}
	
	~BSTree()
	{}
	
	unsigned int getSize()
	{
		return size;
	}
	
	void clear(){
		clear(root);
	}
	
	bool insert (T newContents){
		if(insert(newContents, root))
			return true;
		else
			return false;
	}
	
	bool find (T targetData){
		if(find(targetData, root))
			return true;
		else
			return false;
	}
	bool remove (T targetData){
		if(remove(targetData, root))
			return true;
		else
			return false;
	}
	
	T* get (T targetData){
		return get(targetData, root);
	}
	
	void inOrder (){
		inOrder(root);
	}
	
	void reverseOrder (){
		reverseOrder(root);
	}
	
	private:
	
	BSTNode<T>* root;
	
	unsigned int size;
	
	void clear (BSTNode<T>*& tempRoot){
		if(tempRoot != NULL){
			clear(tempRoot -> getLeftChild());
			
			clear(tempRoot -> getRightChild());
			
			delete tempRoot;
			
			tempRoot = NULL;
			
			size--;
		}
	}	
		
		
	
	T* get (T targetData, BSTNode<T>* tempRoot){
	
		if(tempRoot != NULL){
			if(tempRoot -> getData() == targetData)
				return &tempRoot -> getData();
			else
				if(tempRoot -> getData() < targetData)
					return get(targetData, tempRoot -> getLeftChild());
				else
					return get(targetData, tempRoot -> getRightChild());	
		}
		else
			return NULL;
	}
	

	bool insert (T newContents, BSTNode<T>*& tempRoot){
		if(tempRoot != NULL){

			if(newContents == tempRoot->getData()){
				Word newWord = tempRoot->getData();
				
				newWord.incrementCount();
				
				tempRoot->setData(newWord);

				return false;
			}
			else
				if(newContents < tempRoot -> getData())
					return (insert(newContents,tempRoot->getLeftChild()));
				else
					return (insert(newContents,tempRoot->getRightChild()));
		}
		else{
			BSTNode<T>* newNode = new BSTNode<T>(newContents);		 							
			
			tempRoot = newNode;
			size++;
			
			return true;			
		}	

	}
	
	bool find (T targetData, BSTNode<T>*& tempRoot){
		if(tempRoot != NULL){

			if(tempRoot->getData() == targetData)
				return true;
			else
				if(find(targetData, tempRoot->getLeftChild()))
					return true;
				else
				if(find(targetData,tempRoot->getRightChild()))				
					return true;
				else
					return false;		
		}
	}
	
	bool remove (T targetData, BSTNode<T>*& tempRoot){
		if(tempRoot != NULL){
			
			if(targetData < tempRoot -> getData())
				return remove(targetData, tempRoot -> getLeftChild());
			else
				if(targetData > tempRoot -> getData())
					return remove(targetData, tempRoot -> getRightChild());
				else{
			
					if(tempRoot->getLeftChild() == NULL ){
						BSTNode<T>* temp = tempRoot;
					
						tempRoot = tempRoot->getRightChild();
										
						delete temp;
						size--;
						return true;
					}
					else
						removeMax(tempRoot->getData(), tempRoot -> getLeftChild());
			}
		}
		else
			return false;
			
	}
	
	void removeMax (T& removed, BSTNode<T>*& tempRoot){
		BSTNode<T>* max = tempRoot;
		
		if(tempRoot ->getRightChild() == NULL){
			removed = max -> getData();
			tempRoot = max -> getLeftChild();
			delete max;
			size--;
		}
		else{
			removeMax(removed, tempRoot->getRightChild());	
		}
		
		
	}
	

	
	void inOrder (BSTNode<T>* tempRoot){
		
		if(tempRoot != NULL){
			inOrder (tempRoot->getLeftChild());
			cout << tempRoot->getData() << endl;		
			inOrder (tempRoot->getRightChild());
		}
	}
	
	void reverseOrder (BSTNode<T>* tempRoot){

		if(tempRoot != NULL){
			reverseOrder(tempRoot->getRightChild());
			cout << tempRoot-> getData() << endl;
			reverseOrder(tempRoot->getLeftChild());			
			
		}
			
	}
};










