//
// Created by dawidbarzyk on 2/11/19.
//

#ifndef CODEDUNGEON_OUTPUTINIT_H
#define CODEDUNGEON_OUTPUTINIT_H

#include <curses.h>

int initialize()
{
    initscr();

    cbreak();
    keypad(stdscr, TRUE);
    intrflush(stdscr, FALSE);
    noecho();

    timeout(-1); // non-blocking read

    return curs_set(0);
}

void finalize(int curs)
{
    if (curs >= 0)
        curs_set(curs);
    endwin();
}


#endif //CODEDUNGEON_OUTPUTINIT_H
