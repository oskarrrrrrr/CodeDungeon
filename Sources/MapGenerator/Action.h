#ifndef CODEDUNGEON_MOVE_H
#define CODEDUNGEON_MOVE_H

#include <variant>

struct Attack
{
	enum{UP, DOWN, RIGHT, LEFT} dir;
};

struct Move
{
	enum{UP, DOWN, RIGHT, LEFT} dir;
};

struct GoNextFloor
{};

struct UseItem
{
	int id;
};


using Action = std::variant<Attack, Move, GoNextFloor, UseItem>;

#endif //CODEDUNGEON_MOVE_H
