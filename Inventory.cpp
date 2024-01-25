#include "Inventory.h"
#include "Item.h"

using namespace std;

Inventory::Inventory() : grid(){}

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

void Inventory::display() const
{
    const int numItems = grid.size();
    const int emptySlots = Inventory_Size - numItems;
    for (int i = 0; i < grid.size(); i++)
    {
        //I might want to add a const here, but permissive issues-- ask
        const Item &currentItem = grid[i];

        cout <<currentItem.getName() << "\t";
    }
    for (int i = 0; i < emptySlots; ++i) {
        cout << "Empty\t";
    }
    cout << endl;
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

void Inventory::setArmor(string _Armor)
{
    this->Armor = _Armor;
    grid.push_back(Item (_Armor));
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