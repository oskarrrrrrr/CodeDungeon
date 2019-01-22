#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <gmock/gmock-matchers.h>

#include <MapGenerator/Action.h>

using ::testing::UnorderedElementsAre;

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
