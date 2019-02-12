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

Position getAnythingFreeAround(RandomGenerator& randGen, const Item& item, const Map& map, const std::vector<Position>& takenFields)
{
    Position mid = item.position();
    std::vector<Position> availablePositions;
    for (auto maybeGood : std::vector<Position>{mid + Direction::UP, mid + Direction::DOWN, mid + Direction::LEFT, mid + Direction::RIGHT})
    {
        if (isFieldValid(maybeGood, map, takenFields))
        {
            availablePositions.push_back(maybeGood);
        }
    }
    return availablePositions[randGen.generate(0,availablePositions.size()-1)];
}

std::vector<Position> preparePositionsForMonsters(RandomGenerator& randGen, const Map& map)
{
    std::vector<Position> result;
    for (const auto& itemUnique : map.items())
    {
        result.push_back(getAnythingFreeAround(randGen, *itemUnique, map, result));
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

std::list<Monster> AgentMonsterGenerator::generate(RandomGenerator& randGen, const Map& map)
{
    MaxStatsPlayer player{map.max().attack, map.max().health};

    std::list<Monster> monsters = createRandomMonsters(randGen, preparePositionsForMonsters(randGen, map), player);
    
    return monsters;
}
