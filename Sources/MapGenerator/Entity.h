#ifndef CODEDUNGEON_ENTITY_H
#define CODEDUNGEON_ENTITY_H

#include <utility>

#include <MapGenerator/Position.h>

class Entity
{
public:
    Entity(Position pos)
    : id_(id_counter_),
      pos_(pos)
    {
        id_counter_++;
    }

private:
    int id_;
    Position pos_;

    static int id_counter_;
};

int Entity::id_counter_ = 0;

#endif //CODEDUNGEON_ENTITY_H
