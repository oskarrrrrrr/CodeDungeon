#ifndef CODEDUNGEON_POSITION_H
#define CODEDUNGEON_POSITION_H

#include <MapGenerator/Action.h>

struct Position
{
    Position() = default;

    Position(int row, int column)
    : row(row), column(column)
    {}

    int row;
    int column;

    bool operator == (const Position& rhs) const;
    bool operator != (const Position& rhs) const;
    void operator += (const Direction& rhs);
    Position operator + (const Direction& rhs) const;
};

#endif //CODEDUNGEON_POSITION_H
