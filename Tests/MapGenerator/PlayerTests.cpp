//
// Created by dawidbarzyk on 2/9/19.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>

#include <MapGenerator/Player.h>

TEST(hahahahah, bagno)
{
    std::vector<std::unique_ptr<int>> v;

    v.reserve(10);

    EXPECT_TRUE(v[0]);
}

TEST(hahahahah, jeszczewiekszebagno)
{
    std::vector<std::unique_ptr<int>> v;

    v.resize(10);

    EXPECT_FALSE(v[0]);
}

TEST(PlayerShould, beAbleToAddItem)
{
    auto player = std::make_unique<Player>();

    EXPECT_TRUE(player->canPickItem());

}