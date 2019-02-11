#include <MapGenerator/RandomGenerator.h>

//RandomGenerator::RandomGenerator()
//: RandomGenerator(uint64_t(std::random_device{}()) << 32 | uint64_t(std::random_device{}()))
//{}

RandomGenerator::RandomGenerator(uint64_t seed)
: seed_{seed}
{
    state_.seed(seed);
}

uint64_t RandomGenerator::generate()
{
    return std::uniform_int_distribution<uint64_t>()(state_);
}

uint64_t RandomGenerator::generate(uint64_t min, uint64_t max)
{
    return std::uniform_int_distribution<uint64_t>(min, max)(state_);
}

uint64_t RandomGenerator::seed()
{
    return seed_;
}
