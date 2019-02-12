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
    : Creature({-1, -1}, 40, 5), hunger_(0), maxHunger_(200) //example values
    {
        items_.resize(10);
    }

    int hunger() { return hunger_; }
    int maxHunger() { return maxHunger_; }

    void setPosition(Position pos);

    void useItem(int item) override;

    bool canPickItem() override;

    void pickItem(std::unique_ptr<Item> item) override;

    virtual Action genAction(const Map& map) const override;

    std::string getStringOfItem(size_t i);

    void increaseHunger();

    void reset();

protected:
    int hunger_;
    int maxHunger_;
    std::vector<std::unique_ptr<Item>> items_;
};

using PlayerShrdPtr = std::shared_ptr<Player>;
#endif //CODEDUNGEON_PLAYER_H
