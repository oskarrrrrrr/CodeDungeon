//
// Created by dawidbarzyk on 2/12/19.
//

#ifndef CODEDUNGEON_BOTPLAYER_H
#define CODEDUNGEON_BOTPLAYER_H

#include <MapGenerator/Player.h>

class BotPlayer : public Player
{
public:
    BotPlayer()
            : Player()
    {}

    Action genAction(const Map& map) const override;
};

#endif //CODEDUNGEON_BOTPLAYER_H
