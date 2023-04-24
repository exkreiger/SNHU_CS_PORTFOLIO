#ifndef GROCERY_FILING_H 
#define GROCERY_FILING_H
#include <map>

class GroceryFiling{
	 
	public:
		GroceryFiling();
		GroceryFiling(string fileIn, string fileOut);
		map<string, int> ProcessList();	
		void PrintMenu();
		void GetOccurences();
		void PrintNumerals();
		void PrintHistogram();
		void SetFileIn(string name);
		void SetFileOut(string name);
		void SetGroceryList(map <string, int> list);
		string GetFileIn();
		string GetFileOut();
		map <string, int> GetGroceryList();

	
	private:
		string fileIn;
		string fileOut;
		map<string, int> groceryList;
	
};

#endif
