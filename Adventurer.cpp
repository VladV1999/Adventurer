#include <iostream>
#include <random>
#include <string>

using namespace std;

class Adventurer{
public:

        Adventurer (string newname){
            Name = newname;
            Dexterity = 0;
            Strength = 0;
            Constitution = 0;
            Intelligence = 0;
            Charisma = 0;
            Wisdom = 0;
        }
        int getDexterity(){
            return this->Dexterity;
        }
        void setStrength(int _Strength){
            this->Strength = _Strength;
        }
        int getStrength(){
            return this->Strength;
        }
        void setConstitution(int _Constitution){
            this->Constitution = _Constitution;
        }
        int getConstitution(){
            return this->Constitution;
        }
        void setIntelligence(int _Intelligence){
            this->Intelligence = _Intelligence;
        }
        int getIntelligence(){
            return this->Intelligence;
        }
        void setCharisma(int _Charisma){
            this->Charisma = _Charisma;
        }
        int getCharisma(){
            return this->Charisma;
        }
        void setWisdom(int _Wisdom){
            this->Wisdom = _Wisdom;
        }
        int getWisdom(){
            return this->Wisdom;
        }
        string getName (){
            return this->Name;
        }
        void setName(string _Name){
            this->Name = _Name;
        }


    private:
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