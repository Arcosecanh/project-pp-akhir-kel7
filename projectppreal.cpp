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

// bagian sekar taro di sini yeah

        frame++;
        int jeda = 4 - skor / 100;           // makin tinggi skor, makin cepat
        if (jeda < 1) jeda = 1;

        if (frame % 20 == 0)                 // munculkan objek baru
            for (int i = 0; i < N; i++)
                if (y[i] < 0) { x[i] = rand() % (W - 2) + 1; y[i] = 1; bom[i] = rand() % 4 == 0; break; }

        if (frame % jeda == 0)               // objek jatuh
            for (int i = 0; i < N; i++) {
                if (y[i] < 0) continue;
                if (++y[i] == H - 2) {
                    bool kena = x[i] >= kx && x[i] < kx + 7;
                    if (kena && bom[i]) nyawa--;   // nyawa berkurang hanya kena bom
                    else if (kena) skor += 10;     // bintang = +10 poin
                    y[i] = -1;
                }
            }
