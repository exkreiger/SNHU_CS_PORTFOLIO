#include "GroceryFiling.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <iterator>
using namespace std;

//default constructor
//unused, exists to catch missing files
GroceryFiling::GroceryFiling(){
	map<string, int> tempMap;
	tempMap["error"] = -9;
	SetFileIn("Error: no in file");
	SetFileOut("Error: no out file");
	SetGroceryList(tempMap);
}

//usable constructor
//will set fields based on input, and will process the grocery list based 
//on input file at this point
GroceryFiling::GroceryFiling(string nameIn, string nameOut){
	SetFileIn(nameIn);
	SetFileOut(nameOut);
	SetGroceryList(this->ProcessList());
}

//takes the files set at object init and creates a map of the words with
//occurences, and prints this map to the output file
map<string, int> GroceryFiling::ProcessList(){
	string fileIn= this->GetFileIn();
	string fileOut = this->GetFileOut();
	map <string, int> gList;
	ifstream inf;
	ofstream outf;
	string itemKey = "";
	
	//init map for error return
	gList["error"] = -9;
	
	inf.open(fileIn);
	if(!inf.is_open()){
		cout << "Could not open file " << fileIn << endl;
		return gList;
	}

	outf.open(fileOut);
	if(!outf.is_open()){
		cout << "Could not open file " << fileOut << endl;
		return gList;
	}
	
	//prep map for file processsing
	gList.clear();

	//runs while there is a viable line to feed itemKey, avoids duplicate @ end
	while(inf>>itemKey){
		//item not in map, add and assign count to 1
		if(gList.find(itemKey) == gList.end()){
			gList[itemKey] = 1;		
		}
		//item in map, increment count
		else{
			gList[itemKey]++;
		}
	}
	inf.close();

	map<string, int>::iterator it = gList.begin();
	string item = "";
	int occ = 0;
	//printing to the file
	while(it != gList.end()){
		//get key
		item = it->first;
		//get val
		occ = it->second;
		//output of func
		outf << item << " " << occ << endl;
		cout << item << " " << occ << endl;
		it++;
	}
	outf.close();

	return gList;
}

void GroceryFiling::PrintMenu(){
	cout << "1  -  Show number of matches for a specific item" << endl;	
	cout << "2  -  Print all matches with numeric counts" <<  endl;
	cout << "3  -  Print all matches with histogram visualization" << endl;
	cout << "4  -  Quit" << endl;
}

//prompts user for input and searches map for a match
//prints the result on success
//prints error message on no match
void GroceryFiling::GetOccurences(){
	map<string, int> groceryList = this->GetGroceryList();
	string target;
	string cont;
	
	cout << "Enter the item to search for: " << endl;
	cin >> target;

	if(groceryList.find(target) == groceryList.end()){
		cout << "Error: item not found in list..." << endl;
	}
	else{
		cout << target << " occurred in list " << groceryList.at(target) << 
			" times" << endl;
	}
	cout << "****Type anything and RETURN to continue****" << endl;
	cin >> cont;
}

//prints all contents of groceryList private map field as key value newline
void GroceryFiling::PrintNumerals(){
	map<string, int> groceryList = this->GetGroceryList();
	//init iterator to loop on map
	map<string, int>::iterator it = groceryList.begin();
	string item = "";
	int occ = 0;
	string cont;

	while(it != groceryList.end()){
		//get key
		item = it->first;
		//get val
		occ = it->second;
		//output of func
		cout << item << " " << occ << endl;
		it++;
	}
	cout << "****Type anything and RETURN to continue****" << endl;
	cin >> cont;
}

//prints all contents of groceryList private map field as key (value*"|") newline
void GroceryFiling::PrintHistogram(){
	map<string, int> groceryList = this->GetGroceryList();
	//init iterator to loop on map
	map<string, int>::iterator it = groceryList.begin();
	string item = "";
	int occ = 0;
	string cont;

	while(it != groceryList.end()){
		//get key
		item = it->first;
		//get val
		occ = it->second;
		//output of func
		cout << item << " " << string(occ, '|') << endl;
		it++;
	}
	cout << "****Type anything and RETURN to continue****" << endl;
	cin >> cont;
}

void GroceryFiling::SetFileIn(string name){
	this->fileIn = name;
}

void GroceryFiling::SetFileOut(string name){
	this->fileOut = name;
}

void GroceryFiling::SetGroceryList(map <string, int> list){
	this->groceryList = list;
}

string GroceryFiling::GetFileIn(){
	return this->fileIn;
}

string GroceryFiling::GetFileOut(){
	return this->fileOut;
}

map <string, int> GroceryFiling::GetGroceryList(){
	return this->groceryList;
}
