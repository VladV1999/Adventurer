#include <iostream>
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
#include "Adventurer.h"
#include "Inventory.h"

using namespace std;

static const unordered_map<string, Attribute> attributeMap = {
    {"Dexterity", Attribute::Dexterity},
    {"Strength", Attribute::Strength},
    {"Wisdom", Attribute::Wisdom},
    {"Charisma", Attribute::Charisma},
    {"Intelligence", Attribute::Intelligence},
    {"Constitution", Attribute::Constitution},
    {"Invalid", Attribute::InvalidAttribute}
};

static const unordered_map<string, CharacterClass> characterClassMap = {
    {"Cleric", CharacterClass::Cleric},
    {"Artificier", CharacterClass::Artificier},
    {"Barbarian", CharacterClass::Barbarian},
    {"Bard", CharacterClass::Bard},
    {"Druid", CharacterClass::Druid},
    {"Fighter", CharacterClass::Fighter},
    {"Monk", CharacterClass::Monk},
    {"Paladin", CharacterClass::Paladin},
    {"Ranger", CharacterClass::Ranger},
    {"Sorcerer", CharacterClass::Sorcerer},
    {"Warlock", CharacterClass::Warlock},
    {"Wizard", CharacterClass::Wizard},
    {"Rogue", CharacterClass::Rogue},
    {"Invalid", CharacterClass::InvalidClass}
};
template<typename EnumType>
EnumType stringToEnum(const string& str, const unordered_map<string, EnumType>& lookupTable, const EnumType defaultValue) {
    const auto it = lookupTable.find(str);

    if (it == lookupTable.end()) {        
        return defaultValue;
    }
    
    const EnumType foundValue = it->second;
    return foundValue;
}

Attribute attributeStringToEnum(const string& str) {
    return stringToEnum(str, attributeMap, Attribute::InvalidAttribute);
}

CharacterClass classStringToEnum(const string& str) {
    return stringToEnum(str, characterClassMap, CharacterClass::InvalidClass);
}


// @todo 
Inventory generateInitialInventory(std::string theClass) {
    Inventory bagOfHolding;
    if (theClass == "Cleric") {
        bagOfHolding.setArmor("Light Chainmail");
        bagOfHolding.setWeapon("Morningstar and Light Shield");
        bagOfHolding.setClassItem("Holy Sigil");
    }
    else if (theClass == "Wizard") {
        bagOfHolding.setArmor("Robes");
        bagOfHolding.setWeapon("Quarterstaff");
        bagOfHolding.setClassItem("Focus");
    }
    else if (theClass == "Artificier") {
        bagOfHolding.setArmor("Leather Armor");
        bagOfHolding.setWeapon("Hammer");
        bagOfHolding.setClassItem("Tinker's Tools");
    }    
    else if (theClass == "Barbarian") {
        bagOfHolding.setArmor("Hide Armor");
        bagOfHolding.setWeapon("Battleaxe");
    }    
    else if (theClass == "Druid") {
        bagOfHolding.setArmor("Bear Fur");
        bagOfHolding.setWeapon("Club");
    }    
    else if (theClass == "Bard") {
        bagOfHolding.setArmor("Light Armor");
        bagOfHolding.setWeapon("Daggers");
        bagOfHolding.setClassItem("Musical Instrument"); //make method to let user choose their instrument later on
    }    
    else if (theClass == "Rogue") {
        bagOfHolding.setArmor("Leather Armor");
        bagOfHolding.setWeapon("Daggers");
    }    
    else if (theClass == "Fighter") {
        bagOfHolding.setArmor("Chain Mail");
        bagOfHolding.setWeapon("Longsword");
    }
    else if (theClass == "Monk") {
        bagOfHolding.setArmor("Robes");
        bagOfHolding.setWeapon("Quarterstaff");
    }
    else if (theClass == "Paladin") {
        bagOfHolding.setArmor("Half Plate Armor");
        bagOfHolding.setWeapon("Longsword");
    }
    else if (theClass == "Ranger") {
        bagOfHolding.setArmor("Leather Armor");
        bagOfHolding.setWeapon("Longbow");
    }
    else if (theClass == "Sorcerer") {
        bagOfHolding.setArmor("Robes");
        bagOfHolding.setWeapon("Quarterstaff");
    }
    else if (theClass == "Warlock") {
        bagOfHolding.setArmor("Robes");
        bagOfHolding.setWeapon("Dagger"); //add a method that lets user choose specific weapon if they choose subclass of pact of the blade
        bagOfHolding.setClassItem("To be determined for subclass"); // add a method that lets user choose class Item if they choose any subclass
    }             
    else {
        cerr << "Invalid Class" << '\n';
    }

    return bagOfHolding;
}
// After thinking about it, will this simply be a normal set?
// Or perhaps a type of inventory (the generation of initial inventory is fine but I can't seem to get)
// the set for it.
// Is it even necessary?
//  Inventory setInitialInventory() {

//  }

string promptForClass() {
    unordered_set<string> classSet = {
        "Cleric",
        "Artificier",
        "Barbarian",
        "Bard",
        "Druid",
        "Fighter",
        "Monk",
        "Paladin",
        "Ranger",
        "Sorcerer",
        "Warlock",
        "Wizard",
        "Rogue"
    };

    string selectedClass;
    bool validChoice = false;
    Attribute Attribute = attributeStringToEnum(selectedClass); 
    while (!validChoice) {
        cout << "What class would you like to choose? " << endl;
        cin >> selectedClass;

        if (classSet.find(selectedClass) != classSet.end()) {
            cout << "You have chosen " << selectedClass << endl;
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
            string attributeStr;
            cout << "Which attribute would you like to increase?" << endl;
            cin >> attributeStr;
            Attribute attribute = attributeStringToEnum(attributeStr);

            if (attribute == Attribute::Dexterity) {
                advent.addToDexterity(1);
                cout << "Your Dexterity was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == Attribute::Strength) {
                advent.addToStrength(1);
                cout << "Your Strength was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == Attribute::Wisdom) {
                advent.addToWisdom(1);
                cout << "Your Wisdom was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == Attribute::Charisma) {
                advent.addToCharisma(1);
                cout << "Your Charisma was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == Attribute::Intelligence) {
                advent.addToIntelligence(1);
                cout << "Your Intelligence was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == Attribute:: Constitution) {
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
        string selectedClass = promptForClass();
        Inventory inventory = generateInitialInventory(selectedClass);
        advent.replaceInventory(inventory);
        adventurerList.push_back(advent);
    }
    list<Adventurer>::iterator adventureritr;
    for (adventureritr = adventurerList.begin(); adventureritr != adventurerList.end(); adventureritr++) {
        adventureritr->Adventurer::display();
    }
    // Inventory inventory;
    // Inventory::Item sword("Sword");
    // Inventory::Item shield("Shield");
    // Inventory::Item potion("Health Potion");
    // bool result = inventory.addItem(&sword);
    // result = inventory.addItem(&shield);
    // result = inventory.addItem(&potion);

    // if (!result) {
    //     // the "too full output"
    // }

    //inventory.display();
    //rollADieForGold(1, 4, inventory);
    
    for (adventureritr = adventurerList.begin(); adventureritr != adventurerList.end(); adventureritr++) {
        adventureritr->display();
    }

    //--------------------------------------------------------------------------
    Adventurer me("A. Noob");

    return 0;
};