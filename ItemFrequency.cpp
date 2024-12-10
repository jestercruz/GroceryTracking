/* Jester Cruz
   12/10/2024
   A program for Corner Grocer that takes a file and creates another file containing
   the frequency of each entry.
*/

#include "ItemFrequency.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower

using namespace std;

// Utility function to convert a string to lowercase
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

// Constructor: Reads the input file and saves data to backup
ItemFrequency::ItemFrequency(const string& inputFileName, const string& backupFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Input file '" << inputFileName << "' not found or inaccessible.\n";
        exit(EXIT_FAILURE); // Exit program if the file can't be opened
    }

    readInputFile(inputFileName);
    saveToBackupFile(backupFileName);
}

// Reads the input file and populates the map
void ItemFrequency::readInputFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    std::string item;
    if (inputFile.is_open()) {
        while (inputFile >> item) {
            std::string lowerItem = toLowerCase(item);
            if (frequencyMap.find(lowerItem) == frequencyMap.end()) {
                // Insert the original word with a count of 1
                frequencyMap[lowerItem] = { item, 1 };
            }
            else {
                // Increment the frequency
                frequencyMap[lowerItem].second++;
            }
        }
        if (frequencyMap.empty()) {
            std::cerr << "Error: Input file '" << fileName << "' is empty.\n";
            exit(EXIT_FAILURE);
        }
        inputFile.close();
    }
    else {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
    }
}

// Saves the map data to a backup file
void ItemFrequency::saveToBackupFile(const std::string& backupFileName) {
    std::ofstream backupFile(backupFileName);
    if (backupFile.is_open()) {
        for (const auto& pair : frequencyMap) {
            backupFile << pair.second.first << " " << pair.second.second << std::endl;
        }
        backupFile.close();
    }
    else {
        std::cerr << "Error: Unable to create backup file." << std::endl;
    }
}

// Searches for a specific item and prints its frequency
void ItemFrequency::searchItem(const std::string& item) const {
    std::string lowerItem = toLowerCase(item); // Convert input to lowercase
    auto it = frequencyMap.find(lowerItem);
    if (it != frequencyMap.end()) {
        std::cout << it->second.first << ": " << it->second.second << " times" << std::endl;
    }
    else {
        std::cout << item << " not found." << std::endl;
    }
}

// Displays all items with their frequencies
void ItemFrequency::displayFrequencies() const {
    for (const auto& pair : frequencyMap) {
        std::cout << std::setw(15) << std::left << pair.second.first << pair.second.second << std::endl;
    }
}

// Displays a histogram of item frequencies
void ItemFrequency::displayHistogram() const {
    for (const auto& pair : frequencyMap) {
        std::cout << std::setw(15) << std::left << pair.second.first << std::string(pair.second.second, '*') << std::endl;
    }
}