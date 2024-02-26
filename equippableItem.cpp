#include "equippableItem.h"
using namespace std;

string EquippableItem::weaponType;
string EquippableItem::armorType;

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
//couldn't find proper syntax on how to make this static without getting errors need help 
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

// void EquippableItem::armorTypeArmorClassDeterminant(const string _armorType) {
//     unordered_map<string, pair<unordered_map<string, string>, int>> ArmorClassMap = {
//         {""}
//     }
// }

void EquippableItem::weaponTypeDeterminant (string _playerClass) {
    unordered_map<string, string> classToWeaponMap = {
        {"Cleric", "All"},
        {"Barbarian", "All"},
        {"Bard", "Martial Ranged, Simple, and Finesse"
            // "Bard",
            // (
            //      "Martial Ranged," + "Simple, " + "Finesse"
            // )
        },
        {"Druid", "All"},
        {"Fighter", "All"},
        {"Monk", "Simple"},
        {"Paladin", "All"},
        {"Ranger", "All"},
        {"Rogue", "Martial Ranged, Simple, and Finesse"},
        {"Sorcerer", "Simple"},
        {"Warlock", "Simple"},
        {"Wizard", "Simple"}
    };
    if (classToWeaponMap.find(_playerClass) == classToWeaponMap.end()) {
        weaponType = "None";
        return;
    }
    weaponType = classToWeaponMap[_playerClass];
}

int EquippableItem::RNG(int min, int max) {
    int result;
    static random_device random;
    static mt19937 gen(random());
    uniform_int_distribution<int> damageDistribution (min, max);
    return damageDistribution(gen);
}