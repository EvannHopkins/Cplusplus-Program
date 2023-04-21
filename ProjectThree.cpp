#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Map to store item name and frequency
    map<string, int> frequencyMap;

    // Open input file and read item names and quantities
    ifstream inputFile("frequency.dat");
    string itemName;
    int itemQuantity;
    while (inputFile >> itemName >> itemQuantity) {
        frequencyMap[itemName] += itemQuantity;
    }

    // Open output file to store frequency data
    ofstream outputFile("frequency.dat");
    for (auto& entry : frequencyMap) {
        outputFile << entry.first << " " << entry.second << endl;
    }

    // Menu options loop
    int choice = 0;
    while (choice != 4) {
        // Print menu options
        cout << "Select an option:" << endl;
        cout << "1. Look up an item frequency" << endl;
        cout << "2. Print frequency list" << endl;
        cout << "3. Print frequency histogram" << endl;
        cout << "4. Exit program" << endl;
        cin >> choice;

        // Handle menu option
        switch (choice) {
        case 1: {
            // Look up an item frequency
            string itemName;
            cout << "Enter item name: ";
            cin >> itemName;
            if (frequencyMap.find(itemName) != frequencyMap.end()) {
                cout << "Frequency of " << itemName << ": " << frequencyMap[itemName] << endl;
            }
            else {
                cout << "Item not found" << endl;
            }
            break;
        }
        case 2: {
            // Print frequency list
            for (auto& entry : frequencyMap) {
                cout << entry.first << " " << entry.second << endl;
            }
            break;
        }
        case 3: {
            // Print frequency histogram
            for (auto& entry : frequencyMap) {
                cout << entry.first << " ";
                for (int i = 0; i < entry.second; i++) {
                    cout << "*";
                }
                cout << endl;
            }
            break;
        }
        case 4: {
            // Exit program
            cout << "Exiting program" << endl;
            break;
        }
        default: {
            // Invalid menu option
            cout << "Invalid menu option, please try again" << endl;
            break;
        }
        }
    }

    return 0;
}