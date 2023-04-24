#include <iostream>
using namespace std;
#include "GroceryFiling.cpp"

int main(){
	//checking system for which clear command to send
	bool winos = false;
#ifdef _WIN32
		winos =  true;
#elif _WIN64
		winos = true;
#endif
	string inFile ="CS210_Project_Three_Input_File.txt";
	string outFile ="frequency.dat";

	//processes list and creates private map during instatiation, calling
	//this->ProcessList()
	//@ grocery.GetGroceryList()
	GroceryFiling grocery(inFile, outFile);
	int choice = 0;

	while(choice != 4){
		//clear screen
		if(winos){
			system("CLS");
		}
		else{
			system("clear");
		}
		
		grocery.PrintMenu();	
		
		cout << "Please choose one of the menu options: " << endl;
		cin >> choice;
		
		//runs until "quit" or "bad input"
		switch(choice){
			case 1:
				grocery.GetOccurences();
				break;
			case 2:
				grocery.PrintNumerals();
				break;
			case 3:
				grocery.PrintHistogram();
				break;
			case 4:
				cout << "Quitting..." << endl;
				break;
			default:
				cout <<	"Error...quitting" << endl;
				choice = 4;
				continue;
		}
	}
}

