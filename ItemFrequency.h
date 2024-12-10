/* Jester Cruz
   12/10/2024
   A program for Corner Grocer that takes a file and creates another file containing
   the frequency of each entry.
*/

#ifndef ITEMFREQUENCY_H
#define ITEMFREQUENCY_H

#include <string>
#include <map>

std::string toLowerCase(const std::string& str);

class ItemFrequency {
private:
    std::map<std::string, std::pair<std::string, int>> frequencyMap; // Map to store item frequencies
    void readInputFile(const std::string& fileName); // Reads input file and populates the map
    void saveToBackupFile(const std::string& backupFileName); // Saves the map to a backup file

public:
    // Constructor to initialize data and save a backup
    ItemFrequency(const std::string& inputFileName, const std::string& backupFileName);

    // Searches for a specific item and prints its frequency
    void searchItem(const std::string& item) const;

    // Displays all items with their frequencies
    void displayFrequencies() const;

    // Displays a histogram of item frequencies
    void displayHistogram() const;
};

#endif // ITEMFREQUENCY_H
