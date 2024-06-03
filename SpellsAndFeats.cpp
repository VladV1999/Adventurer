#include "SpellsAndFeats.h"

const unordered_set<string> SpellsAndFeats::Helper::ARTIFICIER_CANTRIPS {
    "Acid Splash",
    "Booming Blade",
    "Create Bonfire",
    "Dancing Lights",
    "Fire Bolt",
    "Frostbite",
    "Green-Flamde Blade",
    "Guidance",
    "Light",
    "Lightning Lure",
    "Mage Hand",
    "Magic Stone",
    "Mending",
    "Message",
    "Poison Spray",
    "Prestidigitation",
    "Ray of Frost",
    "Resistance",
    "Shocking Grasp",
    "Spare the Dying",
    "Sword Burst",
    "Thorn Whip",
    "Thunderclap"
};

const unordered_set<string> SpellsAndFeats::Helper::BARD_CANTRIPS {
    "Blade Ward",
    "Dancing Lights",
    "Friends",
    "Light",
    "Mage Hand",
    "Mending",
    "Message",
    "Minor Illusion",
    "Prestidigitation",
    "Thunderclap",
    "True Strike",
    "Vicious Mockery"
};

const unordered_set<string> SpellsAndFeats::Helper::CLERIC_CANTRIPS {
    "Guidance",
    "Light",
    "Mending",
    "Resistance",
    "Sacred Flame",
    "Spare the Dying",
    "Thaumaturgy",
    "Toll the Dead",
    "Word of Radiance"
};

const unordered_set<string> SpellsAndFeats::Helper::DRUID_CANTRIPS {
    "Chill Touch",
    "Control Flames",
    "Create Bonfire",
    "Druidcraft",
    "Frostbite",
    "Guidance",
    "Gust",
    "Infestation",
    "Magic Stone",
    "Mending",
    "Mold Earth",
    "Poison Spray",
    "Primal Savagery",
    "Produce Flame",
    "Resistance",
    "Shape Water",
    "Shillelagh",
    "Thunderclap"
};

const unordered_set<string> SpellsAndFeats::Helper::RANGER_CANTRIPS {
    "Mage Hand"
};

const unordered_set<string> SpellsAndFeats::Helper::SORCERER_CANTRIPS {
    "Acid Splash",
    "Blade Ward",
    "Booming Blade",
    "Chill Touch",
    "Control Flames",
    "Create Bonfire",
    "Dancing Lights",
    "Fire Bolt",
    "Friends",
    "Frostbite",
    "Green-Flame Blade",
    "Gust",
    "Infestation",
    "Light",
    "Lightning Lure",
    "Mage Hand",
    "Mending",
    "Message",
    "Mind Sliver",
    "Minor Illusion",
    "Mold Earth",
    "Poison Spray",
    "Prestidigitation",
    "Ray of Frost",
    "Shape Water",
    "Shocking Grasp",
    "Sword Burst",
    "Thunder Clap",
    "True Strike"
};

const unordered_set<string> SpellsAndFeats::Helper::WARLOCK_CANTRIPS {
    "Blade Ward",
    "Booming Blade",
    "Chill Touch",
    "Create Bonfire",
    "Eldritch Blast",
    "Friends",
    "Frostbite",
    "Green-Flame Blade",
    "Infestation",
    "Light",
    "Lightning Lure",
    "Mage Hand",
    "Magic Stone",
    "Mind Sliver",
    "Minor Illusion",
    "Poison Spray",
    "Prestidigitation",
    "Sacred Flame",
    "Spare the Dying",
    "Sword Burst",
    "Thunder Clap",
    "Toll the Dead",
    "True Strike"
};

const unordered_set<string> SpellsAndFeats::Helper::WIZARD_CANTRIPS {
    "Acid Splash",
    "Blade Ward",
    "Booming Blade",
    "Chill Touch",
    "Control Flames",
    "Create Bonfire",
    "Dancing Lights",
    "Encode Thoughts",
    "Fire Bolt",
    "Friends",
    "Frostebite",
    "Green-Flame Blade",
    "Gust",
    "Infestation",
    "Light",
    "Lightning Lure",
    "Mage Hand",
    "Mending",
    "Message",
    "Mind Sliver",
    "Minor Illusion",
    "Mold Earth",
    "Poison Spray",
    "Prestidigitation",
    "Ray of Frost",
    "Sapping Sting",
    "Shape Water",
    "Shocking Grasp",
    "Sword Burst",
    "Thunder Clap",
    "Toll the Dead",
    "True Strike"
};

const std::unordered_map<SpellsAndFeats::Helper::CharClass, SpellsAndFeats::Helper::Cantrips> SpellsAndFeats::Helper::CANTRIPS_BY_CLASS = {
    {
        "Wizard",
        {
            "Acid Splash",
            "Blade Ward",
            "Booming Blade",
            "Chill Touch",
            "Control Flames",
            "Create Bonfire",
            "Dancing Lights",
            "Encode Thoughts",
            "Fire Bolt",
            "Friends",
            "Frostebite",
            "Green-Flame Blade",
            "Gust",
            "Infestation",
            "Light",
            "Lightning Lure",
            "Mage Hand",
            "Mending",
            "Message",
            "Mind Sliver",
            "Minor Illusion",
            "Mold Earth",
            "Poison Spray",
            "Prestidigitation",
            "Ray of Frost",
            "Sapping Sting",
            "Shape Water",
            "Shocking Grasp",
            "Sword Burst",
            "Thunder Clap",
            "Toll the Dead",
            "True Strike"
        }
}

};

int SpellsAndFeats::getLevelOfSpell() {
    return this->levelOfSpell;
}

void SpellsAndFeats::setLevelOfSpell(int _levelOfSpell) {
    this->levelOfSpell = _levelOfSpell;
}

int SpellsAndFeats::getNumOfSpellSlots() {
    return this->numOfSpellSlots;
}

void SpellsAndFeats::setNumOfSpellSlots(int _numOfSpellSlots) {
    this->numOfSpellSlots = _numOfSpellSlots;
}

// void SpellsAndFeats::cantripNumberDeterminant(string _playerClass) {
//     int pointSelection;

// }

