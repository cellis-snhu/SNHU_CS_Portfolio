// Author Name: Christopher Ellis

// Date: 10/15/2023

// Course ID: CS210

// Description: Corner Grocer application to read a file of purchases made at the store
// and store the frequency of each purchase in the grocery file.

#include "GroceryItemList.h"
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

// Default constructor
GroceryItemList::GroceryItemList() {}

// AddItem takes an item string and attempts to add it to the map of all items and frequencies
// if the item exists it increments the frequency, otherwise it adds the new item with frequency
// of 1
void GroceryItemList::AddItem(string item) {
    // iterate over map using `find` to check if key exists already
    map<string, int>::iterator it = groceryItems.find(item);

    if (it != groceryItems.end()) {
        // if the key exists, add 1 to its value (frequency)
        it->second += 1;
    }
    else {
        // Key does not exist in the map, add it with a frequency of 1
        groceryItems[item] = 1;
    }
}

// GetItem takes an item string and returns the frequency if the item exists in the map,
// otherwise it returns frequency of 0
int GroceryItemList::GetItem(string item) {
    // iterate over map using `find` to check if key exists
    map<string, int>::iterator it = groceryItems.find(item);

    if (it != groceryItems.end()) {
        // if the key exists return the quantity
        return it->second;
    }
    else {
        // Key does not exist in the map, return quantity of 0
        return 0;
    }
}

// PrintItems prints all items in the map with the format "item frequency"
void GroceryItemList::PrintItems() const {
    // iterate over groceryItems map
    for (const auto& item : groceryItems) {
        // output the key (first) and quantity (second) values from each map entry
        cout << item.first << " " << item.second << endl;
    }
}

// PrintItemsWithChar prints all items in the map with the format "item (n * char)"
// where char is passed to the function and the number of times the char is printed is the
// frequency value
void GroceryItemList::PrintItemsWithChar(char c) {
    // iterate over groceryItems map
    for (const auto& item : groceryItems) {
        // output the key (first) and quantity (second) values from each map entry
        cout << item.first << " " << string(item.second, c) << endl;
    }
}

// SaveBackup takes a map of items and frequencies, and outputs them into a backup file
// frequency.dat with the format "item frequency"
void GroceryItemList::SaveBackup() {
    // initialize output file stream
    const string outputFileName = "frequency.dat";
    cout << "Saving backup file..." << endl;
    ofstream outputFS;
    outputFS.open(outputFileName);

    if (outputFS.is_open()) {
        // loop through map and write item name and frequency to output filestream
        for (const auto& item : groceryItems) {
            outputFS << item.first << " " << item.second << endl;
        }
        outputFS.close();
    }
    else {
        cout << "Unable to open the file for writing." << endl;
    }
}

// ReadGroceryFile takes a filename as input and attempts to read the file line by line
// called AddItem for each line in the input file
void GroceryItemList::ReadGroceryFile(string filename) {
    // initialize input file stream
    ifstream inputFS;

    cout << "Opening file: " << filename << endl;

    // open file
    inputFS.open(filename);
    // if file fails to open, error and do nothing
    if (!inputFS.is_open()) {
        cout << "Failed to open file: " << filename << endl;
    }
    // otherwise, loop through file reading each line into the input file stream
    else {

        while (!inputFS.eof()) {
            string item;
            inputFS >> item;

            AddItem(item);
        }
    }
    // attempt to close file if it is still open
    inputFS.close();
}
