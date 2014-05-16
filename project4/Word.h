#pragma once
#include <string>

using namespace std;
class Word{

	public:
	
	//Default Constructor	
	Word()
	:word(""),count(0)
	{}

	//Overloaded Constructor
	//@param newWord -> string to set as the word
	Word(string newWord){
	for(int i = 0; i < newWord.length(); i++)
		newWord[i] = tolower(newWord[i]);
	word = newWord;
	count = 1;
	}
	
	//Destructor
	virtual ~Word(){
	
	}
	
	//returns stored string
	string getWord(){
		return word;
	}
	
	//sets string
	void setWord(string newWord){
		for(int i = 0; i < newWord.length(); i++)
			newWord[i] = tolower(newWord[i]);
	
		word = newWord;
		count = 1;
	}
	
	unsigned int getCount(){
		return count;
	}
	
	void incrementCount(){
		count++;
	}
    
    friend ostream& operator<< (ostream& out, Word word){
        out << word.getWord() << " " << word.getCount() << " ";
        
        return out;
    }	
    
	bool friend operator== (Word& word1, Word& word2){
		if(word1.getWord() == word2.getWord())
			return true;
		else
			return false;
	}
	
	bool friend operator!= (Word& word1, Word& word2){
		if(word1.getWord() != word2.getWord())
			return true;
		else
			return false;
	}
	bool friend operator< (Word& word1, Word& word2){
		string wordstr1 = word1.getWord();
		string wordstr2 = word2.getWord();		
	
		if(wordstr1.compare(wordstr2) < 0)
			return true;
		else
			return false;
		
	}

	bool friend operator> (Word& word1, Word& word2){
		string wordstr1 = word1.getWord();
		string wordstr2 = word2.getWord();		
		
		if(wordstr1.compare(wordstr2) > 0)
			return true;
		else
			return false;
		
	}
	
	void friend operator++ (Word& word1){
		word1.incrementCount();		
	}		
			
	private:
	
	string word;
	
	unsigned int count;
		
};