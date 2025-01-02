#pragma once
#ifndef CONSUMABLEITEM_H_INCLUDED
#define CONSUMABLEITEM_H_INCLUDED

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class ConsumableItem : public Item {

    public:
        int getStackSize ();

        int getUses ();

        void setStackSize (int _stackSize);

        void setUses (int _Uses);

        void addUses (int _points);

        void addStackSize (int _points);

        void subtractStackSize (int _points);

        void subtractUses (int points);
        
    private:
        int stackSize;
        int uses;

};

#endif