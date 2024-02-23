#pragma once
#ifndef Inventory_H_INCLUDED
#define Inventory_H_INCLUDED
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Item.h"

using namespace std;
class Inventory {
public:
    static const int Inventory_Size = 16;

    Inventory();

    bool addItem(Item &newItem);

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
    ;
    
    // not really sure about making this const-- at one side it is const until added on the other this just feels wrong-- but the display ITSELF is constant
    void display(ostream& outs) const;

    int getGold();

    void setGold (int _Gold);

    void addGold (Inventory& inv, int _Gold);

    string getArmor();

    void setArmor (string _Armor);

    string getWeapon();

    void setWeapon (string _Weapon);

    string getclassItem();

    void setClassItem(string _classItem);

/*
void rollADieForGold(int min, int max, Inventory& inv) {
    int result = getRandomDie(min, max);
    result *= 10;
    result *=5;
    this->addGold(result);
    cout << "Your gold is " << result << endl;
}    
*/

private:
    int Gold = 1;
    Item Armor;
    Item Weapon;
    vector<Item> grid;
    Item classItem;
};

int getRandomDie(int min, int max);
void rollADieForGold(int min, int max, Inventory& inv);

ostream& operator<<(ostream& outs, const Inventory& inv);

Inventory generateInitialInventory(std::string theClass);

#endif