#include <MapGenerator/Position.h>

bool Position::operator == (const Position& rhs) const
{
    return row == rhs.row && column == rhs.column;
}

bool Position::operator != (const Position& rhs) const
{
    return !(*this == rhs);
}

void Position::operator += (const Direction& rhs)
{
    if (rhs == Direction::UP)
        row--;
    if (rhs == Direction::DOWN)
        row++;
    if (rhs == Direction::RIGHT)
        column++;
    if (rhs == Direction::LEFT)
        column--;
}

Position Position::operator + (const Direction& rhs) const
{
    Position newPos {row, column};
    newPos += rhs;
    return newPos;
}
