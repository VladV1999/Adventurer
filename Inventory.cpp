#include "Inventory.h"

using namespace std;

Inventory::Inventory()
    : grid(Inventory_Size, nullptr) {

    }
bool Inventory::addItem(Item* newItem) {
    for (int i = 0; i< Inventory_Size; i++) {
        if (grid[i] == nullptr) {
        grid[i] = newItem;
        return true;
            }
        }
        cout << "Inventory is full " << endl;
        return false;
}
void rollADieForGold(int min, int max, Inventory& inv);

void rollADieForGold(int min, int max, Inventory& inv) {
    int result = getRandomDie(min, max);
    result *= 10;
    result *=5;
    inv.addGold(inv, result);
    cout << "Your gold is " << result << endl;
}  

int getRandomDie(int min, int max);

int getRandomDie(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

void Inventory::display() const {
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

    int Inventory::getGold() {
    return this->Gold;
}

void Inventory::setGold (int _Gold) {
    this->Gold = _Gold;
}

void Inventory::addGold (Inventory& inv, int _Gold) {
    this->Gold += _Gold;
}

string Inventory::getArmor() {
    return this->Armor;
}

void Inventory::setArmor (string _Armor) {
    this->Armor = _Armor;
}

string Inventory::getWeapon() {
    return this->Weapon;
}

void Inventory::setWeapon (string _Weapon) {
    this->Weapon = _Weapon;
}