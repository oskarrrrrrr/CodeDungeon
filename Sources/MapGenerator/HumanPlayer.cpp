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
            result = Move{Direction::UP};
            break;
        case KEY_DOWN:
            result = Move{Direction::DOWN};
            break;
        case KEY_LEFT:
            result = Move{Direction::LEFT};
            break;
        case KEY_RIGHT:
            result = Move{Direction::RIGHT};
            break;
        default:
            result = Wait{};
            break;
    }

    return result;
}