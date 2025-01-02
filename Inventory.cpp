#include "Inventory.h"
#include "Item.h"
#include "equippableItem.h"

using namespace std;

Inventory::Inventory() : grid(){}

Inventory::Inventory(const Item& _armor, string _weapon, string _classItem)
    :Inventory()
{
    this->setArmor(_armor);
    this->setWeapon(_weapon);
    this->setClassItem(_classItem);
}

bool Inventory::addItem(Item &newItem)
{
    if (grid.size() < grid.capacity())
    {
        grid.push_back(newItem);
        return true;
    }
    else
    {
        cout << "Inventory is full " << endl;
        return false;
    }
}
void rollADieForGold(int min, int max, Inventory &inv);

void rollADieForGold(int min, int max, Inventory &inv)
{
    int result = getRandomDie(min, max);
    result *= 10;
    result *= 5;
    inv.addGold(inv, result);
    cout << "Your gold is " << result << endl;
}

int getRandomDie(int min, int max);

int getRandomDie(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

// void Inventory::display(ostream& outs) const
// {
//     const int numItems = grid.size();
//     const int emptySlots = Inventory_Size - numItems;
//     for (int i = 0; i < grid.size(); i++)
//     {
//         const Item &currentItem = grid[i];

//         outs <<currentItem.getName() << "\t";
//     }
//     for (int i = 0; i < emptySlots; ++i) {
//         outs << "Empty\t";
//     }
//     outs << endl;
// }

void Inventory::display(ostream& outs) const {
    for (const auto& item : grid) {
        outs << item.getName() << "\t";
    }

    const int emptySlots = Inventory_Size - grid.size();
    for (int i = 0; i < emptySlots; ++i) {
        outs << "Empty\t";
    }

    outs << endl;
}


int Inventory::getGold()
{
    return this->Gold;
}

void Inventory::setGold(int _Gold)
{
    this->Gold = _Gold;
}

void Inventory::addGold(Inventory &inv, int _Gold)
{
    this->Gold += _Gold;
}

string Inventory::getArmor()
{
    return this->Armor.getName();
}

// void Inventory::setArmor(string _Armor)
// {
//     this->Armor = _Armor;
//     grid.push_back(Item (_Armor));
// }

void Inventory::setArmor(const Item& _Armor)
{
    this->Armor = _Armor;
    grid.push_back(Item(_Armor));
}

string Inventory::getWeapon()
{
    return this->Weapon.getName();
}

void Inventory::setWeapon(string _Weapon)
{
    this->Weapon = _Weapon;
    grid.push_back(Item (_Weapon));
}

string Inventory::getclassItem()
{
    return this->classItem.getName();
}
// @todo ask specifically what this was about (still confused a tiny bit)
void Inventory::setClassItem(string _classItem)
{
    this->classItem = _classItem;
    grid.push_back(Item (_classItem));

}

ostream& operator<<(ostream& outs, const Inventory& inv)
{
    inv.display(outs);

    return outs;
}
// Ask why getArmorType is necessary here???
Inventory generateInitialInventory(std::string theClass) {
    /*
    auto& clericBag = []() -> Inventory {
        Inventory bagOfHolding;

        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Cleric").getArmorType());
        bagOfHolding.setWeapon("Morningstar and Light Shield");
        bagOfHolding.setClassItem("Holy Sigil");

        return bagOfHolding;
    }
    */

    /*
    if (theClass == "Cleric") {
        return clericBag();
    }
    */
    const std::unordered_map<std::string, std::function<Inventory()>> invBuilders = {
        {
            "Cleric",
            []() -> Inventory {
                return Inventory(
                    EquippableItem::armorTypeDeterminant("Cleric").getArmorType(),
                    "Morningstar and Light Shield",
                    "Holy Sigil"
                );
            }
        }
    };

    Inventory bagOfHolding;
    if (theClass == "Cleric") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Cleric").getArmorType());
        bagOfHolding.setWeapon("Morningstar and Light Shield");
        bagOfHolding.setClassItem("Holy Sigil");
    }
    else if (theClass == "Wizard") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Wizard").getArmorType());
        bagOfHolding.setWeapon("Quarterstaff");
        bagOfHolding.setClassItem("Focus");
    }
    else if (theClass == "Artificier") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Artificier").getArmorType());
        bagOfHolding.setWeapon("Hammer");
        bagOfHolding.setClassItem("Tinker's Tools");
    }    
    else if (theClass == "Barbarian") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Barbarian").getArmorType());
        bagOfHolding.setWeapon("Battleaxe");
    }    
    else if (theClass == "Druid") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Druid").getArmorType());
        bagOfHolding.setWeapon("Club");
    }    
    else if (theClass == "Bard") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Bard").getArmorType());
        bagOfHolding.setWeapon("Daggers");
        bagOfHolding.setClassItem("Musical Instrument"); //make method to let user choose their instrument later on
    }    
    else if (theClass == "Rogue") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Rogue").getArmorType());
        bagOfHolding.setWeapon("Daggers");
    }    
    else if (theClass == "Fighter") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Fighter").getArmorType());
        bagOfHolding.setWeapon("Longsword");
    }
    else if (theClass == "Monk") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Monk").getArmorType());
        bagOfHolding.setWeapon("Quarterstaff");
    }
    else if (theClass == "Paladin") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Paladin").getArmorType());
        bagOfHolding.setWeapon("Longsword");
    }
    else if (theClass == "Ranger") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Ranger").getArmorType());
        bagOfHolding.setWeapon("Longbow");
    }
    else if (theClass == "Sorcerer") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Sorcerer").getArmorType());
        bagOfHolding.setWeapon("Quarterstaff");
    }
    else if (theClass == "Warlock") {
        bagOfHolding.setArmor(EquippableItem::armorTypeDeterminant("Warlock").getArmorType());
        bagOfHolding.setWeapon("Dagger"); //add a method that lets user choose specific weapon if they choose subclass of pact of the blade
        bagOfHolding.setClassItem("To be determined for subclass"); // add a method that lets user choose class Item if they choose any subclass
    }             
    else {
        cerr << "Invalid Class" << '\n';
    }

    return bagOfHolding;
}