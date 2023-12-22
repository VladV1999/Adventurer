#include "Inventory.h"

using namespace std;

void rollADieForGold(int min, int max, Inventory& inv);

void rollADieForGold(int min, int max, Inventory& inv) {
    int result = getRandomDie(min, max);
    result *= 10;
    result *=5;
    inv.addGold(inv, result);
    cout << "Your gold is " << result << endl;
}    

int getRandomDie(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}