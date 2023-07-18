#include <iostream>
#include <string>
#include <random>
#include <list>
#include <array>
#include <iterator>
#include <random>
#include <functional>

using namespace std;

class Adventurer {
    public:
        Adventurer(string newname) {
            Name = newname;
            Dexterity = getRandomNumber(4, 6);
            Strength = getRandomNumber(4, 6);
            Constitution = getRandomNumber(4, 6);
            Intelligence = getRandomNumber(4, 6);
            Charisma = getRandomNumber(4, 6);
            Wisdom = getRandomNumber(4, 6);
            Level = 1;
        }
        void display() {
            cout << "Name: " << this->getName() << endl;
            cout << "Dexterity: " << this->getDexterity() << endl;
            cout << "Strength: " << this->getStrength() << endl;
            cout << "Constitution: " << this->getConstitution() << endl;
            cout << "Intelligence: " << this->getIntelligence() << endl;
            cout << "Charisma: " << this->getCharisma() << endl;
            cout << "Wisdom: " << this->getWisdom() << endl;
            cout << "Level " << this->getLevel() << endl;
        }

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
        int getWisdom() {
            return this->Wisdom;
        }
        string getName() {
            return this->Name;
        }
        void setName(string _Name) {
            this->Name = _Name;
        }


    private:
        string Name;
        int Dexterity;
        int Strength;
        int Constitution;
        int Intelligence;
        int Charisma;
        int Wisdom;  
        int getRandomNumber(int min, int max) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dis(min, max);
            return dis(gen);
        }
};
int main() {
    int numAdvent;
    list<Adventurer> adventurerList; 
    cout << "How many adventurers would you like to create? " << endl;
    cin >> numAdvent;
    for (int i = 0; i < numAdvent; i++) {
        string adventName;
        cout << "Enter name for Adventurer " << i + 1 << endl;
        cin >> adventName; 
        Adventurer advent(adventName);
        adventurerList.push_back(advent);
    }
    list<Adventurer>::iterator adventureritr;
    for (adventureritr = adventurerList.begin(); adventureritr != adventurerList.end(); adventureritr++) {
        adventureritr->display();
    }
    return 0;
};