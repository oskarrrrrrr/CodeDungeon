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

struct Wait
{};


using Action = std::variant<Attack, Move, GoNextFloor, UseItem, Wait>;

#endif //CODEDUNGEON_MOVE_H
