#include <iostream>
#include <random>
#include <string>
#include <functional>

using namespace std;

class DiceRoll {
    public:

        int getSidesOfDie();

        int getNumberOfRolls();

        void setSidesOfDie(int _sidesOfDie);

        void setNumberOfRolls(int _numberOfRolls);

        function <int(int, int)> damageDie;

        void rollDamageDie (int diceRolls, int min, int max);

        int distributionMaker (int min, int max);

    private:
        int sidesOfDie;
        int numberOfRolls;
};