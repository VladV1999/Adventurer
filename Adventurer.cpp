#include <iostream>
#include <string>
#include <random>
#include <list>
#include <array>
#include <map>
#include <iterator>
#include <unordered_map>
#include <functional>
#include "Adventurer.h"

using namespace std;

class Inventory;

Adventurer::Adventurer (string newname) {

    //Inventory inventory;
        Name = newname;
        Dexterity = getRandomNumber(4, 6);
        Strength = getRandomNumber(4, 6);
        Constitution = getRandomNumber(4, 6);
        Intelligence = getRandomNumber(4, 6);
        Charisma = getRandomNumber(4, 6);
        Wisdom = getRandomNumber(4, 6);
        Level = 1;

};

class Inventory {
public:
    int getRandomDie(int min, int max) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(min, max);
        return dis(gen);
    }
    void rollADieForGold(int min, int max) {
        int result = getRandomDie(min, max);
        result *= 10;
        result *=5;
        this->Gold = result;
        cout << "Your gold is " << result << endl;
    }
    int getGold() {
        return this->Gold;
    }
    void setGold (int _Gold) {
        this->Gold = _Gold;
    }
    string getArmor() {
        return this->Armor;
    }
    void setArmor (string _Armor) {
        this->Armor = _Armor;
    }
    string getWeapon() {
        return this->Weapon;
    }
    void setWeapon (string _Weapon) {
        this->Weapon = _Weapon;
    }

    
private:
    int Gold = 1;
    string Armor;
    string Weapon;
};

Inventory generateInitialInventory(std::string theClass) {
    Inventory bagOfHolding;
    if (theClass == "Cleric") {
        bagOfHolding.setArmor("Light Chainmail");
        bagOfHolding.setWeapon("Morningstar and Light Shield");
    }
    else {
        std::cerr << "Invalid Class" << '\n';
    }

    return bagOfHolding;
}
// After thinking about it, will this simply be a normal set?
// Or perhaps a type of inventory (the generation of initial inventory is fine but I can't seem to get)
// the set for it.
// Is it even necessary?
//  Inventory setInitialInventory() {

//  }

std::string promptForClass() {
    unordered_map<string, string> classMap;
    classMap["Cleric"] = " ";
    classMap["Artificier"] = " ";
    classMap["Barbarian"] = " ";
    classMap["Bard"] = " ";
    classMap["Druid"] = " ";
    classMap["Fighter"] = " ";
    classMap["Monk"] = " ";
    classMap["Paladin"] = " ";
    classMap["Ranger"] = " ";
    classMap["Sorcerer"] = " ";
    classMap["Warlock"] = " ";
    classMap["Wizard"] = " ";
    classMap["Rogue"] = " ";

    string selectedClass;
    bool validChoice = false;
    while (!validChoice) {
        cout << "What class would you like to choose? " << endl;
        cin >> selectedClass;

        if (classMap.find(selectedClass) != classMap.end()) {
            cout << "You have chosen " << selectedClass << classMap[selectedClass] << endl;
            validChoice = true;
        }
        else {
            cout << "Please choose a valid class " << endl;
        }
    }

    return selectedClass;
}

void performLevelUp(Adventurer& advent) {
    advent.levelUp();
    int pointsToAllocate = 2;
    if (pointsToAllocate > 0) {
        while (pointsToAllocate > 0) {
            string attribute;
            cout << "Which attribute would you like to increase?" << endl;
            cin >> attribute;

            if (attribute == "Dexterity") {
                advent.addToDexterity(1);
                cout << "Your Dexterity was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == "Strength") {
                advent.addToStrength(1);
                cout << "Your Strength was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == "Wisdom") {
                advent.addToWisdom(1);
                cout << "Your Wisdom was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == "Charisma") {
                advent.addToCharisma(1);
                cout << "Your Charisma was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == "Intelligence") {
                advent.addToIntelligence(1);
                cout << "Your Intelligence was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == "Constitution") {
                advent.addToConstitution(1);
                cout << "Your Constitution was increased by 1" << endl;
                pointsToAllocate--;
            }

            else {
                cout << "Please enter a valid attribute" << endl;
            }
        }
    }
};

int main() {
    int numAdvent;
    list<Adventurer> adventurerList;
    cout << "How many adventurers would you like to create? " << endl;
    cin >> numAdvent;
    for (int i = 0; i < numAdvent; i++) {
        string adventName;
        string levelUpInput;
        string attribute;
        cout << "Enter name for Adventurer " << i + 1 << endl;
        cin >> adventName;
        Adventurer advent(adventName);
        while(true){
            cout << "Would you like to increase your Adventurer's level further? " << endl;
            cin >> levelUpInput;
            if(levelUpInput == "yes" || levelUpInput == "y"){
                performLevelUp(advent);
                cout << "Your previous level was " << advent.getLevel() << endl;
                cout << "Your current level is " << advent.getLevel() << endl;
            } else if (levelUpInput == "no" || levelUpInput == "n"){
                break;
            } else {
                cout << "Invalid input. Please enter \"(Y)es\" or \"(N)o\" " << endl;
            }
        }
        adventurerList.push_back(advent);
    }
    list<Adventurer>::iterator adventureritr;
    for (adventureritr = adventurerList.begin(); adventureritr != adventurerList.end(); adventureritr++) {
        adventureritr->display();
    }
    Inventory inventory;
    inventory.rollADieForGold(1, 4);
    //ClassChoice Clazz;
    //Clazz.classDetermination();
    
    for (adventureritr = adventurerList.begin(); adventureritr != adventurerList.end(); adventureritr++) {
        adventureritr->display();
    }
    // for (const Adventurer& adventurer : adventurerList) {
    //     //Did Dr. Kennedy mean adventureritr?
    //     //simply having adventurer here displays the message of:
    //     //passing 'const Adventurer' as 'this' argument discards qualifiers [-fpermissive]
    //     adventurer.display();
    // }


    //--------------------------------------------------------------------------
    std::string selectedClass = promptForClass();
    // Generate starting inventory
    // Generate starting skills
    // Generate starting spells
    Inventory startingInventory = generateInitialInventory(selectedClass);
    Adventurer me("A. Noob");
    // me.setInventory(startingInventory);

    return 0;
};