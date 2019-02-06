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


void Map::makeAction(const Creature& who, Action what)
{
    if (who.id() == player_->id())
        makeAction_(*(player_), what);
    else
        makeAction_(
            *std::find_if(std::begin(monsters_), std::end(monsters_), [&who](const Monster& mob){return mob.id() == who.id();}),
            what);
}

void Map::makeAction_(Creature& who, Action what)
{
    if (std::holds_alternative<Move>(what))
    {
        if (terrain_[who.position() + std::get<Move>(what)] != Field::Wall)
           who.makeMove(std::get<Move>(what));
    }
}
