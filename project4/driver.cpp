#include <iostream>
#include "BSTree.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Word.h"

using namespace std;

int main(int argc, char** argv){


	if(argc < 2){
		cout << "USAGE: project4 FILE_NAME" << endl;
	}
	else{
		cout << "Input File: " << argv[1] << endl;
		ifstream input(argv[1]);
        //istream& input = cin;			
		stringstream stream;
		BSTree<Word> testTree;		
		Word* testWord;
		if(input.good()){
			
			string line;
			
            while (getline (input, line)){
				char command = line.at(0);
				Word target;
				switch(command){
					
					// CREATE
					case 'C':
					cout << "TREE CREATED" << endl;
					break;
					
					// CLEARED
					case 'X':
					cout << "TREE CLEARED" << endl;
					testTree.clear();
					break;
					
					// DELETE
					case 'D':
					cout << "TREE DELETED" << endl;
					break;
										
					// INSERT
					case 'I':
					target.setWord(line.substr(2));
					if(testTree.insert(target))
						cout << "WORD " << line.substr(2) << " INSERTED" << endl;
					else
						cout <<"WORD " << line.substr(2) << " INCREMENTED" << endl;
					break;
									
					// FIND DATA
					case 'F':
					    
					    if(testTree.getSize() < 1)
					        cout << "TREE EMPTY" << endl;
					    else{
					    
						target.setWord(line.substr(2));
												
						if(testTree.find(target))
							cout << "FOUND " << line.substr(2) << endl;
						else
							cout << line.substr(2) << " NOT FOUND" << endl;
					    }
					break;
					
					// REMOVE					
					case 'R':
					    
					    if(testTree.getSize() < 1)
					        cout << "TREE EMPTY" << endl;
					    else{
						target.setWord(line.substr(2));
						
						if(testTree.remove(target))
							cout << "REMOVED " << line.substr(2) << endl;
						else
							cout << line.substr(2) << " NOT FOUND" << endl; 
					    }
					break;
					
					// GET DATA
					case 'G':
					    if(testTree.getSize() < 1)
					        cout << "TREE EMPTY" << endl;
					    else{
						target.setWord(line.substr(2));
						testWord = testTree.get(target);
						cout << testWord << endl;
					    }
					break;
										
					// IN ORDER
					case 'O':
					    if(testTree.getSize() < 1)
					        cout << "TREE EMPTY" << endl;
					    else
						    testTree.inOrder();
					break;
					
					// REVERSE ORDER
					case 'E':
					    if(testTree.getSize() < 1)
					        cout << "TREE EMPTY" << endl;
					    else
						    testTree.reverseOrder();
					break;
					
					// SIZE
					case 'N':
						cout << "TREE SIZE IS " << testTree.getSize() << endl;
					break;
					
					default:
					 cout << "UNKNOWN COMMAND" << endl;
					break;			
				
				}

			}
		}
	}	
	return 0;
}
