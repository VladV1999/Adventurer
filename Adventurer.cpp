#include <iostream>
#include <string>
#include <random>
#include <list>
#include <array>
#include <iterator>
#include <unordered_map>
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
class Class {
    public:
    string getCleric() {
        return this->Cleric;
    }
    void setCleric (string _Cleric) {
        this->Cleric = _Cleric;
    }
    string getArtificier() {
        return this->Artificier;
    }
    void setArtificier (string _Artificier) {
        this->Artificier = _Artificier;
    }
    string getBarbarian() {
        return this->Barbarian;
    }
    void setBarbarian (string _Barbarian) {
        this->Barbarian = _Barbarian;
    }
    string getBard() {
        return this->Bard;
    }
    void setBard (string _Bard) {
        this->Bard = _Bard;
    }
    string getDruid() {
        return this->Druid;
    }
    void setDruid (string _Druid) {
        this->Druid = _Druid;
    }
    string getFighter() {
        return this->Fighter;
    }
    void setFighter (string _Fighter) {
        this->Fighter = _Fighter;
    }
    string getMonk() {
        return this->Monk;
    }
    void setMonk (string _Monk) {
        this->Monk = _Monk;
    }
    string getPaladin() {
        return this->Paladin;
    }
    void setPaladin (string _Paladin) {
        this->Paladin = _Paladin;
    }
    string getRanger() {
        return this->Ranger;
    }
    void setRanger (string _Ranger) {
        this->Ranger = _Ranger;
    }
    string getRogue() {
        return this->Rogue;
    }
    void setRogue (string _Rogue) {
        this->Rogue = _Rogue;
    }
    string getSorcerer() {
        return this->Sorcerer;
    }
    void setSorcerer (string _Sorcerer) {
        this->Sorcerer = _Sorcerer;
    }
    string getWarlock() {
        return this->Warlock;
    }
    void setWarlock (string _Warlock) {
        this->Warlock = _Warlock;
    }
    string getWizard() {
        return this->Wizard;
    }
    void setWizard (string _Wizard) {
        this->Wizard = _Wizard;
    }
    
    private:
    string Cleric;
    string Artificier;
    string Barbarian;
    string Bard;
    string Druid;
    string Fighter;
    string Monk;
    string Paladin;
    string Ranger;
    string Rogue;
    string Sorcerer;
    string Warlock;
    string Wizard;
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
    void setArmor (int _Armor) {
        this->Armor = _Armor;
    }
    string getWeapon() {
        return this->Weapon;
    }
    void setWeapon (int _Weapon) {
        this->Weapon = _Weapon;
    }
    void receiveGear() {
        }
    
private:
    int Gold = 1;
    string Armor = "Great Chainmail";
    string Weapon = "Sword of Fire";
};

void performLevelUp(Adventurer& advent) {
    advent.levelUp();
    int pointsToAllocate = 2;
    if (pointsToAllocate > 0) {
        while (pointsToAllocate > 0) {
            string attribute;
            cout << "Which attribute would you like to increase?" << endl;
            cin >> attribute;

            if (attribute == "Dexterity") {
                advent.addToDexterity(1);
                cout << "Your Dexterity was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == "Strength") {
                advent.addToStrength(1);
                cout << "Your Strength was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == "Wisdom") {
                advent.addToWisdom(1);
                cout << "Your Wisdom was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == "Charisma") {
                advent.addToCharisma(1);
                cout << "Your Charisma was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == "Intelligence") {
                advent.addToIntelligence(1);
                cout << "Your Intelligence was increased by 1" << endl;
                pointsToAllocate--;
            }
            else if (attribute == "Constitution") {
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
    return 0;
};