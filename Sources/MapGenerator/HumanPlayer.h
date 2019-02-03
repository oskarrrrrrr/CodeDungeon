#ifndef CODEDUNGEON_HUMANPLAYER_H
#define CODEDUNGEON_HUMANPLAYER_H

#include <MapGenerator/Player.h>

class HumanPlayer : public Player
{
public:
    HumanPlayer()
    : Player()
    {}

    Action genAction(Map& map) const override;
};


#endif //CODEDUNGEON_HUMANPLAYER_H
