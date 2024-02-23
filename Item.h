#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <iostream>
#include <string>
#include <random>

using namespace std;

enum class CharacterClass;
class Item
{
private:
    string name;
    CharacterClass characClass;

public:
    Item();
    Item(string name);
    string getName() const;
    int RNG(int min, int max);
};

#endif