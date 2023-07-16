#include <iostream>
#include <random>
#include <string>

using namespace std;

class Adventurer{
public:
    string Name;
    int Dexterity;
    int Strength;
    int Constitution;
    int Intelligence;
    int Charisma;
    int Wisdom;
    
};
int main(){
    Adventurer advent;
    advent.Charisma = 0;
    advent.Constitution = 0;
    advent.Dexterity = 0;
    advent.Intelligence = 0;
    advent.Name = "Vlad";
    advent.Charisma = 0;
    advent.Wisdom = 0;

    cout << "The adventurer's name is " << advent.Name << endl;
    cout << "His stats are " << endl;
    cout << "Charisma = " << advent.Charisma << endl;
    cout << "Constitution = " << advent.Constitution << endl;
    cout << "Dexterity = " << advent.Dexterity << endl;
    cout << "Intelligence = "<< advent.Intelligence << endl;
    cout << "Strength = " << advent.Strength << endl;
    cout << "Wisdom = " <<advent.Wisdom << endl;
    return 0;
};