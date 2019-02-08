#include "RandomMonsterGenerator.h"

std::list<Monster> RandomMonsterGenerator::generate(RandomGenerator& randGen, const Map& map)
{
  std::list<Monster> resultMonsters;

  resultMonsters.emplace_back(Position(4,4), 1, 2);
  resultMonsters.emplace_back(Position(9,4), 1, 1);
  resultMonsters.emplace_back(Position(3,20), 1, 4);

  return resultMonsters;
}
