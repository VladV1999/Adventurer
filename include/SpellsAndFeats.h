#pragma once
#ifndef SPELLSANDFEATS_H_INCLUDED
#define SPELLSANDFEATS_H_INCLUDED

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class SpellsAndFeats {
    public:
    int getNumOfSpellSlots();

    void setNumOfSpellSlots(int _numOfSpellSlots);

    int getLevelOfSpell();

    void setLevelOfSpell(int _levelOfSpell);

    //void cantripNumberDeterminant();
    //I want to make this a map
    //That would pair a spellcaster's cantrip number-- at start
    //and then also let them choose the cantrips they want
    //Talk about design-- this will be a map with something more--
    //more than I have done 

    private:
    int numOfSpellSlots;
    int levelOfSpell;

    public:
    class Helper {

        using Cantrips = std::unordered_set<std::string>;
        using CharClass = std::string;
        static const Cantrips ARTIFICIER_CANTRIPS;
        static const Cantrips BARD_CANTRIPS;
        static const Cantrips CLERIC_CANTRIPS;
        static const Cantrips DRUID_CANTRIPS;
        static const Cantrips RANGER_CANTRIPS;
        static const Cantrips SORCERER_CANTRIPS;
        static const Cantrips WARLOCK_CANTRIPS;
        static const Cantrips WIZARD_CANTRIPS;

        static const std::unordered_map<CharClass, Cantrips> CANTRIPS_BY_CLASS;
    };
};


#endif