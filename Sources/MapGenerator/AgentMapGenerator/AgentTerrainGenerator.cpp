#include <MapGenerator/Action.h>
#include <MapGenerator/Position.h>

#include <MapGenerator/AgentMapGenerator/AgentTerrainGenerator.h>

AgentTerrainGenerator::AgentTerrainGenerator() :
    ITerrainGenerator{}
{}

bool isPositionInbound(const Position& pos, uint32_t height, uint32_t width)
{
    return pos.row >= 4 && pos.row < height - 4
        && pos.column >= 4 && pos.column < width - 4;
}

void generateRoom(RandomGenerator& randGen, Terrain& t, const Position& pos)
{
    uint32_t roomHeight = randGen.generate(5,7);
    uint32_t roomWidth = randGen.generate(5,7);
    t.addRoom({int(pos.row - roomHeight/2), int(pos.column - roomWidth/2)}, roomHeight, roomWidth);
}

Terrain AgentTerrainGenerator::generate(RandomGenerator &randGen)
{
    Terrain t(40, 150);

    uint32_t height = 40;
    uint32_t width = 150;

    Position pos {int32_t(randGen.generate(10, 30)), int32_t(randGen.generate(30, 120))};
    auto dir = static_cast<Direction>(randGen.generate(0, 3));

    int32_t changeDirChange = 3;
    int32_t makeRoomChange = 3;

    int32_t changeDir = changeDirChange;
    int32_t makeRoom = makeRoomChange;

    generateRoom(randGen, t, pos);

    Position spawnLoc = pos;

    for (int i=0; i<300; i++)
    {
        int32_t corridorLength = randGen.generate(2, 5);
        for (int i=0; i<corridorLength && isPositionInbound(pos + dir, height, width); i++)
        {
            t[pos] = Field::Ground;
            pos += dir;
        }

        if (randGen.generate(0, 99) < changeDir)
        {
            dir = static_cast<Direction>(randGen.generate(0, 3));

            changeDir = 0;
        }
        else
        {
            changeDir += changeDirChange;
        }

        if (randGen.generate(0, 99) < makeRoom)
        {
            generateRoom(randGen, t, pos);
            makeRoom = 0;
        }
        else
        {
            makeRoom += makeRoomChange;
        }
    }
    generateRoom(randGen, t, pos);
    t.setStairs(pos);

    t.setSpawn(spawnLoc);

    return t;
}
