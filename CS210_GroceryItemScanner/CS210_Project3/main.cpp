// Author Name: Christopher Ellis

// Date: 10/15/2023

// Course ID: CS210

// Description: Corner Grocer application to read a file of purchases made at the store
// and store the frequency of each purchase in the grocery file.

#include <iostream>
#include "GroceryItemList.h"

using namespace std;

// Print the menu options
void PrintMenu() {
    std::cout << "Menu Options:" << std::endl;
    std::cout << "1. Search by word" << std::endl;
    std::cout << "2. Print All Items" << std::endl;
    std::cout << "3. Print All Items With Histogram" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {

    // initialize an instance of GroceryItemList for a store
    GroceryItemList StoreGroceryList;

    // read the given file for grocery item names into the GroceryItemList
    // and map the frequency of each item
    StoreGroceryList.ReadGroceryFile("groceries.txt");


    while (true) {
        int choice;
        string search_term;
        int search_quantity = 0;

        // print the menu
        PrintMenu();
        cout << endl;

        // check that choice is an integer 1-4 input or post error message if not
        while (!(cin >> choice) && (choice >= 0 && choice <= 4)) {
            cout << "Invalid choice. Please enter a valid option (1-4)." << endl;
            PrintMenu();
            cout << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }

        // call functions based on menu option choice
        switch (choice) {
        case 1:
            cout << "Enter the word you want to search for: " << endl;
            cin >> search_term;

            search_quantity = StoreGroceryList.GetItem(search_term);

            if (search_quantity == 0) {
                cout << "Item was not found in list." << endl << endl;
            }
            else {
                cout << "Item '" << search_term << "' found, frequency: " << search_quantity << endl << endl;
            }
            break;
        case 2:
            std::cout << "Printing list of items and frequency..." << std::endl;
            StoreGroceryList.PrintItems();
            break;
        case 3:
            std::cout << "Printing list of items and frequency histogram..." << std::endl;
            StoreGroceryList.PrintItemsWithChar('*');
            break;
        case 4:
            std::cout << "Exiting the program." << std::endl;
            // return to exit the loop/program
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a valid option (1-4)." << std::endl;
            break;
        }
        cout << endl;
    }



	return 0;
}