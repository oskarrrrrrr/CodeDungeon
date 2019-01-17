#ifndef CODEDUNGEON_TERRAIN_H
#define CODEDUNGEON_TERRAIN_H

#include <vector>

#include <MapGenerator/Field.h>


class Terrain
{
public:
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
    const std::pair<int, int>& spawnLoc() const
        { return spawnLoc_; }

    const Field& operator()(int row, int column) const;
    const Field& at(int row, int column) const;

    void addRoom(int row, int column, int h, int w);
    void addCorridor(int beginningRow, int beginningColumn, int length, bool isHorizontal);
    void setSpawn(int row, int column);
    void setStairs(int row, int column);

private:
    Field& operator()(int row, int column);

    int height_;
    int width_;
    std::vector< Field > fields_;
    bool isSpawn_;
    bool isStairs_;
    std::pair<int, int> spawnLoc_;
};


#endif //CODEDUNGEON_TERRAIN_H
