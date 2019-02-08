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
        case '0':
            if(items_[0]) result = UseItem{items_[0]->id()};
            else result = Wait{};
            break;
        case '1':
            if(items_[1]) result = UseItem{items_[1]->id()};
            else result = Wait{};
            break;
        case '2':
            if(items_[2]) result = UseItem{items_[2]->id()};
            else result = Wait{};
            break;
        case '3':
            if(items_[3]) result = UseItem{items_[3]->id()};
            else result = Wait{};
            break;
        case '4':
            if(items_[4]) result = UseItem{items_[4]->id()};
            else result = Wait{};
            break;
        case '5':
            if(items_[5]) result = UseItem{items_[5]->id()};
            else result = Wait{};
            break;
        case '6':
            if(items_[6]) result = UseItem{items_[6]->id()};
            else result = Wait{};
            break;
        case '7':
            if(items_[7]) result = UseItem{items_[7]->id()};
            else result = Wait{};
            break;
        case '8':
            if(items_[8]) result = UseItem{items_[8]->id()};
            else result = Wait{};
            break;
        case '9':
            if(items_[9]) result = UseItem{items_[9]->id()};
            else result = Wait{};
            break;
        default:
            result = Wait{};
            break;
    }

    return result;
}