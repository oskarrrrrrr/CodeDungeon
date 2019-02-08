#include <algorithm>

#include <MapGenerator/Map.h>


const std::list<Item>& Map::items() const
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


void Map::addItems(const std::list<Item>& items)
{
    items_ = items;
}

void Map::addMonsters(const std::list<Monster>& monsters)
{
    monsters_ = monsters;
}

void Map::addPlayer(PlayerShrdPtr player)
{
    player_ = player;
}

void Map::addTerrain(const Terrain& terrain)
{
    terrain_ = terrain;
}

auto Map::getMonsterOnPosition(const Position& pos)
{
    return std::find_if(
        std::begin(monsters_),
        std::end(monsters_),
        [pos](const Monster& mob){return mob.position() == pos;});
}

auto Map::getItemOnPosition(const Position& pos)
{
    return std::find_if(
        std::begin(items_),
        std::end(items_),
        [pos](const Item& it){return it.position() == pos;});

}

void Map::makeAction(const Creature& who, Action what)
{
    if (who.id() == player_->id())
    {
        if (std::holds_alternative<Move>(what))
        {
            auto move = std::get<Move>(what);
            auto targetPosition = who.position() + move.dir;

            if (getMonsterOnPosition(targetPosition)->position() == targetPosition)
            {
                makeAction_(*(player_), Attack{move.dir});
            }
            else
            {
                auto potential_item = getItemOnPosition(targetPosition);
                if (potential_item->position() == targetPosition)
                {
                    player_->useItem(*potential_item);
                    items_.erase(potential_item);
                }
                else
                {
                    makeAction_(*(player_), what);
                }
            }
        }
        else
        {
            makeAction_(*(player_), what);
        }
    }
    else
        makeAction_(
            *std::find_if(std::begin(monsters_), std::end(monsters_), [&who](const Monster& mob){return mob.id() == who.id();}),
            what);
}

void Map::makeAction_(Creature& who, Action what)
{
    if (std::holds_alternative<Move>(what))
    {
        if (terrain_[who.position() + std::get<Move>(what).dir] != Field::Wall)
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
            target_monster->getHit(who.attack());

            if (target_monster->actualHealth() <= 0)
                monsters_.erase(target_monster);
        }
    }

    else if(std::holds_alternative<UseItem>(what))
    {
        auto itemIter = std::find_if(std::begin(items_), std::end(items_), [&what](const Item& item){return item.id() == std::get<UseItem>(what).id;});
        if(itemIter == std::end(items_))
        {
            throw std::logic_error("Item with Id: " + std::to_string(std::get<UseItem>(what).id) + " does not exist in item list.");
        }
        else
        {
            who.useItem(*itemIter);
        }
    }

}
