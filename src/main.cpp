#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <list>
#include <array>
#include <map>
#include <iterator>
#include <unordered_map>
#include <functional>
#include <unordered_set>
#include <vector>
#include "Item.h"
#include "equippableItem.h"
#include "Adventurer.h"
#include "Inventory.h"

using namespace std;

int main() {
    // const CharacterClass desiredClass = classStringToEnum(promptForSubclass("Rogue", 3));
    // Ignore everything below this line
    int numAdvent;
    list<Adventurer> adventurerList;
    cout << "How many adventurers would you like to create? " << "\n";
    cin >> numAdvent;
    for (int i = 0; i < numAdvent; i++) {
        std::string adventName;
        std::string levelUpInput;
        std::string desiredClass;
        std::string attribute;
        cout << "Enter name for Adventurer " << i + 1 << "\n";
        cin >> adventName;
        Adventurer advent(adventName, desiredClass);
        while(true){
            cout << "Would you like to increase your Adventurer's level further? " << "\n";
            cin >> levelUpInput;
            if(levelUpInput == "yes" || levelUpInput == "y"){
                advent.performLevelUp(advent);
                cout << "Your previous level was " << advent.getLevel() - 1 << "\n";
                cout << "Your current level is " << advent.getLevel() << "\n";
            } else if (levelUpInput == "no" || levelUpInput == "n"){
                break;
                // I want to put promptForSubclass() here;
            } else {
                cout << "Invalid input. Please enter \"(Y)es\" or \"(N)o\" " << "\n";
            }
        }
        advent.promptForClass(desiredClass);
        Inventory inventory = generateInitialInventory(desiredClass);
        advent.replaceInventory(inventory);
        adventurerList.push_back(advent);
    }
    list<Adventurer>::iterator adventureritr;
    for (adventureritr = adventurerList.begin(); adventureritr != adventurerList.end(); adventureritr++) {
        cout << *adventureritr;
    }

    return 0;
}