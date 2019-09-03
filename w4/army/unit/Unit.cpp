#include "Unit.h"

void Unit::changeCharClass(const std::string& newCharClass) {
    this->charClass = newCharClass;
};

bool Unit::unitIsMage() const {
    return this->mState != NULL;
};

Unit::Unit(const std::string& charName, const std::string& charClass) : charClass(charClass), charName(charName) {};

Unit::~Unit() {
    delete this->state;
    delete this->mState;
    delete this->ability;
    delete this->weapon;
};

float Unit::getHP() const {
    return this->state->getHP();
};

float Unit::getHPLimit() const {
    return this->state->getHPLimit();
};

float Unit::getStrength() const {
    return this->state->getStrength();
};

float Unit::getAgility() const {
    return this->state->getAgility();
};

float Unit::getDMG() const {
    return this->weapon->getDMG();
};

State& Unit::getState() const {
    return *(this->state);
};

Weapon& Unit::getWeapon() const {
    return *(this->weapon);
};

float Unit::getMana() const {
    return 0;
};

float Unit::getManaLimit() const {
    return 0;
};

MagicState& Unit::getMagicState() const {
    if ( this->unitIsMage() ) {
        return *(this->mState);
    }
};

const std::string& Unit::getCharClass() const {
    return this->charClass;
};

const std::string& Unit::getCharName() const {
    return this->charName;
};

void Unit::takePhysDamage(float physDmg) {
    this->state->takePhysDamage(physDmg);
};

void Unit::takeMagicDamage(float magicDmg) {
    this->state->takeMagicDamage(magicDmg);
};

void Unit::increaseHP(float extraHP) {
    this->state->increaseHP(extraHP);
};

void Unit::changeState(State* newState, const std::string& newCharClass) {
    State* tmpState = this->state;
    delete (tmpState);
    this->state = newState;
    this->changeCharClass(newCharClass);
};

void Unit::changeWeapon(Weapon* newWeapon) {
    Weapon* tmpWeapon = this->weapon;
    delete (tmpWeapon);
    this->weapon = newWeapon;
};

void Unit::changeAbility(ClassAbility* newAbility) {
    if ( this->ability != NULL ) {
        ClassAbility* tmpAbility = this->ability;
        delete (tmpAbility);
    }
    this->ability = newAbility;
};

bool Unit::readyToBeInfected() {
    return this->state->readyToBeInfected();
};

void Unit::attack(Unit* enemy) {
    try {
        this->weapon->attack(enemy);
    } catch (OutOfHPException) {
        std::cout << "Unit \"" << enemy->getCharName() << "\" is DEAD!!!" << std::endl;
    }
};

void Unit::counterAttack(Unit* enemy) {
    this->weapon->counterAttack(enemy);
};

void Unit::useAbility() {
    if ( this->ability == NULL ) {
        std::cout << this->getCharName() << " has no ability!" << std::endl;
        return;
    }
    this->ability->useAbility();
};

void Unit::useAbility(Unit* enemy) {
    if ( this->ability == NULL ) {
        std::cout << this->getCharName() << " has no ability!" << std::endl;
        return;
    }
    this->ability->useAbility(enemy);
};

void Unit::notifySoulHunters() {
    std::set<SoulHunter*>::iterator it = this->getSoulHunters().begin();
    
    for ( ; it != soulHunters.end(); it++ ) {
        ((Unit*)(*it))->increaseHP(getHPLimit() / 10);
        (*it)->removeSoul(this);
    }
};

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getCharClass() << ": " << unit.getCharName();
    out << unit.getState();
    out << unit.getWeapon() << std::endl;
    out << "[mana: " << unit.getMana() << "/" << unit.getManaLimit() << "]";

    return out;
};