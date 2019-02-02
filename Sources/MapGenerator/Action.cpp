#include <MapGenerator/Action.h>

bool Attack::operator == (const Attack& rhs) const
{
    return dir == rhs.dir;
}

bool Attack::operator != (const Attack& rhs) const
{
    return ! (*this == rhs);
}


bool Move::operator == (const Move& rhs) const
{
    return dir == rhs.dir;
}

bool Move::operator != (const Move& rhs) const
{
    return ! (*this == rhs);
}
