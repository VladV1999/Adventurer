#include "Adventurer.h"
#include "Inventory.h"

using namespace std;

        int Adventurer::getDexterity() {
            return this->Dexterity;
        }

        void Adventurer::setDexterity(int _Dexterity) {
            this->Dexterity = _Dexterity;
        }

        void Adventurer::setStrength(int _Strength) {
            this->Strength = _Strength;
        }
        

        int Adventurer::getStrength() {
            return this->Strength;
        }

        void Adventurer::setConstitution(int _Constitution) {
            this->Constitution = _Constitution;
        }

        int Adventurer::getConstitution() {
            return this->Constitution;
        }

        void Adventurer::setIntelligence(int _Intelligence) {
            this->Intelligence = _Intelligence;
        }

        int Adventurer::getIntelligence() {
            return this->Intelligence;
        }

        void Adventurer::setCharisma(int _Charisma) {
            this->Charisma = _Charisma;
        }

        int Adventurer::getCharisma() {
            return this->Charisma;
        }
        void Adventurer::setWisdom(int _Wisdom) {
            this->Wisdom = _Wisdom;
        }

        void Adventurer::addToWisdom(int points) {
            this->Wisdom += points;
        }

        void Adventurer::addToStrength(int points) {
            this->Strength += points;
        }

        void Adventurer::addToIntelligence(int points) {
            this->Intelligence += points;
        }

        void Adventurer::addToDexterity(int points) {
            this->Dexterity += points;
        }

        void Adventurer::addToConstitution(int points) {
            this->Constitution += points;
        }

        void Adventurer::addToCharisma(int points) {
            this->Charisma += points;
        }

        int Adventurer::getWisdom() {
            return this->Wisdom;
        }

        string Adventurer::getName() {
            return this->Name;
        }

        void Adventurer::setName(string _Name) {
            this->Name = _Name;
        }

        int Adventurer::getLevel() {
            return this->Level;
        }

        void Adventurer::levelUp() {
            this->Level=this->Level+1;
        }
        // //this entire method needs work but I want to do this with string enums, ask
        // void Adventurer::populateInventory(CharacterClass characterclass) {
        //     switch (characterclass)
        //     {
        //     case CharacterClass::Cleric:
                
        //         this->inventory.addItem(Item &newItem)
        //         break;
            
        //     default:
        //         break;
        //     }
        // }

        int Adventurer::getRandomNumber(int min, int max) {
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> distribution(min, max);
        return distribution(gen);
    }

Adventurer::Adventurer (string newname) {
        Name = newname;
        Dexterity = getRandomNumber(4, 6);
        Strength = getRandomNumber(4, 6);
        Constitution = getRandomNumber(4, 6);
        Intelligence = getRandomNumber(4, 6);
        Charisma = getRandomNumber(4, 6);
        Wisdom = getRandomNumber(4, 6);
        Level = 1;
}

void Adventurer::display() {
    cout << "Name: " << this->getName() << endl;
    cout << "Dexterity: " << this->getDexterity() << endl;
    cout << "Strength: " << this->getStrength() << endl;
    cout << "Constitution: " << this->getConstitution() << endl;
    cout << "Intelligence: " << this->getIntelligence() << endl;
    cout << "Charisma: " << this->getCharisma() << endl;
    cout << "Wisdom: " << this->getWisdom() << endl;
    cout << "Level " << this->getLevel() << endl;
    this->inventory.display();
}

void Adventurer::replaceInventory(Inventory inv) {
    inventory = inv;
}