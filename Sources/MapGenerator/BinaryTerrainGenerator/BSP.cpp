#include <MapGenerator/BinaryTerrainGenerator/BSP.h>

#include <iostream>

const int MIN_PARTITION_WIDTH = 14;
const int MIN_PARTITION_HEIGHT = 12;

void BSP::split(RandomGenerator& randGen)
{
    if (randGen.generate(0,1))
    {
        split_vertically(randGen);
    }
    else
    {
        split_horizontally(randGen);
    }
}

void BSP::split_vertically(RandomGenerator& randGen)
{
    if (!can_be_split_vertically())
    {
        if (can_be_split_horizontally() && randGen.generate(1,10) > 5)
            split_horizontally_raw(randGen);
        else
        {
            make_room(randGen);
            return;
        }
    }

    split_vertically_raw(randGen);
    left_child->split(randGen);
    right_child->split(randGen);
}

void BSP::split_horizontally(RandomGenerator& randGen)
{
    if (!can_be_split_horizontally())
    {
        if (can_be_split_vertically() && randGen.generate(1,10) > 5)
            split_vertically_raw(randGen);
        else
        {
            make_room(randGen);
            return;
        }
    }

    split_horizontally_raw(randGen);
    left_child->split(randGen);
    right_child->split(randGen);
}


void BSP::split_vertically_raw(RandomGenerator& randGen)
{
    int split_column = randGen.generate(
        left_top.column + MIN_PARTITION_WIDTH - 1,
        right_bottom.column - MIN_PARTITION_WIDTH);

    if (split_column <= left_top.column || split_column >= right_bottom.column)
        return;

    left_child = std::make_unique<BSP>(left_top, Position(right_bottom.row, split_column));
    right_child = std::make_unique<BSP>(Position(left_top.row, split_column+1), right_bottom);
}

void BSP::split_horizontally_raw(RandomGenerator& randGen)
{
    int split_row = randGen.generate(
        left_top.row + MIN_PARTITION_HEIGHT - 1,
        right_bottom.row - MIN_PARTITION_HEIGHT);

    if (split_row <= left_top.row || split_row >= right_bottom.row)
        return;

    left_child = std::make_unique<BSP>(left_top, Position(split_row, right_bottom.column));
    right_child = std::make_unique<BSP>(Position(split_row+1, left_top.column), right_bottom);
}

bool BSP::can_be_split_vertically()
{
    return right_bottom.column - left_top.column + 1 > 2 * MIN_PARTITION_WIDTH;
}

bool BSP::can_be_split_horizontally()
{
    return right_bottom.row - left_top.row >= 2 * MIN_PARTITION_HEIGHT;
}

void BSP::make_room(RandomGenerator& randGen)
{
    // MAX
    // Position left_top_pos(
    //     left_top.row+1,
    //     left_top.column+1
    // );
    //
    // Position right_bottom_pos(
    //     right_bottom.row-1,
    //     right_bottom.column-1
    // );

    // NAIVE RAND
    // Position left_top_pos(
    //     randGen.generate(left_top.row+1, right_bottom.row-2),
    //     randGen.generate(left_top.column+1, right_bottom.column-2)
    // );
    //
    // Position right_bottom_pos(
    //     randGen.generate(left_top_pos.row+1, right_bottom.row-1),
    //     randGen.generate(left_top_pos.column+1, right_bottom.column-1)
    // );

    Position left_top_pos(
        randGen.generate(left_top.row+2, left_top.row+5),
        randGen.generate(left_top.column+2, left_top.column+5)
    );

    Position right_bottom_pos(
        randGen.generate(right_bottom.row-5, right_bottom.row-2),
        randGen.generate(right_bottom.column-5, right_bottom.column-2)
    );

    if ( right_bottom_pos.row - left_top_pos.row < 4
        || right_bottom_pos.column - left_top_pos.column < 4)
    {
        make_room(randGen);
        return;
    }

    left_child = std::make_unique<BSP>(
        left_top_pos,
        right_bottom_pos
    );
}

void BSP::draw_rooms(Terrain& t)
{
    if (is_room())
    {
        t.addRoom(
            left_top,
            right_bottom.row - left_top.row + 1,
            right_bottom.column - left_top.column + 1);
    }
    else
    {
        if (left_child)
            left_child->draw_rooms(t);

        if (right_child)
            right_child->draw_rooms(t);
    }
}

bool BSP::is_room()
{
    return !left_child && !right_child;
}

void BSP::add_corridors(Terrain& t)
{
    if (is_room())
        return;

    if (left_child && right_child
        && left_child->left_child && right_child->left_child
        && left_child->left_child->is_room() && right_child->left_child->is_room())
    {
        if (left_child->left_top.column == right_child->left_top.column)
        {
            t.addCorridor(
                {left_child->left_child->right_bottom.row+1, (left_child->left_top.column+left_child->right_bottom.column)/2},
                right_child->left_child->left_top.row - left_child->left_child->right_bottom.row - 1,
                false);
        }
        else
        {
            t.addCorridor(
                {(left_child->left_top.row+left_child->right_bottom.row)/2, left_child->left_child->right_bottom.column+1},
                right_child->left_child->left_top.column - left_child->left_child->right_bottom.column - 1,
                true);
        }
        return;
    }

    if (left_child) left_child->add_corridors(t);
    if (right_child) right_child->add_corridors(t);

    if (left_child && right_child)
    {
        if (left_child->left_top.column == right_child->left_top.column)
        {
            t.addCorridor(
                {(left_child->left_child->left_top.row+left_child->left_child->right_bottom.row)/2, (left_child->left_child->left_top.column+left_child->left_child->right_bottom.column)/2},
                (right_child->left_child->left_top.row+right_child->left_child->right_bottom.row)/2 - (left_child->left_child->left_top.row+left_child->left_child->right_bottom.row)/2,
                false);
        }
        else
        {
            t.addCorridor(
                {(left_child->left_child->left_top.row+left_child->left_child->right_bottom.row)/2, (left_child->left_child->left_top.column+left_child->left_child->right_bottom.column)/2},
                (right_child->left_child->left_top.column+right_child->left_child->right_bottom.column)/2 - (left_child->left_child->left_top.column+left_child->left_child->right_bottom.column)/2,
                true);
        }
    }
}

void BSP::add_spawn(Terrain& t, RandomGenerator& randGen)
{
    if(is_room())
    {
        t.setSpawn(
            {
                (left_top.row+right_bottom.row)/2,
                (left_top.column+right_bottom.column)/2
            }
        );
    }
    else
    {
        if(randGen.generate(1,10) > 6)
        {
            if (right_child)
                right_child->add_spawn(t, randGen);
            else
                left_child->add_spawn(t, randGen);
        }
        else
        {
            left_child->add_spawn(t, randGen);
        }
    }
}

void BSP::add_stairs(Terrain& t, RandomGenerator& randGen)
{
    if(is_room())
    {
        t.setStairs(
            {
                (left_top.row+right_bottom.row)/2,
                (left_top.column+right_bottom.column)/2
            }
        );
    }
    else
    {
        if(randGen.generate(1,10) > 8)
        {
            left_child->add_stairs(t, randGen);
        }
        else
        {
            if (right_child)
                right_child->add_stairs(t, randGen);
            else
                left_child->add_stairs(t, randGen);
        }
    }
}
