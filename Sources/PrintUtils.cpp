#include <curses.h>
#include <string>
#include <sstream>

#include <MapGenerator/Item.h>
#include <MapGenerator/Map.h>
#include <MapGenerator/Monster.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/Position.h>
#include <MapGenerator/Terrain.h>


void showGameState(const Map& map)
{
    const auto& player = map.player();

    mvwprintw(stdscr, 0, 5, "Attack: %d", player->attack());
    mvwprintw(stdscr, 0, 25, "Health: %d/%d", player->actualHealth(), player->maxHealth());


    mvwaddstr(stdscr, 1, 0, const_cast<char*>(map.terrain().toString().c_str()) );


    for (const auto& mob : map.monsters())
    {
        auto& pos = mob.position();
        mvwaddch(stdscr, pos.row+1, pos.column, 'M');
    }
    for (const auto& item : map.items())
    {
        auto& pos = item.position();
        mvwaddch(stdscr, pos.row+1, pos.column, 'I');
    }

    auto& pos = player->position();
    mvwaddch(stdscr, pos.row+1, pos.column, 'P');
    wmove(stdscr, pos.row+1, pos.column);
}
