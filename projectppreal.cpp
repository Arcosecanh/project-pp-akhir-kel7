#include <ncurses.h>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    initscr(); cbreak(); noecho(); curs_set(0);

    const int W = 40, H = 20, N = 6;

    int my, mx;
    getmaxyx(stdscr, my, mx);
    int oy = (my - H) / 2, ox = (mx - W) / 2;
    if (oy < 0) oy = 0;
    if (ox < 0) ox = 0;
    WINDOW *w = newwin(H, W, oy, ox);
    keypad(w, TRUE);
    wtimeout(w, 50);
