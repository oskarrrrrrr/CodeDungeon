#include <vector>

#include <MapGenerator/AgentMapGenerator/AgentItemGenerator.h>
#include <MapGenerator/Position.h>
#include <algorithm>

namespace
{

bool fieldIsInRoom(const Terrain &terrain, const Position& pos)
{
    return true;
}

std::vector<Position> getFreeFields(const Terrain &terrain)
{
    std::vector<Position> result;
    for (int row = 0; row < terrain.height(); ++row)
    {
        for (int column = 0; column < terrain.width(); ++column)
        {
            Position cursor(row, column);

            if(terrain[cursor] == Field::Ground && fieldIsInRoom(terrain, cursor))
            {
                result.push_back(cursor);
            }
        }
    }

    return result;
}

Item makeItem(RandomGenerator& randGen, const Position& pos)
{
    int healing;
    int healthBuff;
    int attackBuff;
    int itemStrength = randGen.generate(4, 10);
    int healingStrength = randGen.generate(0, itemStrength);

    healing = healingStrength * 5;

    itemStrength -= healingStrength;

    healthBuff = randGen.generate(0, itemStrength) * 2;

    attackBuff = (itemStrength - healthBuff) / 2;

    return {pos, healing, attackBuff, healthBuff};
}
}  // namespace


std::list<Item> AgentItemGenerator::generate(RandomGenerator& randGen, const Map& map)
{
    std::list<Item> items;

    std::vector<Position> availableFields = getFreeFields(map.terrain());

    std::vector<Position> takenFields;

    for(size_t i = 0; i < availableFields.size()/70; ++i)
    {
        Position pos;
        bool isGood = false;

        while(!isGood)
        {
            pos = availableFields[randGen.generate(0, availableFields.size() - 1)];
            isGood = std::find(std::begin(takenFields), std::end(takenFields), pos) == std::end(takenFields);
        }

        takenFields.push_back(pos);

        items.push_back(makeItem(randGen, pos));

    }
    return items;
}
