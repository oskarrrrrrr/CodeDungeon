#include <sstream>
#include <stdexcept>

#include <MapGenerator/Terrain.h>

const Field& Terrain::operator()(int row, int column) const
{
    return fields_[row*width_ + column];
}

Field& Terrain::operator()(int row, int column)
{
    return const_cast<Field &>(static_cast<const Terrain &>(*this)(row, column));
}

const Field& Terrain::at(int row, int column) const
{
    if (row >= height_)
        throw std::out_of_range("Terrain: 'row' arg in 'at' function out of range.");
    else if (column >= width_)
        throw std::out_of_range("Terrain: 'column' arg in 'at' function out of range.");
    return (*this)(row, column);
}

void Terrain::addRoom(int row, int column, int h, int w)
{
    for (int r = row; r < row + h; r++)
    {
        for (int c = column; c < column + w; c++)
            (*this)(r, c) = Field::Ground;
    }
}

void Terrain::addCorridor(int beginningRow, int beginningColumn, int length, bool isHorizontal)
{
    if (isHorizontal)
        for (int c = beginningColumn; c < beginningColumn + length; c++)
                (*this)(beginningRow, c) = Field::Ground;
    else
        for (int r = beginningRow; r < beginningRow + length; r++)
            (*this)(r, beginningColumn) = Field::Ground;
}

void Terrain::setSpawn(int row, int column)
{
    if (isSpawn_)
        throw std::logic_error("Spawn has been already set");
    (*this)(row, column) = Field::Spawn;
    isSpawn_ = true;

    spawnLoc_ = std::make_pair(row, column);
}

void Terrain::setStairs(int row, int column)
{
    if (isStairs_)
        throw std::logic_error("Stairs has been already set");
    (*this)(row, column) = Field::Stairs;
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
            res << fieldToChar((*this)(r, c));
        res << "\n";
    }
    return res.str();
}
