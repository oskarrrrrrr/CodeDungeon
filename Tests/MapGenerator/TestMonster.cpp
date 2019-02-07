#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>

#include <memory>

#include <MapGenerator/Action.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/Position.h>
#include <MapGenerator/Map.h>
#include <MapGenerator/Monster.h>

#include "MockPlayer.h"

TEST(MonsterShould, WaitIfCantAttack)
{
    Monster mob {Position{0, 0}, 5, 10};
    Map map {};

    auto p = std::make_shared<MockPlayer>();
    p->setPosition({4,5});

    map.addPlayer(p);

    EXPECT_EQ(mob.genAction(map), Action{Wait{}});
}

TEST(MonsterShould, AttackNearPlayer)
{
    Monster mob {Position{5, 5}, 5, 10};
    Map map {};

    auto p = std::make_shared<MockPlayer>();
    map.addPlayer(p);

    p->setPosition({4,5});
    EXPECT_EQ(mob.genAction(map), Action{Attack{Direction::UP}});
    p->setPosition({5,4});
    EXPECT_EQ(mob.genAction(map), Action{Attack{Direction::LEFT}});
}
