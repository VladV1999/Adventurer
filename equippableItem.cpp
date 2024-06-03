#include "equippableItem.h"
using namespace std;

string EquippableItem::getArmorType () {
    return this->armorType;
}

void EquippableItem::setArmorType (string _armorType) {
    this->armorType = _armorType;
}

string EquippableItem::getWeaponType () {
    return this->weaponType;
}

void EquippableItem::setWeaponType (string _weaponType) {
    this->weaponType = _weaponType;
}

EquippableItem EquippableItem::armorTypeDeterminant (string _playerClass) {

    unordered_map<string, string> classToArmorMapping = {
        {"Cleric", "Heavy"},
        {"Artificier", "Medium"},
        {"Barbarian", "Light"},
        {"Bard", "Light"},
        {"Druid", "Medium"},
        {"Fighter", "Heavy"},
        {"Monk", "Light"},
        {"Paladin", "Heavy"},
        {"Ranger", "Medium"},
        {"Sorcerer", "Light"},
        {"Warlock", "Light"},
        {"Wizard", "Light"},
        {"Rogue", "Medium"}
    };

    EquippableItem item;
    const auto& armorGetterItr = classToArmorMapping.find(_playerClass);
    if (classToArmorMapping.find(_playerClass) == classToArmorMapping.end()) {
       item.setArmorType("None");
    } else {
        item.setArmorType(armorGetterItr->second);
    }
    return item;
}

EquippableItem EquippableItem::armorTypeArmorClassDeterminant(pair<string, string> _armorTypeAndName) {
    unordered_map<pair<string, string>, int, hash_Pair> armorClassMap = {
        {{"Light", "Padded Armor"}, 11},
        {{"Light", "Leather Armor"}, 11},
        {{"Light", "Studded Leather Armor"}, 12},
        {{"Medium", "Hide Armor"}, 12},
        {{"Medium", "Chain Shirt"}, 13},
        {{"Medium", "Scale Mail"}, 14},
        {{"Medium", "Breastplate"}, 14},
        {{"Medium", "Half Plate"}, 15},
        {{"Heavy", "Ring Mail"}, 14},
        {{"Heavy", "Chain Mail"}, 16},
        {{"Heavy", "Splint Armor"}, 17},
        {{"Heavy", "Plate"}, 18}
    };
    EquippableItem item;
    if (armorClassMap.find(_armorTypeAndName) == armorClassMap.end()) {
        item.armorType = 10;
    }
    for (const auto& it : armorClassMap) {
        item.armorClass = it.second;
        cout << "Your armor type is " << it.first.first << " And your armor specification is " << it.first.second << "\n";
        cout << "Making your armor class "<< it.second << "\n";
    }
    return item;
};

EquippableItem EquippableItem::weaponTypeDeterminant (string _playerClass) {
    unordered_map<string, string> classToWeaponMap = {
        {"Cleric", "All"},
        {"Barbarian", "All"},
        {"Bard", 
        R"(Martial Ranged, 
        Simple, 
        Finesse)"},
        {"Druid", "All"},
        {"Fighter", "All"},
        {"Monk", "Simple"},
        {"Paladin", "All"},
        {"Ranger", "All"},
        {"Rogue", 
        R"(Martial Ranged, 
        Simple,
        Finesse)"},
        {"Sorcerer", "Simple"},
        {"Warlock", "Simple"},
        {"Wizard", "Simple"}
    };
    EquippableItem item;
    if (classToWeaponMap.find(_playerClass) == classToWeaponMap.end()) {
        item.weaponType = "None";
        return item;
    }
    item.weaponType = classToWeaponMap[_playerClass];
    return item;
}

int RNG(int min, int max) {
    int result;
    static random_device random;
    static mt19937 gen(random());
    uniform_int_distribution<int> damageDistribution (min, max);
    return damageDistribution(gen);
}

uniform_int_distribution<int> roll1d4() {
    return uniform_int_distribution(1, 4);
}

uniform_int_distribution<int> roll1d6() {
    return uniform_int_distribution(1, 6);
}

// uniform_int_distribution<int> roll1d8() {
//     return uniform_int_distribution(1, 8);
// }

// uniform_int_distribution<int> roll1d10() {
//     return uniform_int_distribution(1, 10);
// }

// uniform_int_distribution<int> roll1d12() {
//     return uniform_int_distribution(1, 12);
// }

//  uniform_int_distribution<int>,



EquippableItem EquippableItem::weaponDamageGenerator(pair <string, string> _weaponTypeAndName) {
    unordered_map<pair<string, string>, function<void(int, int, int)>, hash_Pair> weaponDamageMap = {
    {{"Simple", "Club"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 4); }},
    {{"Simple", "Dagger"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 4); }},
    {{"Simple", "Greatclub"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 8); }},
    {{"Simple", "Handaxe"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 6); }},
    {{"Simple", "Javelin"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 6); }},
    {{"Simple", "Light Hammer"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 4); }},
    {{"Simple", "Mace"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 6); }},
    {{"Simple", "Quarterstaff"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 6); }},
    {{"Simple", "Sickle"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 4); }},
    {{"Simple", "Spear"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 6); }},

    {{"Simple Ranged", "Light Crossbow"}, [](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 8); }},
    {{"Simple Ranged", "Dart"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 4); }},
    {{"Simple Ranged", "Shortbow"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 6); }},
    {{"Simple Ranged", "Sling"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 4); }},

    {{"Martial Melee", "Battleaxe"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 8); }},
    {{"Martial Melee", "Flail"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 8); }},
    {{"Martial Melee", "Glaive"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 10); }},
    {{"Martial Melee", "Greatsword"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(2, 1, 6); }},
    {{"Martial Melee", "Halberd"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 10); }},
    {{"Martial Melee", "Lance"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 12); }},
    {{"Martial Melee", "Longsword"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 8); }},
    {{"Martial Melee", "Maul"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(2, 1, 6); }},
    {{"Martial Melee", "Morningstar"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 8); }},
    {{"Martial Melee", "Pike"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 10); }},
    {{"Martial Melee", "Rapier"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 8); }},
    {{"Martial Melee", "Scimitar"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 6); }},
    {{"Martial Melee", "Shortsword"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 6); }},
    {{"Martial Melee", "Trident"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 6); }},
    {{"Martial Melee", "War pick"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 8); }},
    {{"Martial Melee", "Warhammer"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 8); }},
    {{"Martial Melee", "Whip"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 4); }},
    {{"Martial Melee", "Greataxe"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 12); }},
    
    {{"Martial Ranged", "Blowgun"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 1); }},
    {{"Martial Ranged", "Hand Crossbow"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 6); }},
    {{"Martial Ranged", "Heavy Crossbow"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 10); }},
    {{"Martial Ranged", "Longbow"}, [this](int diceRolls, int min, int max) {DiceRoll::getInstance().rollDamageDie(1, 1, 8); }}
    };
    if (weaponDamageMap.find(_weaponTypeAndName) == weaponDamageMap.end()) {
        cout << "No weapon entry found " << "\n";
    }
    auto it = weaponDamageMap.find(_weaponTypeAndName);
    EquippableItem item;
    item.damageDie = it->second;
    return item;
}
