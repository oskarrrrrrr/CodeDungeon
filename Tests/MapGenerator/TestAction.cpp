#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <gmock/gmock-matchers.h>

#include <MapGenerator/Action.h>

using ::testing::UnorderedElementsAre;

TEST(DirectionShould, checkEquality)
{
    Direction dir1 {Direction::UP};
    Direction dir1_2 {Direction::UP};
    Direction dir2 {Direction::DOWN};
    Direction dir2_2 {Direction::DOWN};
    Direction dir3 {Direction::LEFT};
    Direction dir3_2 {Direction::LEFT};
    Direction dir4 {Direction::RIGHT};
    Direction dir4_2 {Direction::RIGHT};


    EXPECT_EQ(dir1, dir1_2);
    EXPECT_EQ(dir2, dir2_2);
    EXPECT_EQ(dir3, dir3_2);
    EXPECT_EQ(dir4, dir4_2);

    EXPECT_NE(dir1, dir2);
    EXPECT_NE(dir2, dir3);
    EXPECT_NE(dir3, dir4);
    EXPECT_NE(dir4, dir1);
}

TEST(ActionShould, CheckEqualityForAttack)
{
    Attack act1 {Direction::UP};
    Attack act1_2 {Direction::UP};
    Attack act2 {Direction::DOWN};
    Attack act2_2 {Direction::DOWN};
    Attack act3 {Direction::LEFT};
    Attack act3_2 {Direction::LEFT};
    Attack act4 {Direction::RIGHT};
    Attack act4_2 {Direction::RIGHT};

    EXPECT_EQ(act1, act1_2);
    EXPECT_EQ(act2, act2_2);
    EXPECT_EQ(act3, act3_2);
    EXPECT_EQ(act4, act4_2);

    EXPECT_NE(act1, act2);
    EXPECT_NE(act2, act3);
    EXPECT_NE(act3, act4);
    EXPECT_NE(act4, act1);
}


TEST(ActionShould, CheckEqualityForMove)
{
    Move act1 {Direction::UP};
    Move act1_2 {Direction::UP};
    Move act2 {Direction::DOWN};
    Move act2_2 {Direction::DOWN};
    Move act3 {Direction::LEFT};
    Move act3_2 {Direction::LEFT};
    Move act4 {Direction::RIGHT};
    Move act4_2 {Direction::RIGHT};

    EXPECT_EQ(act1, act1_2);
    EXPECT_EQ(act2, act2_2);
    EXPECT_EQ(act3, act3_2);
    EXPECT_EQ(act4, act4_2);

    EXPECT_NE(act1, act2);
    EXPECT_NE(act2, act3);
    EXPECT_NE(act3, act4);
    EXPECT_NE(act4, act1);
}

TEST(ActionShould, CheckEqualityForGoNextFloor)
{
    GoNextFloor act1 {};
    GoNextFloor act2 {};

    EXPECT_EQ(act1, act2);
}

TEST(ActionShould, CheckEqualityForUseItem)
{
    UseItem act1 {5};
    UseItem act1_2 {5};
    UseItem act2 {7};

    EXPECT_EQ(act1, act1_2);
    EXPECT_NE(act1, act2);
    EXPECT_NE(act1_2, act2);
}

TEST(ActionShould, CheckEqualityForWait)
{
    Wait act1 {};
    Wait act2 {};

    EXPECT_EQ(act1, act2);
}


TEST(ActionShould, CheckEqaulityWithDifferentTypes)
{
    Action move1 = Move{Direction::UP};
    Action move1_2 = Move{Direction::UP};
    Action move2 = Move{Direction::DOWN};

    Action att1 = Attack{Direction::UP};
    Action att1_2 = Attack{Direction::UP};
    Action att2 = Attack{Direction::DOWN};

    Action wait = Wait{};


    EXPECT_EQ(move1, move1_2);
    EXPECT_NE(move1, move2);

    EXPECT_EQ(att1, att1_2);
    EXPECT_NE(att1, att2);

    EXPECT_NE(move1, att1);
    EXPECT_NE(move1, wait);
}


TEST(ActionShould, CheckType)
{
    Action m = Attack{Direction::UP};

    EXPECT_TRUE(std::holds_alternative<Attack>(m));
    EXPECT_FALSE(std::holds_alternative<Move>(m));
}

TEST(ActionShould, ReturnGoodValue)
{
    Action m = Attack{Direction::UP};

    EXPECT_EQ(std::get<Attack>(m).dir, Direction::UP);
}

TEST(ActionShould, ThrowWithWrongType)
{
    Action m = Attack{Direction::LEFT};

    EXPECT_THROW(std::get<Move>(m).dir, std::bad_variant_access);
}

TEST(ActionShould, WorkWithGetIf)
{
    Action m = Attack{Direction::LEFT};

	EXPECT_EQ(std::get_if<Move>(&m), nullptr);
	EXPECT_EQ(std::get_if<Attack>(&m)->dir, Direction::LEFT);
}
