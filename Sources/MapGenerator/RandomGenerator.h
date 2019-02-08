#ifndef CODEDUNGEON_RANDOMGENERATOR_H
#define CODEDUNGEON_RANDOMGENERATOR_H

#include <random>

class RandomGenerator
{
public:
    RandomGenerator();
    RandomGenerator(uint64_t seed);

    uint64_t seed();
    uint64_t generate();
    uint64_t generate(uint64_t min, uint64_t max);

private:
    uint64_t seed_;
    std::mt19937 state_;
};


#endif //CODEDUNGEON_RANDOMGENERATOR_H
