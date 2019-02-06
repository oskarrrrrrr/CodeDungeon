#ifndef CODEDUNGEON_TERRAIN_H
#define CODEDUNGEON_TERRAIN_H

#include <string>
#include <vector>

#include <MapGenerator/Field.h>
#include <MapGenerator/Position.h>


class Terrain
{
public:
    Terrain() = default;

    Terrain(int h, int w)
    : height_(h),
      width_(w),
      fields_(h*w, Field::Wall),
      isSpawn_(false),
      isStairs_(false)
    {}

    int height() const
        { return height_; }
    int width() const
        { return width_; }
    const Position& spawnLoc() const
        { return spawnLoc_; }

    const Field& operator[](const Position& pos) const;
    Field& operator[](const Position& pos);

    const Field& at(const Position& pos) const;

    void addRoom(const Position& pos, int h, int w);
    void addCorridor(const Position& pos, int length, bool isHorizontal);
    void setSpawn(const Position& pos);
    void setStairs(const Position& pos);


    std::string toString() const;

private:

    int height_;
    int width_;
    std::vector< Field > fields_;
    bool isSpawn_;
    bool isStairs_;
    Position spawnLoc_;
};


#endif //CODEDUNGEON_TERRAIN_H
