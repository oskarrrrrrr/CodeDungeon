#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <gmock/gmock-matchers.h>

#include <MapGenerator/Action.h>

using ::testing::UnorderedElementsAre;

TEST(AttackShould, CheckEquality)
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


TEST(MoveShould, CheckEquality)
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
