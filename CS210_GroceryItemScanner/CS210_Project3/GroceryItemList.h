// Author Name: Christopher Ellis

// Date: 10/15/2023

// Course ID: CS210

// Description: Corner Grocer application to read a file of purchases made at the store
// and store the frequency of each purchase in the grocery file.

#pragma once

#ifndef GROCERY_ITEM_LIST_H
#define GROCERY_ITEM_LIST_H

#include <map>
#include <string>

using namespace std;

class GroceryItemList {
private:
	// map to store "item_name frequency" of grocery items
	map<string, int> groceryItems;
public:
	// Default constructor
	GroceryItemList();

	// AddItem takes an item string and attempts to add it to the map of all items and frequencies
	// if the item exists it increments the frequency, otherwise it adds the new item with frequency
	// of 1
	void AddItem(string item);

	// GetItem takes an item string and returns the frequency if the item exists in the map,
	// otherwise it returns frequency of 0
	int GetItem(string item);

	// SaveBackup takes a map of items and frequencies, and outputs them into a backup file
	// frequency.dat with the format "item frequency"
	void SaveBackup();

	// ReadGroceryFile takes a filename as input and attempts to read the file line by line
	// called AddItem for each line in the input file
	void ReadGroceryFile(string filename);

	// PrintItems prints all items in the map with the format "item frequency"
	void PrintItems() const;

	// PrintItemsWithChar prints all items in the map with the format "item (n * char)"
	// where char is passed to the function and the number of times the char is printed is the
	// frequency value
	void PrintItemsWithChar(char c);
};

#endif // GROCERY_ITEM_LIST_H