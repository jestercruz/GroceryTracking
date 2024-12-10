/* Jester Cruz
   12/10/2024
   A program for Corner Grocer that takes a file and creates another file containing
   the frequency of each entry.
*/

#include "ItemFrequency.h"
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

// Function to validate menu input
int getValidatedMenuChoice() {
    int choice;
    while (true) {
        // Display the menu
        cout << "\nMenu:\n"
            << "1. Search for an item\n"
            << "2. Display all item frequencies\n"
            << "3. Display histogram\n"
            << "4. Exit\n"
            << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        // Check for valid input
        if (!cin.fail() && choice >= 1 && choice <= 4) {
            return choice; // Valid choice
        }
        else {
            // Handle invalid input
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }
}

// Function to validate item input
string getValidatedItem() {
    string item;
    while (true) {
        cout << "Enter the item to search for: ";
        cin >> item;
        cout << endl;

        // Check for non-empty input
        if (!item.empty()) {
            return toLowerCase(item); // Return lowercase input
        }
        else {
            cout << "Invalid input. Please enter a valid item name.\n";
        }
    }
}


int main() {
    // Initialize the class with input and backup file names
    ItemFrequency itemFrequency("Input_File.txt", "frequency.dat");

    int choice;
    do {
        // Get validated menu choice
        choice = getValidatedMenuChoice();

        switch (choice) {
        case 1: { // Search for an item
            string item = getValidatedItem();
            itemFrequency.searchItem(item);
            break;
        }
        case 2: // Display all frequencies
            itemFrequency.displayFrequencies();
            break;
        case 3: // Display histogram
            itemFrequency.displayHistogram();
            break;
        case 4: // Exit
            cout << "Exiting program. Goodbye!\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
