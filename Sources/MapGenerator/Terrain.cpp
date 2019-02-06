#include <sstream>
#include <stdexcept>

#include <MapGenerator/Terrain.h>

const Field& Terrain::operator[](const Position& pos) const
{
    return fields_[pos.row*width_ + pos.column];
}

Field& Terrain::operator[](const Position& pos)
{
    return const_cast<Field &>(static_cast<const Terrain &>(*this)[pos]);
}

const Field& Terrain::at(const Position& pos) const
{
    if (pos.row >= height_)
        throw std::out_of_range("Terrain: 'row' arg in 'at' function out of range.");
    else if (pos.column >= width_)
        throw std::out_of_range("Terrain: 'column' arg in 'at' function out of range.");
    return (*this)[pos];
}

void Terrain::addRoom(const Position& pos, int h, int w)
{
    for (int r = pos.row; r < pos.row + h; r++)
    {
        for (int c = pos.column; c < pos.column + w; c++)
            (*this)[{r, c}] = Field::Ground;
    }
}

void Terrain::addCorridor(const Position& begin, int length, bool isHorizontal)
{
    if (isHorizontal)
        for (int c = begin.column; c < begin.column + length; c++)
                (*this)[{begin.row, c}] = Field::Ground;
    else
        for (int r = begin.row; r < begin.row + length; r++)
            (*this)[{r, begin.column}] = Field::Ground;
}

void Terrain::setSpawn(const Position& pos)
{
    if (isSpawn_)
        throw std::logic_error("Spawn has been already set");
    (*this)[pos] = Field::Spawn;
    isSpawn_ = true;

    spawnLoc_ = pos;
}

void Terrain::setStairs(const Position& pos)
{
    if (isStairs_)
        throw std::logic_error("Stairs has been already set");
    (*this)[pos] = Field::Stairs;
    isStairs_ = true;
}





char fieldToChar(const Field& f)
{
    switch (f)
    {
        case Field::Wall:
            return '#';
        case Field::Ground:
            return '-';
        case Field::Spawn:
            return 'O';
        case Field::Stairs:
            return 'V';
    }
}


std::string Terrain::toString() const
{
    std::ostringstream res;
    for (int r = 0; r < height_; r++)
    {
        for (int c = 0; c < width_; c++)
            res << fieldToChar((*this)[{r, c}]);
        res << "\n";
    }
    return res.str();
}
