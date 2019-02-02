#include <MapGenerator/Position.h>

bool Position::operator == (const Position& rhs) const
{
    return row == rhs.row && column == rhs.column;
}

bool Position::operator != (const Position& rhs) const
{
    return !(*this == rhs);
}

void Position::operator += (const Move& rhs)
{
    if (rhs == Move{Move::UP})
        row--;
    if (rhs == Move{Move::DOWN})
        row++;
    if (rhs == Move{Move::RIGHT})
        column++;
    if (rhs == Move{Move::LEFT})
        column--;
}

Position Position::operator + (const Move& rhs) const
{
    Position newPos {row, column};
    newPos += rhs;
    return newPos;
}
