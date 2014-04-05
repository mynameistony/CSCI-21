
#include "box.h"
#include "prize.h"
//#include "CinReader.h"

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
//CinReader input;
Box testBox;
Prize testPrize;

bool quit = false;
bool quitBox = false;
bool quitPrize = false;

void clearPrizes();

void clearScreen();

int MainMenu();

int PrizeMenu();

int BoxMenu();

void changeNumber();

void changeColor();

void viewPrizes();

void addPrize();

void changePrizeName();

void changePrizeValue();

void comparePrizes();

void secret();

bool root = false;

int main ()
{
    while(!quit)
    {
        quit = false;
        clearScreen();
    
        switch(MainMenu())
        {
    	    //Interactive Box Test
            case 1:
            {
            quitBox = false;
            while(!quitBox){
        
            switch(BoxMenu())
            {
        	    //Add Prize
                case 1:
                addPrize();
                break;
                
                //View Prizes
                case 2:
                viewPrizes();
                break;
                
                //Clear Prizes
                //Learn Dynamic Array!!
                case 3:{
		        clearPrizes();
                }
                break;
                
                //Change Number
                case 4:
                changeNumber();
                break;
                
                //Change Color
                case 5:
                changeColor();
                break;
                
                default:
                quitBox = true;
                break;            
            }
                
                
            }
        }
            break;
        
            //Interactive Prize Test
            case 2:{
        
		quitPrize = false;
        while (!quitPrize){

        switch(PrizeMenu()){
            
            //Change Prize Name
            case 1:
			changePrizeName();
            break;
            
            //Change Prize Value
            case 2:
            changePrizeValue();            
            break;
            
            //Compare 2 Prizes
            case 3:
            comparePrizes();
            break;
            
            default:
            	quitPrize = true;
            break;
            
        }
        }
        
        
        }
            break;
        
            //Unit Test
            case 3:
        
            break;
            
            //"Secret" Option
            case 4:
                if(root == true){
		 cout << "\\|/    ___    \\|/  \n";
         cout << " \\    |0 0|    /\n";
         cout << "  \\   | @ |   /\n";
         cout << "   \\_/|\"\"\"|\\_/\n";
         cout << "      |   |\n";
         cout << "      |   |\n";
         cout << "      |   |\n";
         cout << "      | _ |\n";
         cout << "      |/ \\|\n";
         cout << "      || ||\n";
         cout << "      || ||\n";
         cout << "      || ||\n";
         cout << "-----------------\n";
         cout << "JAZZ HANDS!!!!!!\n";
         cout << "\nType 'anything' to continue\n";
         string wait;
         cin >> wait;
         }
            break;
        
            default:
        	    quit = true;
            break;
        }
    }

    return 0;
}

void comparePrizes(){
	clearScreen();
	
	int prize1Val, prize2Val;
	string prize1Name, prize2Name;
	
	cout << "--Comparing 2 Prizes--\n";
	cout << "Enter Prize 1 Name: ";
	cin >> prize1Name;
	cout << "Enter Prize 1 Value: ";
	cin >> prize1Val;
	cout << "Enter Prize 2 Name: ";
	cin >> prize2Name;
	cout << "Enter Prize 2 Value: ";
	cin >> prize2Val;
	
	Prize prize1(prize1Name, prize1Val);
	Prize prize2(prize2Name, prize2Val);
	
	if(prize1 < prize2){
		cout << "--Prize 2 is greater--";
	}	
	else
	
	if(prize1 > prize2){
		cout << "--Prize 1 is greater--";
		
	}else
		cout << "--Prizes are equal--";
		
	string wait;
	cout << "\nType 'anything' to continue\n";
	cin>> wait;
	
	if (wait == "anything")
		root = true;
	
	
	
}

void clearPrizes(){
	testBox.clearPrizeArray();
}

