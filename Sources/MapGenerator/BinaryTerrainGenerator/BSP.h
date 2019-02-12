#ifndef BSP_H
#define BSP_H

#include <MapGenerator/Position.h>
#include <MapGenerator/RandomGenerator.h>
#include <MapGenerator/Terrain.h>
#include <memory>

class BSP
{
public:

    BSP(Position left_top, Position right_bottom)
    : left_top(left_top), right_bottom(right_bottom)
    {
        left_child = nullptr;
        right_child = nullptr;
    }

    void split(RandomGenerator& randGen);

    void split_vertically(RandomGenerator& randGen);
    void split_horizontally(RandomGenerator& randGen);

    void split_vertically_raw(RandomGenerator& randGen);
    void split_horizontally_raw(RandomGenerator& randGen);

    bool can_be_split_vertically();
    bool can_be_split_horizontally();


    void make_room(RandomGenerator& randGen);
    void draw_rooms(Terrain& t);
    bool is_room();


    void add_corridors(Terrain& t);
    void add_spawn(Terrain& t, RandomGenerator& randGen);
    void add_stairs(Terrain& t, RandomGenerator& randGen);


    Position left_top, right_bottom;
    std::unique_ptr<BSP> left_child, right_child;
};

#endif // BSP_H
