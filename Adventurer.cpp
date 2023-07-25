#include <iostream>
#include <string>
#include <random>
#include <list>
#include <array>
#include <iterator>
#include <unordered_map>

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
        void levelUp() {
            this->Level=this->Level+1;
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
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dis(min, max);
            return dis(gen);
        }
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

void performLevelUp(Adventurer& advent) {
    advent.levelUp();
    int pointsToAllocate =2;
    if (pointsToAllocate > 0) {
        unordered_map<string, function<void(Adventurer&)>> attributeMap = {
            { "Dexterity", &Adventurer::addToDexterity },
            { "Strength", &Adventurer::addToStrength },
            { "Charisma", &Adventurer::addToCharisma },
            { "Intelligence", &Adventurer::addToIntelligence },
            { "Constitution", &Adventurer::addToConstitution },
            { "Wisdom", &Adventurer::addToWisdom }
        };

        while (pointsToAllocate > 0) {
            string attribute;
            cout << "Which attribute would you like to increase?" << endl;
            cin >>attribute;
            auto it = attributeMap.find(attribute);
            if (it!= attributeMap.end()) {
                (it->second)(advent);
                cout << "Your " << attribute << " was increased by 1" << endl;
                pointsToAllocate--;
            }
            else{
                cout << "Please enter a valid attribute" << endl;
            }
            }
        }
    }

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
    return 0;
};