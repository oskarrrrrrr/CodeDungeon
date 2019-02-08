#ifndef CODEDUNGEON_RANDOMMONSTERGENERATOR1_H
#define CODEDUNGEON_RANDOMMONSTERGENERATOR1_H

#include <MapGenerator/IMapGenerator/IMonsterGenerator.h>

class RandomMonsterGenerator : public IMonsterGenerator
{
public:
  std::list<Monster> generate(RandomGenerator& randGen, const Map& map);
};
#endif // CODEDUNGEON_RANDOMMONSTERGENERATOR1_H
