/// instead of string inputs try to do string enums they will help you locate an error at compile time
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
#include <unordered_set>

using namespace std;

class Inventory;

enum class Attribute {
    Dexterity,
    Strength,
    Wisdom,
    Charisma,
    Intelligence,
    Constitution,
    InvalidAttribute
};

enum class CharacterClass {
    Cleric,
    Artificier,
    Barbarian,
    Bard,
    Druid,
    Fighter,
    Monk,
    Paladin,
    Ranger,
    Sorcerer,
    Warlock,
    Wizard,
    Rogue,
    InvalidClass
};

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
    /*
    const auto it = attributeMap.find(str);

    if (it == attributeMap.end()) {
        return Attribute::InvalidAttribute;
    }
    
    return it->second;
    
    ///The line above i'm a bit unsure of, wouldn't it return dexterity by all means?
    */
    return stringToEnum(str, attributeMap, Attribute::InvalidAttribute);
}

CharacterClass classStringToEnum(const string& str) {
    return stringToEnum(str, characterClassMap, CharacterClass::InvalidClass);
}


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
    Attribute Attribute = attributeStringToEnum(selectedClass); ///First test case of using string to string Enum
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