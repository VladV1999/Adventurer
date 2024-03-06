#include "DiceRoll.h"

using namespace std;

int DiceRoll::getNumberOfRolls () {
    return this->numberOfRolls;
}

int DiceRoll::getSidesOfDie () {
    return this->sidesOfDie;
}

void DiceRoll::setNumberOfRolls (int _numberOfRolls) {
    this->numberOfRolls = _numberOfRolls;
}

void DiceRoll::setSidesOfDie (int _sidesOfDie) {
    this->sidesOfDie = _sidesOfDie;
}

int DiceRoll::distributionMaker (int min, int max) {
    static random_device rd;
    static mt19937 generation(rd());
    uniform_int_distribution<int> damageDistribution (min, max);
    return damageDistribution(generation);
}


void DiceRoll::rollDamageDie (int diceRolls, int min, int max) {
    int damage;
    for (int i=0;i<diceRolls; ++i) {
        damage += distributionMaker(min, max);
    }
}