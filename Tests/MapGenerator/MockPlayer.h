#include "gmock/gmock.h"

#include <MapGenerator/Player.h>

class MockPlayer : public Player
{
public:
    MOCK_CONST_METHOD1(genAction, Action(Map& map));
};
