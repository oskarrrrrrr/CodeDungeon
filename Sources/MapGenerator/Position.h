#ifndef CODEDUNGEON_POSITION_H
#define CODEDUNGEON_POSITION_H

#include <MapGenerator/Action.h>

struct Position
{
    int row;
    int column;

    bool operator == (const Position& rhs) const;
    bool operator != (const Position& rhs) const;
    void operator += (const Move& rhs);
    Position operator + (const Move& rhs) const;
};

#endif //CODEDUNGEON_POSITION_H
