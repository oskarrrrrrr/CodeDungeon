#include <MapGenerator/Action.h>

bool Quit::operator==(const Quit &rhs) const
{
    return true;
}

bool Quit::operator!=(const Quit &rhs) const
{
    return false;
}

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


bool GoNextFloor::operator == (const GoNextFloor& rhs) const
{
    return true;
}

bool GoNextFloor::operator != (const GoNextFloor& rhs) const
{
    return false;
}


bool UseItem::operator == (const UseItem& rhs) const
{
    return id == rhs.id;
}

bool UseItem::operator != (const UseItem& rhs) const
{
    return ! (*this == rhs);
}


bool Wait::operator == (const Wait& rhs) const
{
    return true;
}

bool Wait::operator != (const Wait& rhs) const
{
    return false;
}
