// @todo think about this class some more, probably remove 
// add and subtract, and just stick with direct methods, set uses and get uses
#include "consumableItem.h"

using namespace std;

int ConsumableItem::getStackSize()
{
    return this->stackSize;
}

int ConsumableItem::getUses()
{
    return this->uses;
}

void ConsumableItem::setStackSize (int _stackSize)
{
    this->stackSize = _stackSize;
}

void ConsumableItem::setUses (int _uses)
{
    this->uses = _uses;
}

void ConsumableItem::addStackSize (int _points)
{
    this->stackSize += _points;
}

void ConsumableItem::addUses (int _points)
{
    this->uses += _points;
}

void ConsumableItem::subtractUses (int _points)
{
    this->uses -= _points;
}

void ConsumableItem::subtractStackSize (int _points)
{
    this->stackSize -= _points;
}