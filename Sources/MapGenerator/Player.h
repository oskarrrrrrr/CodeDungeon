#ifndef CODEDUNGEON_PLAYER_H
#define CODEDUNGEON_PLAYER_H

#include <memory>
#include <vector>

#include <MapGenerator/Action.h>
#include <MapGenerator/Creature.h>
#include <MapGenerator/Item.h>

class Player : public Creature
{
public:
    Player()
    : Creature({-1, -1}, 40, 5) //example values
    {
        items_.resize(10);
    }

    void setPosition(Position pos);

    void useItem(int item) override;

    bool canPickItem() override;

    void pickItem(std::unique_ptr<Item> item) override;

    virtual Action genAction(Map& map) const override;

protected:
    std::vector<std::unique_ptr<Item>> items_;
};

using PlayerShrdPtr = std::shared_ptr<Player>;
#endif //CODEDUNGEON_PLAYER_H
