#include "Adventurer.h"

using namespace std;

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
}

