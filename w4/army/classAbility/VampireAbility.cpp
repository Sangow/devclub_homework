#include "VampireAbility.h"

VampireAbility::VampireAbility(Unit* owner) : ClassAbility(owner), infectionChance(1) {};

VampireAbility::~VampireAbility() {};

void VampireAbility::useAbility() {
    std::cout << owner->getCharName() << ", choose the enemy to kiss!!!" << std::endl;
};

void VampireAbility::useAbility(Unit* enemy) {
    try {
        enemy->ensureIsAlive();
    } catch (OutOfHPException e) {
        std::cout << owner->getCharName() << " cannot bite " << enemy->getCharName() << " :" << e.message << std::endl;
        return;
    }
    this->kiss(enemy);
};

void VampireAbility::kiss(Unit* enemy) {
    try {
        enemy->ensureIsAlive();
    } catch (OutOfHPException e) {
        std::cout << owner->getCharName() << " cannot kiss " << enemy->getCharName() << " :" << e.message << std::endl;
        return;
    }

    std::cout << enemy->getCharName() << " was kissed by " << owner->getCharName() << "." << std::endl;
    if ( this->infectionChance % 2 == 0 && enemy->readyToBeInfected() ) {
        double oldHP = enemy->getHP();
        double oldHPLimit = enemy->getHPLimit();

        enemy->changeState(new VampireState(), "Vampire");
        enemy->takePhysDamage(enemy->getHPLimit() - (oldHP * enemy->getHPLimit()) / oldHPLimit);
        enemy->changeWeapon(new Claws(enemy));
        enemy->changeAbility(new VampireAbility(enemy));
        std::cout << enemy->getCharName() << " was infected by " << owner->getCharName() << " and turned into Vampire." << std::endl;
    }
    this->infectionChance += 1;
};