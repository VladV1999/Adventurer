#ifndef ADVENTURER_H_INCLUDED
#define ADVENTURER_H_INCLUDED

#include <iostream>
#include <random>
#include <string>

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
        int getDexterity() {
            return this->Dexterity;
        }
        void setStrength(int _Strength) {
            this->Strength = _Strength;
        }
        int getStrength() {
            return this->Strength;
        }
        void setConstitution(int _Constitution) {
            this->Constitution = _Constitution;
        }
        int getConstitution() {
            return this->Constitution;
        }
        void setIntelligence(int _Intelligence) {
            this->Intelligence = _Intelligence;
        }
        int getIntelligence() {
            return this->Intelligence;
        }
        void setCharisma(int _Charisma) {
            this->Charisma = _Charisma;
        }
        int getCharisma() {
            return this->Charisma;
        }
        void setWisdom(int _Wisdom) {
            this->Wisdom = _Wisdom;
        }
        
        void addToWisdom(int points) {
            this->Wisdom += points;
        }

        void addToStrength(int points) {
            this->Strength += points;
        }

        void addToIntelligence(int points) {
            this->Intelligence += points;
        }

        void addToDexterity(int points) {
            this->Dexterity += points;
        }

        void addToConstitution(int points) {
            this->Constitution += points;
        }

        void addToCharisma(int points) {
            this->Charisma += points;
        }

        int getWisdom() {
            return this->Wisdom;
        }
        string getName() {
            return this->Name;
        }
        void setName(string _Name) {
            this->Name = _Name;
        }
        int getLevel() {
            return this->Level;
        }
        int getRandomNumber(int min, int max) {
            return -1;
        }
        void levelUp() {
            this->Level=this->Level+1;
        }
                    
        void display();

    private:
        string Name;
        int Dexterity;
        int Strength;
        int Constitution;
        int Intelligence;
        int Charisma;
        int Wisdom;
        int Level;

};

#endif