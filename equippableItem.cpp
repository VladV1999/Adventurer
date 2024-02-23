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

void EquippableItem::armorTypeDeterminant (string _playerClass) {

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

    if (classToArmorMapping.find(_playerClass) == classToArmorMapping.end()) {
        armorType = "None";
        return;
    }
    armorType = classToArmorMapping[_playerClass];

}

void EquippableItem::weaponTypeDeterminant (string _playerClass) {
    unordered_map<string, string> classToWeaponMap = {
        {"Cleric", "All"},
        {"Barbarian", "All"},
        {"Bard", "Martial Ranged, Simple, Finesse"},
        {"Druid", "All"},
        {"Fighter", "All"},
        {"Monk", "Simple"},
        {"Paladin", "All"},
        {"Ranger", "All"},
        {"Rogue", "Martial Ranged, Simple, and Finesse"}
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