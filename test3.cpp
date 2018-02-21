#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <vector>

#define WIDTH 50
#define HEIGHT 20

using namespace std;
enum direction { UP, DOWN, RIGHT, LEFT};

int main()
{
    WINDOW *winbox;
    int offsetx, offsety;
    int x = WIDTH / 2;
    int y = HEIGHT / 2;
    int ox = x;
    int oy = y;

    initscr();
    noecho();
    cbreak();
    timeout(100);
    keypad(stdscr, TRUE);
    printw("hello, world");
    refresh();

    offsetx = (COLS - WIDTH) / 2;
    offsety = (LINES - HEIGHT) / 2;
    int ch;

    winbox = newwin(HEIGHT, WIDTH, offsety, offsetx);
    wrefresh(winbox);
    while (true) {
        wclear(winbox);
        ch = getch();
        ox = x;
        oy = y;
        if (ch != ERR) {
            switch (ch) {
                case 'w':
                    --y; break;
                case 's':
                    ++y; break;
                case 'a':
                    --x; break;
                case 'd':
                    ++x; break;
                case KEY_UP:
                    --y; break;
                case KEY_DOWN:
                    ++y; break;
                case KEY_LEFT:
                    --x; break;
                case KEY_RIGHT:
                    ++x; break;
                default:
                    break;
            }
        }
        mvwaddch(winbox, y, x, '#');
        box(winbox, 0, 0);
        wrefresh(winbox);
        if (ch == 'q') break;
    }


    delwin(winbox);
    endwin();
    return 0;



}
