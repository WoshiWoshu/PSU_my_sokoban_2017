/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** mario sokoban type project game
*/

#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_sokoban.h"

int my_sokoban(int line, int column, char array[line][column])
{
	WINDOW *window;
	int i;
	int j;
	int f;
	int h;
	int m;
	int x;
	int y;
	int cup_x;
	int cup_y;
	int x2;
	int y2;
	int x3;
	int y3;
	int slot = 0;
	int array_2[1000];
	int array_3[1000];
	int array_box[1000];
	int array_box_2[1000];

	initscr();
	keypad(stdscr, TRUE);
	for (int k = 0 ; k < line ; k++) {
		for (int j = 0 ; j < column ; j++) {
			if(array[k][j] == 'P') {
				y = k;
				x = j;
			}
			if(array[k][j] == 'O') {
				array_2[slot] = k;
				array_3[slot] = j;
				slot++;
			}
		}
	}
	array_2[slot] = '\0';
	array_3[slot] = '\0';
	h = 0;
	while (array_2[h] != '\0') {
		h++;
	}
	while (1) {
		clear();
		window = subwin(stdscr, LINES, COLS, 0, 0);
		box(window, ACS_VLINE, ACS_HLINE);
		for (int k = 0 ; k < line ; k++) {
			for (int j = 0 ; j < column ; j++) {
				printw("%c", array[k][j]);
			}
			printw("\n");
		}
		if (getch() == KEY_RIGHT) {
			if (array[y][x + 1] != '#') {
				if (array[y][x + 1] == 'X' & array[y][x + 2] != '#' & array[y][x + 2] != 'X') {
					array[y][x+2] = 'X';
					array[y][x] = ' ';
					array[y][x + 1] = 'P';
					x++;
				}
				if (array[y][x + 1] != 'X') {
					array[y][x] = ' ';
					array[y][x + 1] = 'P';
					x++;
				}
			}
		}
		if (getch() == KEY_LEFT) {
			if (array[y][x - 1] != '#') {
				if (array[y][x - 1] == 'X' & array[y][x - 2] != '#' & array[y][x - 2] != 'X') {
					array[y][x - 2] = 'X';
					array[y][x] = ' ';
					array[y][x - 1] = 'P';
					x--;
				}
				if (array[y][x - 1] != 'X') {
					array[y][x] = ' ';
					array[y][x - 1] = 'P';
					x--;
				}
			}
		}
		if (getch() == KEY_UP) {
			if (array[y - 1][x] != '#') {
				if (array[y - 1][x] == 'X' & array[y - 2][x] != '#' & array[y - 2][x] != 'X') {
					array[y - 2][x] = 'X';
					array[y][x] = ' ';
					array[y - 1][x] = 'P';
					y--;
				}
				if (array[y - 1][x] != 'X') {
					array[y][x] = ' ';
					array[y - 1][x] = 'P';
					y--;
				}
			}
		}
		if (getch() == KEY_DOWN) {
			if (array[y + 1][x] != '#') {
				if (array[y + 1][x] == 'X' & array[y + 2][x] != '#' & array[y + 2][x] != 'X') {
					array[y + 2][x] = 'X';
					array[y][x] = ' ';
					array[y + 1][x] = 'P';
					y++;
				}
				if (array[y + 1][x] != 'X') {
					array[y][x] = ' ';
					array[y + 1][x] = 'P';
					y++;
				}
			}
		}
		for (int k = 0 ; k < line ; k++) {
			for (int j = 0 ; j < column ; j++) {
				i = 0;
				while (array_2[i] != '\0' && array_3[i] != '\0') {
					cup_y = array_2[i];
					cup_x = array_3[i];
					if (array[cup_y][cup_x + 1] == 'P' && array[cup_y][cup_x] != 'X') {
						array[cup_y][cup_x] = 'O';
					}
					if (array[cup_y][cup_x - 1] == 'P' && array[cup_y][cup_x] != 'X') {
						array[cup_y][cup_x] = 'O';
					}
					if (array[cup_y - 1][cup_x] == 'P' && array[cup_y][cup_x] != 'X') {
						array[cup_y][cup_x] = 'O';
					}
					if (array[cup_y + 1][cup_x] == 'P' && array[cup_y][cup_x] != 'X') {
						array[cup_y][cup_x] = 'O';
					}
					i++;
				}
				m = 0;
				f = 0;
				while (array[array_2[m]][array_3[m]] == 'X') {
					f++;
					m++;
				}
				if (f == h) {
					endwin();
					free(window);
					return(0);
				}
				if (array[k][j] == 'X') {
					if (array[k][j + 1] == '#' && array[k + 1][j] == '#') {
						endwin();
						free(window);
						return(1);
					}
					if (array[k][j - 1] == '#' && array[k + 1][j] == '#') {
						endwin();
						free(window);
						return(1);
					}
					if (array[k][j + 1] == '#' && array[k - 1][j] == '#') {
						endwin();
						free(window);
						return(1);
					}
					if (array[k][j - 1] == '#' && array[k - 1][j] == '#') {
						endwin();
						free(window);
						return(1);
					}
				}
			}
		}
		wrefresh(window);
		refresh();
	}
	endwin();
	free(window);
	return(0);
}
