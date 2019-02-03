
#include <MapGenerator/Map.h>
#include <MapGenerator/Monster.h>
#include <MapGenerator/Position.h>

Action Monster::genAction(Map& map) const
{
    const auto& playerPosition = map.player()->position();


    if (pos_ + Move{Move::UP} == playerPosition)
        return Attack{Attack::UP};
    if (pos_ + Move{Move::DOWN} == playerPosition)
        return Attack{Attack::DOWN};
    if (pos_ + Move{Move::RIGHT} == playerPosition)
        return Attack{Attack::RIGHT};
    if (pos_ + Move{Move::LEFT} == playerPosition)
        return Attack{Attack::LEFT};

    return Wait{};
}
