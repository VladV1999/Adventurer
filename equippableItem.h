#pragma once
#ifndef EquippableItem_H_INCLUDED
#define EquippableItem_H_INCLUDED
#include <iostream>
#include <string>
#include <random>
#include "Item.h"
#include "Inventory.h"
#include <unordered_map>
#include <utility>

using namespace std;

class EquippableItem : public Item {

public:

    int RNG(int min, int max);

    string getWeaponType();

    string getArmorType();

    static EquippableItem armorTypeDeterminant (string _playerClass);

    void weaponTypeDeterminant (string _playerClass);

    void setArmorType(string _armorType);

    void setWeaponType(string _weaponType);

    // void armorTypeArmorClassDeterminant();

private: 
    static string weaponType;
    static string armorType;
    CharacterClass (*classStringToEnumPtr)(const string&);
};

#endif