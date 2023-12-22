#ifndef Inventory_H_INCLUDED
#define Inventory_H_INCLUDED
#include <iostream>
#include <random>
#include <string>

using namespace std;
class Inventory {
public:
    static const int Inventory_Size = 16;

    class Item {
        public:
            string name;

            Item(const string& itemName)
              : name(itemName)
              {
              }
    };

    Inventory() 
      : grid(Inventory_Size, nullptr)
    {
    }

    bool addItem(Item* newItem) {
        for (int i = 0; i< Inventory_Size; i++) {
            if (grid[i] == nullptr) {
                grid[i] = newItem;
                return true;
            }
        }
        cout << "Inventory is full " << endl;
        return false;

        /*
        // Find the index of the next available slot
        int idx = 0;
        while (grid[idx] != nullptr && idx < Inventory_Size) {
            ++idx;
        }

        // If there are not empty slots... the item can not be added
        if (idx >= Inventory_Size) {
            cout << "Inventory is full " << endl;
            return false;
        }

        // If we make it here... the item can be added because there is room
        grid[idx] = newItem;
        return true;
        */

    }

    // not really sure about making this const-- at one side it is const until added on the other this just feels wrong-- but the display ITSELF is constant
    void display() const {
        for (int i = 0; i < Inventory_Size; i++){
            if (grid[i] != nullptr) {
                cout << grid[i]->name << "\t";
            }
            else {
                cout << "Empty\t";
            }
        }
        cout << endl;
    }

    int getGold() {
        return this->Gold;
    }

    void setGold (int _Gold) {
        this->Gold = _Gold;
    }

    void addGold (Inventory& inv, int _Gold) {
        this->Gold += _Gold;
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
/*
void rollADieForGold(int min, int max, Inventory& inv) {
    int result = getRandomDie(min, max);
    result *= 10;
    result *=5;
    this->addGold(result);
    cout << "Your gold is " << result << endl;
}    
*/
int getRandomDie(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

private:
    int Gold = 1;
    string Armor;
    string Weapon;
    vector <Item*> grid;
};

int getRandomDie(int min, int max);
void rollADieForGold(int min, int max, Inventory& inv);


#endif