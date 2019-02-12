#include <MapGenerator/AgentMapGenerator/AgentMonsterGenerator.h>
#include <MapGenerator/Map.h>
#include <algorithm>

struct MaxStatsPlayer
{
    int attack;
    int hp;
};

bool isFieldValid(const Position& coords, const Map& map, const std::vector<Position>& takenFields)
{
    if (coords.column < 0 || coords.column > map.terrain().width() ||
        coords.row < 0 || coords.row > map.terrain().height())
        return false;
    return map.terrain()[coords] == Field::Ground && map.getConstItemOnPosition(coords) == std::end(map.items())
        && std::find(std::cbegin(takenFields), std::cend(takenFields), coords) == std::cend(takenFields);
}

Position getAnythingFreeAround(const Item& item, const Map& map, const std::vector<Position>& takenFields)
{
    Position mid = item.position();

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            Position maybeGood{mid.row+i, mid.column+j};
            if (isFieldValid(maybeGood, map, takenFields))
            {
                return maybeGood;
            }
        }
    }
}

std::vector<Position> preparePositionsForMonsters(const Map& map)
{
    std::vector<Position> result;
    for (const auto& itemUnique : map.items())
    {
        result.push_back(getAnythingFreeAround(*itemUnique, map, result));
    }
    return result;
}

Monster createRandomMonster(RandomGenerator& randGen, const Position& position, const MaxStatsPlayer& player)
{
    return { position, (int) randGen.generate(1, (uint64_t) player.hp), (int) randGen.generate(1, (uint64_t) player. attack)};
}

std::list<Monster> createRandomMonsters(RandomGenerator& randGen, const std::vector<Position>& positions, const MaxStatsPlayer& player)
{
    std::list<Monster> monsters;

    for (const auto& position : positions)
    {
        monsters.emplace_back(createRandomMonster(randGen, position, player));
    }

    return monsters;
}

void pickMonsters(std::list<Monster>& monsters, MaxStatsPlayer player)
{

}

std::list<Monster> AgentMonsterGenerator::generate(RandomGenerator& randGen, const Map& map)
{
    MaxStatsPlayer player{map.max().attack, map.max().health};

    std::list<Monster> monsters = createRandomMonsters(randGen, preparePositionsForMonsters(map), player);


    return monsters;
}
