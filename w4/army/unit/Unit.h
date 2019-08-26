#ifndef UNIT_H
#define UNIT_H

#include "../exceptions/Exceptions.h"
#include "../state/State.h"
#include "../weapon/Weapon.h"

class State;
class Weapon;

class Unit {
    protected:
        State* state;
        Weapon* weapon;
        const char* charName;
        const char* charClass;

    public:
        Unit(const char* charName, const char* charClass);
        ~Unit();
        
        float getHP() const;
        float getHPLimit() const;
        float getDMG() const;
        const char* getCharClass() const;
        const char* getCharName() const;
        State& getState() const;
        Weapon& getWeapon() const;

        void takePhysDamage(float physDmg);
        virtual void takeMagicDamage(float magicDmg);
        void increaseHP(float extraHP);

        void changeState(State* newState);
        void changeWeapon(Weapon* newWeapon);

        bool readyToBeInfected();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H