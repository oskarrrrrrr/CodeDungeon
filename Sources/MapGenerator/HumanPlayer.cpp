#include <curses.h>

#include <MapGenerator/HumanPlayer.h>
#include <MapGenerator/Map.h>

Action HumanPlayer::genAction(Map& map) const
{
    int c = 0;
    int lastKey = 0;
    Action result;

    while( (c = wgetch(stdscr)) != EOF )
    {
        lastKey = c;
    }
    c = lastKey;

    switch(c)
    {
        case KEY_UP:
            result = Move{Move::UP};
            break;
        case KEY_DOWN:
            result = Move{Move::DOWN};
            break;
        case KEY_LEFT:
            result = Move{Move::LEFT};
            break;
        case KEY_RIGHT:
            result = Move{Move::RIGHT};
            break;
        default:
            result = Wait{};
            break;
    }

    return result;
}