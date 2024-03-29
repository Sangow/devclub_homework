#include "Warlock.h"

Warlock::Warlock(const std::string& charName) : SpellCaster(charName, "Warlock") {
    this->state = new WarlockState();
    this->mState = new WarlockMState();
    this->weapon = new Sickle(this);
    this->ability = new WarlockAbility(this);
};

Warlock::~Warlock() {};