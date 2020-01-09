/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** mario sokoban like game
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

int open_file(char *name_file, int *val)
{
	*val = open(name_file, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
	if (*val == -1) {
		write(2, "open error\n", 11);
		return(84);
	}
	return(0);
}

void put_in(char *buffer, int *line, int val)
{
	int i;
	int g = 0;

	i = 0;
	while (read(val, buffer + i, 1) == 1) {
		i = i + 1;
	}
	buffer[i] = '\0';
	i = 0;
	while (buffer[i] != '\0') {
		if (buffer[i] == '\n')
			g++;
		i++;
	}
	*line = g;
}

int add(char *buffer)
{
	int m = 0;
	int n;
	int column;

	n = 0;
	while (buffer[n] != '\n') {
		m++;
		n++;
	}
	column = m;
	return(column);
}

void driver(char **av)
{
	int val;

	open_file(av[1], &val);
	read_to(val);
}

int read_to(int val)
{
	char buffer[450000];
	int line;
	int column;

	put_in(buffer, &line, val);
	column = add(buffer);
	char array[line][column];
	for(int k = 0 ; k < line ; k++) {
		for(int j = 0 ; j < column ; j++) {
			array[k][j] = buffer[k * (column + 1) + j];
		}
	}
	my_sokoban(line, column, array);
	return(0);
}
