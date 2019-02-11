#ifndef CODEDUNGEON_CREATURE_H
#define CODEDUNGEON_CREATURE_H

#include <memory>

#include <MapGenerator/Action.h>
#include <MapGenerator/Entity.h>
#include "Item.h"

class Map;

class Creature : public Entity
{
public:
    Creature(Position pos, int health, int attack)
    : Entity(pos),
      maxHealth_(health),
      actualHealth_(health),
      attack_(attack)
    {}

    bool isAllive() const;
    int maxHealth() const;
    int actualHealth() const;
    int attack() const;


    void makeMove(const Move& move);
    void getHit(int dmg);

    virtual void useItem(int itemId);

    virtual bool canPickItem();
    virtual void pickItem(std::unique_ptr<Item> item);

    virtual Action genAction(Map& map) const = 0;

    void kill();

protected:
    int maxHealth_;
    int actualHealth_;
    int attack_;
};

#endif //CODEDUNGEON_CREATURE_H
