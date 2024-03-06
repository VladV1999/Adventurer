#include "Adventurer.h"
#include "Inventory.h"
#include "equippableItem.h"

using namespace std;

Adventurer::Adventurer (string newname) {
    // charClass = "Cleric";
    Name = newname;
    Dexterity = getRandomNumber(4, 8);
    Strength = getRandomNumber(4, 8);
    Constitution = getRandomNumber(4, 8);
    Intelligence = getRandomNumber(4, 8);
    Charisma = getRandomNumber(4, 8);
    Wisdom = getRandomNumber(4, 8);
    Level = 1;
}

Adventurer::Adventurer(string newname, const CharacterClass desiredClass)
    :Adventurer(newname)
{
    charClass = desiredClass;
}

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

    CharacterClass Adventurer::getCharacterClass() {
        return this->charClass;
    }

    void Adventurer::setCharacterClass(CharacterClass _charClass) {
        this->charClass = _charClass;
    }

    //@todo
    //Find a way to display contents of the enum class
    //find a way to iterate over said contents
    // Adventurer static promptForClass (const unordered_set<string>& CLASS_SET) {
    //     string selection;
    //     cout << "Pick a class " << endl;
    //     for (const auto& it : CLASS_SET) {
    //         cout << it << " ";
    //     }
    //     cout << " " << endl;
    //     return Adventurer(string hi);
    // }

    int Adventurer::getRandomNumber(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}



void Adventurer::display(ostream& outs) const{
    outs << "Name: " << this->Name << endl;
    outs << "Dexterity: " << this->Dexterity << endl;
    outs << "Strength: " << this->Strength << endl;
    outs << "Constitution: " << this->Constitution << endl;
    outs << "Intelligence: " << this->Intelligence << endl;
    outs << "Charisma: " << this->Charisma << endl;
    outs << "Wisdom: " << this->Wisdom << endl;
    outs << "Level " << this->Level << endl;
    outs << inventory;
}

void Adventurer::replaceInventory(Inventory inv) {
    inventory = inv;
}

ostream& operator<<(ostream& outs, const Adventurer adv) {
    adv.display(outs);
    return outs;
}