void changePrizeValue(){
    unsigned int newValue;
    clearScreen();
    cout << "Current Value: " << testPrize.getPrizeValue() << "\n";
    cout << "New Value: ";
    cin >> newValue;
    testPrize.setPrizeValue(newValue);
}

void changePrizeName(){
    string newName;
    clearScreen();
    cout << "Current Name: " << testPrize.getPrizeName() << "\n";
    cout << "New Name: ";
    cin >> newName;
    testPrize.setPrizeName(newName);
}

int MainMenu(){
    int choice;

    cout << "--Tony's Box and Prize Thing--\n\n";
    cout << "1: Interactive Box Test\n";
    cout << "2: Interactive Prize Test\n";
    cout << "3: Unit Test\n";
    if(root)
    cout << "4: What's this...\n";
    cout << "0: Quit\n";
    cout << ">> ";
    
    cin >> choice;
    
    return choice;
    
}

int PrizeMenu(){
	int prizeChoice;
    clearScreen();

    cout << "--Interactive Prize Test--\n";
    cout << "Name: "  << testPrize.getPrizeName() << "\n";
    cout << "Value: $" << testPrize.getPrizeValue() << "\n";
    cout << "--------------------------\n";
    cout << "1:Edit Name\n";
    cout << "2:Edit Value\n";
    cout << "3:Compare 2 Prizes\n";
    cout << "0:Main Menu\n";
    cout << ">> ";
    cin >> prizeChoice;
        
    return prizeChoice;
}

int BoxMenu(){
    int boxChoice;

    clearScreen();
      
    cout << "--Interactive Box Test--\n";
    cout << "Number: " << testBox.getBoxNumber() << "\n";
    cout << "Color: " << testBox.getBoxColor() << "\n";
    cout << "Capacity: " << testBox.getPrizeCount() << "/" << testBox.getPrizeCapacity() << "\n";
    cout << "------------------------\n";
    cout << "1: Add Prize\n";
    cout << "2: View Prizes\n";
    cout << "3: Clear Prizes\n";
    cout << "4: Change Number\n";
    cout << "5: Change Color\n";
    cout << "0: Main Menu\n";
    cout << ">> ";
         
    cin >> boxChoice;

    return boxChoice;
}

void changeNumber(){
    clearScreen();
    cout << "Current Number: " << testBox.getBoxNumber() << "\n";
    cout << "New number: ";
    unsigned int newNumber;
    cin >> newNumber;
    testBox.setBoxNumber(newNumber);
}

void changeColor(){
    clearScreen();
    cout << "Current Color: " << testBox.getBoxColor() << "\n";
    cout << "New Color: ";
    string newColor;
    cin >> newColor;
    testBox.setBoxColor(newColor);
}

void viewPrizes(){
    clearScreen();
    cout << "--Let's see what's in this beautiful, " << testBox.getBoxColor() << " colored BOX #";
    cout << testBox.getBoxNumber() << " ?--\n";
        
    for (int i = 0; i < testBox.getPrizeCount(); i ++){
        Prize thisPrize = testBox.getPrize(i);
        cout << "------------------\n";
        cout << "Prize #"<< i+1 << "\n";
        cout << "Prize Name: " << thisPrize.getPrizeName() << "\n";
        cout << "Prize Value: $" << thisPrize.getPrizeValue() << "\n";
    }
    
    cout << "\nType 'anything' to continue\n";
    string wait;
    cin >> wait;
        
    if (wait == "anything")
        root = true;
    
}
            
void addPrize(){
	
    clearScreen();
            
    string newPrizeName;
    int newPrizeValue;
    cout << "Enter new prize name: ";
    cin >> newPrizeName;
    cout << "Enter new prize value: ";
    cin >> newPrizeValue;
                
    Prize newPrize(newPrizeName, newPrizeValue);
    if(testBox.addPrize(newPrize)){
        cout << "Success\n";
    }
    else
        cout << "Fail";
}            

void clearScreen(){
    for (int i = 0; i < 50; i++){
        cout << "\n";
    }
}




