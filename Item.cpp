#include "Item.h"

using namespace std;

Item::Item() : name("") {}

Item::Item(string name) : name(name) {}

string Item::getName() const {
    return this->name;
}