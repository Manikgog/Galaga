#include <curses.h>

int main() {
    int c;
    int y = 28, x = 35;
    int cols, rows;
    initscr();
    keypad(stdscr, TRUE); // allow arrows
    noecho(); // don't display input
    curs_set(0); // hide cursor
    mvprintw(11, 20, "Hello world!");
    getmaxyx(stdscr, rows, cols);
    char map[rows][cols];

    do {
        clear();

        for (int yy = 0; yy < rows; yy++) {
            for (int xx = 0; xx < cols; xx++) {
                map[yy][xx] = '#';
                mvaddch(yy, xx, '#');
            }
        }
        for (int yy = 1; yy <= rows - 2; yy++) {
            for (int xx = 11; xx <= cols / 2; xx++) {
                map[yy][xx] = ' ';
                mvaddch(yy, xx, ' ');
            }
        }

        if (c == KEY_DOWN) {
            for (int yy = 1; yy < 28; yy++) {
                mvaddch(yy, x, 'I');
            }
        }

        else if (c == KEY_LEFT && map[y][x - 1] == ' ') {
            x--;
        }
        else if (c == KEY_RIGHT && map[y][x + 1] == ' ') {
            x++;
        }

        mvaddch(y, x, '@'); // print cursor

    } while ((c = getch()) != 27); // 27 - ESC (c = getch())!=27

    getch();
    endwin();
    return 0;
}


