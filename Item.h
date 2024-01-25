#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
   string name;


public:
    Item();
    Item(string name);
    string getName() const ;
};

#endif