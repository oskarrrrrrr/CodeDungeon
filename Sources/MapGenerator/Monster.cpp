
#include <MapGenerator/Map.h>
#include <MapGenerator/Monster.h>
#include <MapGenerator/Position.h>

Action Monster::genAction(Map& map) const
{
    const auto& playerPosition = map.player()->position();


    if (pos_ + Direction::UP == playerPosition)
        return Attack{Direction::UP};
    if (pos_ + Direction::DOWN == playerPosition)
        return Attack{Direction::DOWN};
    if (pos_ + Direction::RIGHT == playerPosition)
        return Attack{Direction::RIGHT};
    if (pos_ + Direction::LEFT == playerPosition)
        return Attack{Direction::LEFT};

    return Wait{};
}
