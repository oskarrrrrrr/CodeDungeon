#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <gmock/gmock-matchers.h>

#include <MapGenerator/Action.h>
#include <MapGenerator/Position.h>

TEST(PositionShould, CheckEquality)
{
    Position pos1 {0, 0};
    Position pos2 {0, 0};
    Position pos3 {1, 0};
    Position pos4 {0, 1};

    EXPECT_EQ(pos1, pos2);
    EXPECT_NE(pos1, pos3);
    EXPECT_NE(pos3, pos1);

    EXPECT_NE(pos1, pos4);
    EXPECT_NE(pos4, pos1);
}

TEST(PositionShould, BeAbleToMove)
{
    Position pos {7, 9};

    EXPECT_EQ(pos + Move{Move::UP}, (Position{6, 9}));
    EXPECT_EQ(pos + Move{Move::DOWN}, (Position{8, 9}));
    EXPECT_EQ(pos + Move{Move::LEFT}, (Position{7, 8}));
    EXPECT_EQ(pos + Move{Move::RIGHT}, (Position{7, 10}));

    pos += Move{Move::UP};
    EXPECT_EQ(pos, (Position{6, 9}));
    pos += Move{Move::LEFT};
    EXPECT_EQ(pos, (Position{6, 8}));
    pos += Move{Move::DOWN};
    EXPECT_EQ(pos, (Position{7, 8}));
    pos += Move{Move::RIGHT};
    EXPECT_EQ(pos, (Position{7, 9}));
}
