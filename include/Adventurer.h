#pragma once
#ifndef ADVENTURER_H_INCLUDED
#define ADVENTURER_H_INCLUDED

#include <iostream>
#include <random>
#include <string>
#include "Inventory.h"
#include <unordered_set>

using std::string;
using std::cout;
// @todo consider making this global

const unordered_map<string, unordered_set<string>> SUBCLASS_MAPPINGS = {
        {
            "Rogue",
            {
                "Arcane Trickster",
                "Thief",
                "Assassin",
                "Inquisitive",
                "Phantom",
                "Mastermind",
                "Scout",
                "Soulknife",
                "Swashbuckler"
            }
        },
        {
            "Wizard", 
            {
                "Bladesinger",
                "Chronurgy Magician",
                "Graviturgy Magician",
                "Order of Scribes",
                "School of Abjuration",
                "School of Conjuration",
                "School of Divination",
                "School of Enchantment",
                "School of Evocation",
                "School of Illusion",
                "School of Necromancy",
                "School of Transmutation",
                "School of War Magic"
            }
        },
        {
            "Cleric",
            {   
                "Arcana Domain",
                "Death Domain",
                "Forge Domain",
                "Grave Domain",
                "Knowledge Domain",
                "Life Domain",
                "Light Domain",
                "Nature Domain",
                "Order Domain",
                "Peace Domain",
                "Tempest Domain",
                "Trickery Domain",
                "Twilight Domain",
                "War Domain"
            }
        },
        {
            "Barbarian",
            {
                "Path of Ancestral Guardian",
                "Path of the Battlerager",
                "Path of the Beast",
                "Path of the Berserker",
                "Path of the Giant",
                "Path of the Storm Herald",
                "Path of the Totem Warrior",
                "Path of the Zealot",
                "Path of Wild Magic"
            }
        },
        {
            "Bard",
            {
                "College of Creation",
                "College of Eloquence",
                "College of Glamour",
                "College of Lore",
                "College of Spirits",
                "College of Swords",
                "College of Valor",
                "College of Whispers"
            }
        },
        {
            "Artificier",
            {
                "Alchemist",
                "Armorer",
                "Artillerist",
                "Battle Smith"
            }
        },
        {
            "Druid",
            {
                "Circle of Dreams",
                "Circle of Spores",
                "Circle of Stars",
                "Circle of Wildfire",
                "Circle of the Land",
                "Circle of the Moon",
                "Circle of the Shepherd"
            }
        },
        {
            "Fighter",
            {
                "Arcane Archer",
                "Battle Master",
                "Cavalier",
                "Champion",
                "Echo Knight",
                "Eldritch Knight",
                "Psi Warrior",
                "Banneret",
                "Rune Knight",
                "Samurai"
            }
        },
        {
            "Monk",
            {
                "Way of Mercy",
                "Way of Shadow",
                "Way of The Ascendant Dragon",
                "Way of the Astral Self",
                "Way of the Drunken Master",
                "Way of the Four Elements",
                "Way of the Kensei",
                "Way of the Long Death",
                "Way of the Open Hand",
                "Way of the Sun Soul"
            }
        },
        {
            "Paladin",
            {
                "Oath of Conquest",
                "Oath of Devotion",
                "Oath of Glory",
                "Oath of Redemption",
                "Oath of the Ancients",
                "Oath of the Crown",
                "Oath of the Watchers",
                "Oath of Vengeance",
                "Oathbreaker"
            }
        },
        {
            "Ranger",
            {
                "Beast Master",
                "Drakewarden",
                "Fey Wanderer",
                "Gloom Stalker",
                "Horizon Walker",
                "Hunter",
                "Monster Slayer",
                "Swarmkeeper"
            }
        },
        {
            "Sorcerer",
            {
                "Abberant Mind",
                "Clockwork Soul",
                "Divine Soul",
                "Draconic Bloodline",
                "Lunar Sorcery",
                "Shadow Magic",
                "Storm Sorcery",
                "Wild Magic"
            }
        },
        {
            "Warlock",
            {
                "The Archfey",
                "The Celestial",
                "The Fathomless",
                "The Fiend",
                "The Genie",
                "The Great Old One",
                "The Hexblade",
                "The Undead",
                "The Undying"
            }
        }
};
enum class Attribute {
    Dexterity,
    Strength,
    Wisdom,
    Charisma,
    Intelligence,
    Constitution,
    InvalidAttribute
};

enum class CharacterClass {
    Cleric,
    Artificier,
    Barbarian,
    Bard,
    Druid,
    Fighter,
    Monk,
    Paladin,
    Ranger,
    Sorcerer,
    Warlock,
    Wizard,
    Rogue,
    InvalidClass
};

static const unordered_map<string, Attribute> attributeMap = {
    {"Dexterity", Attribute::Dexterity},
    {"Strength", Attribute::Strength},
    {"Wisdom", Attribute::Wisdom},
    {"Charisma", Attribute::Charisma},
    {"Intelligence", Attribute::Intelligence},
    {"Constitution", Attribute::Constitution},
    {"Invalid", Attribute::InvalidAttribute}
};

static const unordered_map<string, CharacterClass> CHARACTER_CLASS_MAP = {
    {"Cleric", CharacterClass::Cleric},
    {"Artificier", CharacterClass::Artificier},
    {"Barbarian", CharacterClass::Barbarian},
    {"Bard", CharacterClass::Bard},
    {"Druid", CharacterClass::Druid},
    {"Fighter", CharacterClass::Fighter},
    {"Monk", CharacterClass::Monk},
    {"Paladin", CharacterClass::Paladin},
    {"Ranger", CharacterClass::Ranger},
    {"Sorcerer", CharacterClass::Sorcerer},
    {"Warlock", CharacterClass::Warlock},
    {"Wizard", CharacterClass::Wizard},
    {"Rogue", CharacterClass::Rogue},
    {"Invalid", CharacterClass::InvalidClass}
};


class Adventurer {
    public:
        Adventurer(std::string newname, std::string desiredClass);

        int getDexterity();

        void setDexterity(int _Dexterity) ;

        void setStrength(int _Strength) ;

        int getStrength();

        void setConstitution(int _Constitution);

        int getConstitution(); 

        void setIntelligence(int _Intelligence);

        int getIntelligence(); 

        void setCharisma(int _Charisma);

        int getCharisma();

        void setWisdom(int _Wisdom); 
        
        void addToWisdom(int points); 

        void addToStrength(int points); 

        void addToIntelligence(int points); 

        void addToDexterity(int points); 

        void addToConstitution(int points);

        void addToCharisma(int points); 

        int getWisdom(); 

        const std::string getName() const; 

        void setName(const std::string& _Name); 

        int getLevel(); 

        void levelUp();

        void performLevelUp(Adventurer& advent); 
                    
        void display(std::ostream& outs) const;

        CharacterClass getCharacterClass();

        void setCharacterClass(CharacterClass _charClass);

        void replaceInventory(Inventory inv);

        CharacterClass classStringToEnum(string& str);

        Attribute attributeStringToEnum(string& str);

        std::string reusable(std::string prompt, std::string tryAgainPrompt, const unordered_set<std::string>& legalValues);

        std::string promptForClass(std::string& selectedClass);

    private:
        Inventory inventory;
        std::string Name;
        int Dexterity;
        int Strength;
        int Constitution;
        int Intelligence;
        int Charisma;
        int Wisdom;
        int Level;
        CharacterClass charClass;
};

std::ostream& operator<<(std::ostream& outs, const Adventurer adv);



#endif