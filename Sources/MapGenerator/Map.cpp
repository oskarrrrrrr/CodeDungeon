#include <algorithm>

#include <MapGenerator/Map.h>


const std::list<std::unique_ptr<Item>>& Map::items() const
{
    return items_;
}

const std::list<Monster>& Map::monsters() const
{
    return monsters_;
}

const PlayerShrdPtr& Map::player() const
{
    return player_;
}

const Terrain& Map::terrain() const
{
    return terrain_;
}

const MaxStats& Map::max() const
{
    return maxStats_;
}

void Map::addItems(const std::list<Item>& items)
{
    for(auto item : items)
    {
        items_.emplace_back(std::make_unique<Item>(item));
    }
}

void Map::addMonsters(const std::list<Monster>& monsters)
{
    monsters_ = monsters;
}

void Map::addPlayer(PlayerShrdPtr player)
{
    player_ = player;
    maxStats_.attack = player->attack();
    maxStats_.health = player->maxHealth();
}

void Map::addTerrain(const Terrain& terrain)
{
    terrain_ = terrain;
}

std::list<Monster>::iterator Map::getMonsterOnPosition(const Position& pos)
{
    return std::find_if(
        std::begin(monsters_),
        std::end(monsters_),
        [pos](const Monster& mob){return mob.position() == pos;});
}

std::list<std::unique_ptr<Item>>::iterator Map::getItemOnPosition(const Position& pos)
{
    return std::find_if(
        std::begin(items_),
        std::end(items_),
        [pos](const std::unique_ptr<Item>& it){return it->position() == pos;});

}

std::list<std::unique_ptr<Item>>::const_iterator Map::getConstItemOnPosition(const Position& pos) const
{
    return std::find_if(
            std::begin(items_),
            std::end(items_),
            [pos](const std::unique_ptr<Item>& it){return it->position() == pos;});

}
void Map::makeAction(const Creature& who, Action what)
{
    if (std::holds_alternative<Quit>(what))
    {
        player_->kill();
        return;
    }
    if (std::holds_alternative<Move>(what)
        && terrain_[who.position() + std::get<Move>(what).dir] == Field::Wall)
        return;

    if (who.id() == player_->id())
    {
        if (std::holds_alternative<Move>(what))
        {
            auto move = std::get<Move>(what);
            auto targetPosition = who.position() + move.dir;

            if (getMonsterOnPosition(targetPosition) != std::end(monsters_))
            {
                makeAction_(*(player_), Attack{move.dir});
            }
            else
            {
                auto potential_item = getItemOnPosition(targetPosition);
                if (potential_item != std::end(items_))
                {
                    if(player_->canPickItem())
                    {
                        player_->pickItem(std::move(*potential_item));
                        items_.erase(potential_item);
                        makeAction(*player_, what);
                    }
                }
                else
                {
                    makeAction_(*player_, what);
                }
            }
        }
        else
        {
            makeAction_(*(player_), what);
        }
    }
    else
    {
        auto monsterIt = std::find_if(std::begin(monsters_), std::end(monsters_),
                                       [&who](const Monster &mob) { return mob.id() == who.id(); });
        if (monsterIt != std::end(monsters_))
            makeAction_(*monsterIt, what);
    }
}

void Map::makeAction_(Creature& who, Action what)
{
    if (std::holds_alternative<Move>(what))
    {
        who.makeMove(std::get<Move>(what));
    }

    else if(std::holds_alternative<Attack>(what))
    {
        auto move = std::get<Attack>(what);
        auto targetPosition = who.position() + move.dir;

        if (targetPosition == player_->position())
        {
            player_->getHit(who.attack());
        }
        else
        {
            auto target_monster = getMonsterOnPosition(targetPosition);

            if (target_monster == std::end(monsters_))
                throw std::logic_error("Trying to attack nonexistent monster on position: " + targetPosition.toString());

            target_monster->getHit(who.attack());

            if (target_monster->actualHealth() <= 0)
                monsters_.erase(target_monster);
        }
    }

    else if(std::holds_alternative<UseItem>(what))
    {
        who.useItem(std::get<UseItem>(what).id);
    }
}

void Map::updateMaxStats()
{
    for(const auto& item : items_)
    {
        maxStats_.attack += item->attackBuff();
        maxStats_.health += item->healthBuff();
    }
}
