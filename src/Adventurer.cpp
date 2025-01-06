#include "Adventurer.h"
#include "Inventory.h"
#include "equippableItem.h"


Adventurer::Adventurer (std::string newname, 
                        std::string charClass) {
    this->charClass = classStringToEnum(charClass);
    const DiceRoll& diceRoll = DiceRoll::getInstance();
    Name = newname;
    Dexterity = diceRoll.distributionMaker(4, 8);
    Strength = diceRoll.distributionMaker(4, 8);
    Constitution = diceRoll.distributionMaker(4, 8);
    Intelligence = diceRoll.distributionMaker(4, 8);
    Charisma = diceRoll.distributionMaker(4, 8);
    Wisdom = diceRoll.distributionMaker(4, 8);
    Level = 1;
}

    int Adventurer::getDexterity() {
        return this->Dexterity;
    }

    void Adventurer::setDexterity(int _Dexterity) {
        this->Dexterity = _Dexterity;
    }

    void Adventurer::setStrength(int _Strength) {
        this->Strength = _Strength;
    }
    

    int Adventurer::getStrength() {
        return this->Strength;
    }

    void Adventurer::setConstitution(int _Constitution) {
        this->Constitution = _Constitution;
    }

    int Adventurer::getConstitution() {
        return this->Constitution;
    }

    void Adventurer::setIntelligence(int _Intelligence) {
        this->Intelligence = _Intelligence;
    }

    int Adventurer::getIntelligence() {
        return this->Intelligence;
    }

    void Adventurer::setCharisma(int _Charisma) {
        this->Charisma = _Charisma;
    }

    int Adventurer::getCharisma() {
        return this->Charisma;
    }
    
    void Adventurer::setWisdom(int _Wisdom) {
        this->Wisdom = _Wisdom;
    }

    void Adventurer::addToWisdom(int points) {
        this->Wisdom += points;
    }

    void Adventurer::addToStrength(int points) {
        this->Strength += points;
    }

    void Adventurer::addToIntelligence(int points) {
        this->Intelligence += points;
    }

    void Adventurer::addToDexterity(int points) {
        this->Dexterity += points;
    }

    void Adventurer::addToConstitution(int points) {
        this->Constitution += points;
    }

    void Adventurer::addToCharisma(int points) {
        this->Charisma += points;
    }

    int Adventurer::getWisdom() {
        return this->Wisdom;
    }

    const std::string Adventurer::getName() const {
        return this->Name;
    }

    void Adventurer::setName(const std::string& _Name) {
        this->Name = _Name;
    }

    int Adventurer::getLevel() {
        return this->Level;
    }

    void Adventurer::levelUp() {
        this->Level=this->Level+1;
    }

    void Adventurer::performLevelUp(Adventurer& advent) {
    advent.levelUp();
    int pointsToAllocate = 2;
    if (pointsToAllocate > 0) {
        while (pointsToAllocate > 0) {
            std::string attributeStr;
            cout << "Which attribute would you like to increase?" << "\n";
            cin >> attributeStr;
            Attribute attribute = advent.attributeStringToEnum(attributeStr);

            switch(attribute) {
                case Attribute::Dexterity:
                    advent.addToDexterity(1);
                    cout << "Your Dexterity was increased by 1" << "\n";
                    --pointsToAllocate;
                    break;
                
                case Attribute::Strength:
                    advent.addToStrength(1);
                    cout << "Your Strength was increased by 1" << "\n";
                    --pointsToAllocate;
                    break;
                
                case Attribute::Charisma:
                    advent.addToCharisma(1);
                    cout << "Your Charisma was increased by 1 " << "\n";
                    --pointsToAllocate;
                    break;

                case Attribute::Intelligence:
                    advent.addToIntelligence(1);
                    cout << "Your Intelligence was increased by 1 " << "\n";
                    --pointsToAllocate;
                    break;

                case Attribute::Wisdom:
                    advent.addToWisdom(1);
                    cout << "Your Wisdom was increased by 1" << "\n";
                    --pointsToAllocate;
                    break;

                case Attribute::Constitution:
                    advent.addToConstitution(1);
                    cout << "Your Constitution was increased by 1 " << "\n";
                    --pointsToAllocate;
                    break;

                default:
                    cout << "Please select a valid attribute " << "\n";
                    break;
            }
        }
    }
}

    CharacterClass Adventurer::getCharacterClass() {
        return this->charClass;
    }

    void Adventurer::setCharacterClass(CharacterClass _charClass) {
        this->charClass = _charClass;
    }

    std::string reusable(std::string prompt, std::string tryAgainPrompt, const unordered_set<std::string>& legalValues) {
    std::string selection;
    bool validChoice = false;
    //Attribute Attribute = attributeStringToEnum(selectedSubclass); 
    while (!validChoice) {
        cout << prompt << "\n";
        std::getline(std::cin, selection);

        if (legalValues.find(selection) != legalValues.end()) {
            cout << "You have chosen " << selection << "\n";
            validChoice = true;
        }
        else {
            cout << tryAgainPrompt << "\n";
        }
    }

    return selection;
}

    template<typename EnumType>
    EnumType stringToEnum(const string& str, const unordered_map<string, EnumType>& lookupTable, const EnumType defaultValue) {
        const auto it = lookupTable.find(str);

        if (it == lookupTable.end()) {
            return defaultValue;
        }

        const EnumType foundValue = it->second;
        return foundValue;
}

Attribute Adventurer::attributeStringToEnum(string& str) {
    return stringToEnum(str, attributeMap, Attribute::InvalidAttribute);
}

CharacterClass Adventurer::classStringToEnum(string& str) {
    return stringToEnum(str, CHARACTER_CLASS_MAP, CharacterClass::InvalidClass);
}

std::string Adventurer::promptForClass(std::string& selectedClass) {
    bool validChoice = false;
    CharacterClass characterClass = classStringToEnum(selectedClass); 
    while (!validChoice) {
        cout << "What class would you like to choose? " << "\n";
        cin >> selectedClass;

        if (CHARACTER_CLASS_MAP.find(selectedClass) != CHARACTER_CLASS_MAP.end()) {
            cout << "You have chosen " << selectedClass << "\n";
            validChoice = true;
        }
        else {
            cout << "Please choose a valid class " << "\n";
        }
    }

    return selectedClass;
};

std::string promptForSubclass(const std::string theClass, int theLevel) {

    if (SUBCLASS_MAPPINGS.find(theClass) == SUBCLASS_MAPPINGS.end()) {
        return "Invalid Class";
    }

    if (theLevel < 3) {
        return "Get back to \"The Grind\"";
    }

    const auto& subclassMap = SUBCLASS_MAPPINGS.find(theClass)->second;

    std::string selectedSubclass = reusable(
        "What subclass would you like to choose? ",
        "Please choose a valid subclass ",
        subclassMap
    );
    return selectedSubclass;
}

void Adventurer::display(std::ostream& outs) const {
    outs << "Name: " << this->Name << "\n";
    outs << "Dexterity: " << this->Dexterity << "\n";
    outs << "Strength: " << this->Strength << "\n";
    outs << "Constitution: " << this->Constitution << "\n";
    outs << "Intelligence: " << this->Intelligence << "\n";
    outs << "Charisma: " << this->Charisma << "\n";
    outs << "Wisdom: " << this->Wisdom << "\n";
    outs << "Level " << this->Level << "\n";
    outs << inventory;
}

void Adventurer::replaceInventory(Inventory inv) {
    inventory = inv;
}

std::ostream& operator<<(std::ostream& outs, const Adventurer adv) {
    adv.display(outs);
    return outs;
}

