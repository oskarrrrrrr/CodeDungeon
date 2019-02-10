#ifndef CODEDUNGEON_AGENTMONSTERGENERATOR_H
#define CODEDUNGEON_AGENTMONSTERGENERATOR_H

#include <MapGenerator/IMapGenerator/IMonsterGenerator.h>

class AgentMonsterGenerator : public IMonsterGenerator
{
public:
    std::list<Monster> generate(RandomGenerator& randGen, const Map& map);
};

#endif //CODEDUNGEON_AGENTMONSTERGENERATOR_H
