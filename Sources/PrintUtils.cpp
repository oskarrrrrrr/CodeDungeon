#include <curses.h>
#include <string>
#include <sstream>

#include <MapGenerator/Item.h>
#include <MapGenerator/Map.h>
#include <MapGenerator/Monster.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/Position.h>
#include <MapGenerator/Terrain.h>


void print_monsters_stats(const Map& map)
{
    int row = map.terrain().height() + 2;

    for (int i = 0; i < 5; ++i)
        mvwprintw(stdscr, row + i, 0, "                                                                                                                       ");

    for (auto m : map.monsters())
        mvwprintw(stdscr, row++, 0, "id: %d, pos_row: %d, pos_column: %d, actualHealth: %d, attack: %d", m.id(), m.position().row, m.position().column, m.actualHealth(), m.attack());
}

void showGameState(const Map& map)
{
    const auto& player = map.player();

    mvwprintw(stdscr, 0, 0, "                                         ");

    mvwprintw(stdscr, 0, 0, "Attack: %d", player->attack());
    mvwprintw(stdscr, 0, 16, "Health: %d/%d", player->actualHealth(), player->maxHealth());


    mvwaddstr(stdscr, 1, 0, const_cast<char*>(map.terrain().toString().c_str()) );


    for (const auto& mob : map.monsters())
    {
        auto& pos = mob.position();
        mvwaddch(stdscr, pos.row+1, pos.column, 'M');
    }
    for (const auto& item : map.items())
    {
        auto& pos = item->position();
        mvwaddch(stdscr, pos.row+1, pos.column, 'I');
    }

    auto& pos = player->position();
    mvwaddch(stdscr, pos.row+1, pos.column, 'P');
    wmove(stdscr, pos.row+1, pos.column);

    //print_monsters_stats(map);
}
