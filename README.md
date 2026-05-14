# 🗡️ Adventurer

> A C++ RPG engine with a full class hierarchy — characters, inventories, spells, cantrips, dice rolls, and TOML-configured game data. 39 commits and still growing.

---

## What is this?

Adventurer is a terminal RPG built in C++ with a proper object-oriented architecture. It's not a tutorial project — it has real inheritance hierarchies, separate compilation units, header/source separation, memory management, and data-driven design via TOML config files.

Think D&D character sheet simulator with a game engine underneath.

---

## Tech Stack

| | |
|---|---|
| Language | C++ |
| Config format | TOML |
| IDE | VS Code |
| Build | Manual compilation (g++) |

---

## Architecture

The project uses clean OOP with proper header/source separation across multiple compilation units:

```
Item (base)
├── consumableItem    (potions, food — single-use)
└── equippableItem    (weapons, armor — stat modifiers)

SpellsAndFeats
└── cantrips          (at-will spells, no slot cost)

Adventurer           (player character)
└── Inventory        (manages item collection)

DiceRoll             (RNG engine for all game randomness)
```

---

## Features

- **Full item type system** — base `Item` class with `consumableItem` and `equippableItem` subclasses
- **Spell system** — `SpellsAndFeats` with `cantrips` as a separate subclass
- **Inventory management** — add, remove, equip, consume items
- **Dice rolling engine** — generalized RNG for d4, d6, d8, d10, d12, d20
- **TOML data files** — cantrips and game content configured externally
- **Character creation** — stat generation, class selection, starting gear
- **Memory management** — manual allocation/deallocation, proper constructor design

---

## Getting Started

**Prerequisites:** g++ or any C++17-compatible compiler

```bash
git clone https://github.com/VladV1999/Adventurer
cd Adventurer

g++ main.cpp Adventurer.cpp Inventory.cpp Item.cpp \
    consumableItem.cpp equippableItem.cpp \
    SpellsAndFeats.cpp cantrips.cpp DiceRoll.cpp \
    -o adventurer

./adventurer
```

---

## What I Learned

- Header/source separation and why it matters for compile times and encapsulation
- Inheritance hierarchies — when to use virtual functions, when not to
- Memory allocation in C++: the difference between stack and heap, when `new` is necessary, and how to avoid leaks
- Raw string literals (`R"(...)"`) for multi-line strings without concatenation hell
- TOML as a data-driven config format: loading game content at runtime instead of hardcoding it
- Constructor design — implicit return types, initialization lists, and object lifecycle

---

## What's Next

- [ ] Combat loop with turn-based mechanics
- [ ] Save/load system using file serialization
- [ ] CMake build system for proper dependency management
- [ ] Enemy AI with basic decision trees