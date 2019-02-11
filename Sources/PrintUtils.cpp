#include <curses.h>
#include <string>
#include <sstream>

#include <MapGenerator/Item.h>
#include <MapGenerator/Map.h>
#include <MapGenerator/Monster.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/Position.h>
#include <MapGenerator/Terrain.h>

namespace {

void print_monsters_stats(const Map &map) {
    int row = map.terrain().height() + 2;

    for (int i = 0; i < 5; ++i)
        mvwprintw(stdscr, row + i, 0,
                  "                                                                                                                       ");

    for (auto m : map.monsters())
        mvwprintw(stdscr, row++, 0, "id: %d, pos_row: %d, pos_column: %d, actualHealth: %d, attack: %d", m.id(),
                  m.position().row, m.position().column, m.actualHealth(), m.attack());
}

}  // namespace

void showGameState(const Map& map)
{
    const auto& player = map.player();

    mvwprintw(stdscr, 0, 0, "                                         ");

    mvwprintw(stdscr, 0, 0, "Attack: %d", player->attack());
    mvwprintw(stdscr, 0, 16, "Health: %d/%d", player->actualHealth(), player->maxHealth());
    std::string preparedItemsLine = "Items:  [0] " + player->getStringOfItem(0) + " [1] " + player->getStringOfItem(1) +
        " [2] " + player->getStringOfItem(2) + " [3] " + player->getStringOfItem(3) + " [4] " + player->getStringOfItem(4) +
        " [5] " + player->getStringOfItem(5) + " [6] " + player->getStringOfItem(6) + " [7] " + player->getStringOfItem(7) +
        " [8] " + player->getStringOfItem(8) + " [9] " + player->getStringOfItem(9);
    mvwprintw(stdscr, 0, 32, preparedItemsLine.c_str());

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

    mvwaddstr(stdscr, 42, 0, "PRESS BACKSPACE TO QUIT");
    refresh();
    //print_monsters_stats(map);
}

void showGameEnd(int floor)
{
    werase(stdscr);
    mvwprintw(stdscr, 0, 0, "Congrats, You beat %d levels!!", floor);
    mvwprintw(stdscr, 1, 0, "press backspace to quit");
}

bool tryGettingBackspace()
{
    int c = EOF;
    while (c == EOF)
    {
        c = wgetch(stdscr);
    }
    return c == KEY_BACKSPACE;
}