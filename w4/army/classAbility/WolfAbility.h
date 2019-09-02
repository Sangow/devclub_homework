#ifndef WOLF_ABILITY_H
#define WOLF_ABILITY_H

#include <iostream>
#include "ClassAbility.h"
#include "WerewolfAbility.h"
#include "../state/WerewolfState.h"
#include "../weapon/Mace.h"

class WolfAbility : public ClassAbility {
    protected:
        int infectionChance;
        float byteDamage;

    public:
        WolfAbility(Unit* owner);
        virtual ~WolfAbility();

        virtual void useAbility();
        virtual void useAbility(Unit* enemy);

        void transform();
        void bite(Unit* enemy);
};

#endif // WOLF_ABILITY_H