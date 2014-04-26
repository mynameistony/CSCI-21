#include "DLList.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;



int main(int argc, char** argv){
    
    DLList* list;
    stringstream stream;
    string strVal;
    int intVal;
    
    if(argc != 2)
    {
        cout << "USAGE: project2 FILENAME" << endl;


    }
    else
    {
        string line;
        int command = 0;
        cout << "PROCESSING FILE: " << argv[1] << endl;
        
        ifstream input (argv[1]);
        //istream& input = cin;
        
        if(input.good())
        {
            cout << "File opened..." << endl;
            
            while (getline (input, line))
            {
                stream.clear();
                intVal = 0;
                strVal = "";
                
                command = line.at(0);
                
                if(command != 35){
                    switch(command){
                    	//I - INSERT
                        case 73:

                            strVal = line.substr(2);
                            stream << strVal;
                            stream >> intVal;
                            cout << "VALUE " << intVal << " INSERTED" << endl;
                            
                            list->insert(intVal);                            
                        break;
                        
                        //X - CLEAR
                        case 88:
                            cout << "LIST CLEARED" << endl;
                            list->clear();
                        break;
                        
                        //D - DELETE
                        case 68:
                            cout << "LIST DELETED" << endl;
                            delete list;
                            list = NULL;
                        break;
                        
                        //A - GET HEAD VALUE
                        case 65:
                            cout << "VALUE " << list->getFront() <<" AT HEAD" << endl;
							
                        break;
                        
                        //K - REMOVE TAIL
                        case 75:
                            cout << "REMOVED TAIL" << endl;
                            list->popBack();
                        break;
                        
                        //C - CREATE
                        case 67:
                            cout << "LIST CREATED" << endl;
                            list = new DLList;
                        break;
                        
                        //P - PRINT LIST
                        //NEED TO USE << OPERATOR
                        case 80:
                            cout << list->toString() << endl;
                        break;                    
                        
                        //F - ADD HEAD
                        case 70:
                            strVal = line.substr(2);
                            stream << strVal;
                            stream >> intVal;
                            cout << "VALUE " << intVal << " ADDED TO HEAD" << endl;
                        
                            list->pushFront(intVal);
                        break;                    
                        
                        //B - ADD TAIL
                        case 66:
                            strVal = line.substr(2);
                            stream << strVal;
                            stream >> intVal;
                            cout << "VALUE " << intVal << " ADDED TO TAIL" << endl;                            
                            
                            list->pushBack(intVal);
                        break;        
                        
                        //N - GET SIZE            
                        case 78:
                           cout << "LIST SIZE IS " << list->getSize() <<endl;
                        break;        
                        
                        //Z - GET TAIL CONTENTS            
                        case 90:
                            cout << "VALUE " << list->getBack() << " AT TAIL" << endl;
                            
                        break;                 
                        
                        //R - REMOVE ITEM   
                        case 82:
                            strVal = line.substr(2);
                            stream << strVal;
                            stream >> intVal;                        
                        	if(list->removeFirst(intVal))
                        		cout << "VALUE " << intVal << " REMOVED" << endl;
                        	else
                        	    cout << "VALUE " << intVal << " NOT FOUND" << endl;
                        break;           
                        
                        //E - ELIMINATE ITEM         
                        case 69:
                            strVal = line.substr(2);
                            stream << strVal;
                            stream >> intVal; 
                                                    
                        	if(list->removeAll(intVal))
	                            cout << "VALUE " << intVal << " ELIMINATED" << endl;
	                        else
	                        	cout << "VALUE " << intVal << " NOT FOUND" << endl;
                        break;              
                        
                        //G - FIND VALUE
                        case 71:
                        	
                            strVal = line.substr(2);
                            stream << strVal;
                            stream >> intVal;
                            
                            if(list->get(intVal))
                            	cout << "VALUE " << intVal << " FOUND" << endl;
                            else                       	
                           		cout << "VALUE " << intVal << " NOT FOUND" << endl;
                            
                        break;          
                        
                        //T - REMOVE HEAD          
                        case 84:
                            cout << "REMOVED HEAD" << endl;
                            list->popFront();
                        break;
                        
                        //? - BAD INPUT
                        default:
                            cout << "UNKNOWN COMMAND" << endl;
                        break;
                    
                    }
                        
                }
            }
            input.close();
        }
        else
        {
            cout << "File did not open..." << endl;
        }
        
    }
    
    
 
    return 0;   
}

