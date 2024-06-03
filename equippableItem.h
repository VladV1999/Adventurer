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
#include <functional>
#include "DiceRoll.h"

using namespace std;

struct hash_Pair {
    template <class pairOne, class pairTwo>
    size_t operator () (const pair<pairOne, pairTwo>& pairs) const {
        auto it1 = hash<pairOne>{}(pairs.first);
        auto it2 = hash<pairOne>{}(pairs.second);

        return it1 ^ it2;
    }
};


class EquippableItem : public Item {

public:

    EquippableItem() = default;

    string getWeaponType();

    string getArmorType();

    static EquippableItem armorTypeDeterminant (string _playerClass);

    EquippableItem weaponTypeDeterminant (string _playerClass);

    void setArmorType(string _armorType);

    void setWeaponType(string _weaponType);

    static EquippableItem armorTypeArmorClassDeterminant(pair<string, string> _armorTypeAndName);

    EquippableItem weaponDamageGenerator(pair<string, string> _weaponTypeAndName);

private: 
    string weaponType;
    string armorType;
    int armorClass;
    function<void(int, int, int)> damageDie;
    CharacterClass (*classStringToEnumPtr)(const string&);
    DiceRoll* diceRollInstance;
};

int RNG(int min, int max);

#endif