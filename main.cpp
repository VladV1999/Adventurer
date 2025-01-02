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

string reusable(string prompt, string tryAgainPrompt, const unordered_set<string>& legalValues);

static const unordered_map<string, Attribute> attributeMap = {
    {"Dexterity", Attribute::Dexterity},
    {"Strength", Attribute::Strength},
    {"Wisdom", Attribute::Wisdom},
    {"Charisma", Attribute::Charisma},
    {"Intelligence", Attribute::Intelligence},
    {"Constitution", Attribute::Constitution},
    {"Invalid", Attribute::InvalidAttribute}
};

static const unordered_map<string, CharacterClass> CHARACTER_CLASS_MAP = {
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

const unordered_map<string, unordered_set<string>> SUBCLASS_MAPPINGS = {
        {
            "Rogue",
            {
                "Arcane Trickster",
                "Thief",
                "Assassin",
                "Inquisitive",
                "Phantom",
                "Mastermind",
                "Scout",
                "Soulknife",
                "Swashbuckler"
            }
        },
        {
            "Wizard", 
            {
                "Bladesinger",
                "Chronurgy Magician",
                "Graviturgy Magician",
                "Order of Scribes",
                "School of Abjuration",
                "School of Conjuration",
                "School of Divination",
                "School of Enchantment",
                "School of Evocation",
                "School of Illusion",
                "School of Necromancy",
                "School of Transmutation",
                "School of War Magic"
            }
        },
        {
            "Cleric",
            {   
                "Arcana Domain",
                "Death Domain",
                "Forge Domain",
                "Grave Domain",
                "Knowledge Domain",
                "Life Domain",
                "Light Domain",
                "Nature Domain",
                "Order Domain",
                "Peace Domain",
                "Tempest Domain",
                "Trickery Domain",
                "Twilight Domain",
                "War Domain"
            }
        },
        {
            "Barbarian",
            {
                "Path of Ancestral Guardian",
                "Path of the Battlerager",
                "Path of the Beast",
                "Path of the Berserker",
                "Path of the Giant",
                "Path of the Storm Herald",
                "Path of the Totem Warrior",
                "Path of the Zealot",
                "Path of Wild Magic"
            }
        },
        {
            "Bard",
            {
                "College of Creation",
                "College of Eloquence",
                "College of Glamour",
                "College of Lore",
                "College of Spirits",
                "College of Swords",
                "College of Valor",
                "College of Whispers"
            }
        },
        {
            "Artificier",
            {
                "Alchemist",
                "Armorer",
                "Artillerist",
                "Battle Smith"
            }
        },
        {
            "Druid",
            {
                "Circle of Dreams",
                "Circle of Spores",
                "Circle of Stars",
                "Circle of Wildfire",
                "Circle of the Land",
                "Circle of the Moon",
                "Circle of the Shepherd"
            }
        },
        {
            "Fighter",
            {
                "Arcane Archer",
                "Battle Master",
                "Cavalier",
                "Champion",
                "Echo Knight",
                "Eldritch Knight",
                "Psi Warrior",
                "Banneret",
                "Rune Knight",
                "Samurai"
            }
        },
        {
            "Monk",
            {
                "Way of Mercy",
                "Way of Shadow",
                "Way of The Ascendant Dragon",
                "Way of the Astral Self",
                "Way of the Drunken Master",
                "Way of the Four Elements",
                "Way of the Kensei",
                "Way of the Long Death",
                "Way of the Open Hand",
                "Way of the Sun Soul"
            }
        },
        {
            "Paladin",
            {
                "Oath of Conquest",
                "Oath of Devotion",
                "Oath of Glory",
                "Oath of Redemption",
                "Oath of the Ancients",
                "Oath of the Crown",
                "Oath of the Watchers",
                "Oath of Vengeance",
                "Oathbreaker"
            }
        },
        {
            "Ranger",
            {
                "Beast Master",
                "Drakewarden",
                "Fey Wanderer",
                "Gloom Stalker",
                "Horizon Walker",
                "Hunter",
                "Monster Slayer",
                "Swarmkeeper"
            }
        },
        {
            "Sorcerer",
            {
                "Abberant Mind",
                "Clockwork Soul",
                "Divine Soul",
                "Draconic Bloodline",
                "Lunar Sorcery",
                "Shadow Magic",
                "Storm Sorcery",
                "Wild Magic"
            }
        },
        {
            "Warlock",
            {
                "The Archfey",
                "The Celestial",
                "The Fathomless",
                "The Fiend",
                "The Genie",
                "The Great Old One",
                "The Hexblade",
                "The Undead",
                "The Undying"
            }
        }
};

//----------------------------------------------------------------------------------------------------------------------

//@todo
//utilize this table
//and ask about how I'm supposed to convert in in Adventurer
//I want character Class to be a part of Adventurer
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
    return stringToEnum(str, CHARACTER_CLASS_MAP, CharacterClass::InvalidClass);
}

string promptForClass() {
    string selectedClass;
    bool validChoice = false;
    Attribute Attribute = attributeStringToEnum(selectedClass); 
    while (!validChoice) {
        cout << "What class would you like to choose? " << endl;
        cin >> selectedClass;

        if (CHARACTER_CLASS_MAP.find(selectedClass) != CHARACTER_CLASS_MAP.end()) {
            cout << "You have chosen " << selectedClass << endl;
            validChoice = true;
        }
        else {
            cout << "Please choose a valid class " << endl;
        }
    }

    return selectedClass;
};
//check the SUBCLASS_MAPPING const error
string promptForSubclass(const string theClass, int theLevel) {

    if (SUBCLASS_MAPPINGS.find(theClass) == SUBCLASS_MAPPINGS.end()) {
        return "Invalid Class";
    }

    if (theLevel < 3) {
        return "Get back to \"The Grind\"";
    }

    const auto& subclassMap = SUBCLASS_MAPPINGS.find(theClass)->second;

    string selectedSubclass = reusable(
        "What subclass would you like to choose? ",
        "Please choose a valid subclass ",
        subclassMap
    );
    return selectedSubclass;
}

string reusable(string prompt, string tryAgainPrompt, const unordered_set<string>& legalValues) {
    string selection;
    bool validChoice = false;
    //Attribute Attribute = attributeStringToEnum(selectedSubclass); 
    while (!validChoice) {
        cout << prompt << endl;
        std::getline(std::cin, selection);

        if (legalValues.find(selection) != legalValues.end()) {
            cout << "You have chosen " << selection << endl;
            validChoice = true;
        }
        else {
            cout << tryAgainPrompt << endl;
        }
    }

    return selection;
}
// @todo should not be here and should be in adventurer
// also, the else ifs are painful, switch statement will do
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
// @todo....... this is a big mess, clean everything up from main,
// it is too cluttered
int main() {
    // const CharacterClass desiredClass = classStringToEnum(promptForSubclass("Rogue", 3));
    // Ignore everything below this line
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
                // I want to put promptForSubclass() here;
            } else {
                cout << "Invalid input. Please enter \"(Y)es\" or \"(N)o\" " << endl;
            }
        }
        const string theClass = promptForClass();
        Inventory inventory = generateInitialInventory(theClass);
        advent.replaceInventory(inventory);
        adventurerList.push_back(advent);
    }
    list<Adventurer>::iterator adventureritr;
    for (adventureritr = adventurerList.begin(); adventureritr != adventurerList.end(); adventureritr++) {
        //adventureritr->Adventurer::display();
        cout << *adventureritr;
    }

    //--------------------------------------------------------------------------
    Adventurer me("A. Noob");

    return 0;
}