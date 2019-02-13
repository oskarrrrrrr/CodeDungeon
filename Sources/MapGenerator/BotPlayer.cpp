//
// Created by dawidbarzyk on 2/12/19.
//

#include <MapGenerator/RandomGenerator.h>
#include <utilities/seedGenerator.h>


#include "BotPlayer.h"

Action BotPlayer::genAction(const Map &map) const
{
    uint64_t seed = createSeed();
    RandomGenerator randGen{seed};

    return Move{static_cast<Direction>(randGen.generate(0, 3))};
}
