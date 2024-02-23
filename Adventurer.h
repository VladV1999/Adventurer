#ifndef ADVENTURER_H_INCLUDED
#define ADVENTURER_H_INCLUDED

#include <iostream>
#include <random>
#include <string>
#include "Inventory.h"
#include <unordered_set>

using std::string;
using std::cout;

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

class Adventurer {
    public:
        Adventurer(string newname);

        Adventurer(string newname, const CharacterClass desiredClass);

        int getDexterity();

        void setDexterity(int _Dexterity) ;

        void setStrength(int _Strength) ;

        int getStrength();

        void setConstitution(int _Constitution);

        int getConstitution(); 

        void setIntelligence(int _Intelligence);

        int getIntelligence(); 

        void setCharisma(int _Charisma);

        int getCharisma();

        void setWisdom(int _Wisdom); 
        
        void addToWisdom(int points); 

        void addToStrength(int points); 

        void addToIntelligence(int points); 

        void addToDexterity(int points); 

        void addToConstitution(int points);

        void addToCharisma(int points); 

        int getWisdom(); 

        string getName(); 

        void setName(string _Name); 

        int getLevel(); 

        int getRandomNumber(int min, int max);

        void levelUp(); 
                    
        void display(ostream& outs) const;

        CharacterClass getCharacterClass();

        void setCharacterClass(CharacterClass _charClass);

        Adventurer promptForClass(const unordered_set<string>& CLASS_SET);

        void replaceInventory(Inventory inv);

    private:
        Inventory inventory;
        string Name;
        int Dexterity;
        int Strength;
        int Constitution;
        int Intelligence;
        int Charisma;
        int Wisdom;
        int Level;
        CharacterClass charClass;

};

ostream& operator<<(ostream& outs, const Adventurer adv);



#endif