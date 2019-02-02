#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <gmock/gmock-matchers.h>

#include <MapGenerator/Action.h>

using ::testing::UnorderedElementsAre;

TEST(ActionShould, CheckEqualityForAttack)
{
    Attack act1 {Attack::UP};
    Attack act1_2 {Attack::UP};
    Attack act2 {Attack::DOWN};
    Attack act2_2 {Attack::DOWN};
    Attack act3 {Attack::LEFT};
    Attack act3_2 {Attack::LEFT};
    Attack act4 {Attack::RIGHT};
    Attack act4_2 {Attack::RIGHT};

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
    Move act1 {Move::UP};
    Move act1_2 {Move::UP};
    Move act2 {Move::DOWN};
    Move act2_2 {Move::DOWN};
    Move act3 {Move::LEFT};
    Move act3_2 {Move::LEFT};
    Move act4 {Move::RIGHT};
    Move act4_2 {Move::RIGHT};

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
    Action move1 = Move{Move::UP};
    Action move1_2 = Move{Move::UP};
    Action move2 = Move{Move::DOWN};

    Action att1 = Attack{Attack::UP};
    Action att1_2 = Attack{Attack::UP};
    Action att2 = Attack{Attack::DOWN};

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
    Action m = Attack{Attack::UP};

    EXPECT_TRUE(std::holds_alternative<Attack>(m));
    EXPECT_FALSE(std::holds_alternative<Move>(m));
}

TEST(ActionShould, ReturnGoodValue)
{
    Action m = Attack{Attack::UP};

    EXPECT_EQ(std::get<Attack>(m).dir, Attack::UP);
}

TEST(ActionShould, ThrowWithWrongType)
{
    Action m = Attack{Attack::LEFT};

    EXPECT_THROW(std::get<Move>(m).dir, std::bad_variant_access);
}

TEST(ActionShould, WorkWithGetIf)
{
    Action m = Attack{Attack::LEFT};

	EXPECT_EQ(std::get_if<Move>(&m), nullptr);
	EXPECT_EQ(std::get_if<Attack>(&m)->dir, Attack::LEFT);
}
