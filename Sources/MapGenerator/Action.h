#ifndef CODEDUNGEON_MOVE_H
#define CODEDUNGEON_MOVE_H

#include <variant>

struct Attack
{
    enum{UP, DOWN, RIGHT, LEFT} dir;

    bool operator == (const Attack& rhs) const;
    bool operator != (const Attack& rhs) const;
};

struct Move
{
    enum{UP, DOWN, RIGHT, LEFT} dir;

    bool operator == (const Move& rhs) const;
    bool operator != (const Move& rhs) const;
};

struct GoNextFloor
{
    bool operator == (const GoNextFloor& rhs) const;
    bool operator != (const GoNextFloor& rhs) const;
};

struct UseItem
{
    int id;

    bool operator == (const UseItem& rhs) const;
    bool operator != (const UseItem& rhs) const;
};

struct Wait
{
    bool operator == (const Wait& rhs) const;
    bool operator != (const Wait& rhs) const;
};


using Action = std::variant<Attack, Move, GoNextFloor, UseItem, Wait>;

#endif //CODEDUNGEON_MOVE_H
