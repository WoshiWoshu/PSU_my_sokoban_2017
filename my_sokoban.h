/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** headers of my sokoban project
*/

int add(char *buffer);
void to_print_array(int line , int column, char arrary[line][column]);
int open_file(char *name_file, int *val);
int read_to(int val);
void driver(char **av);
int my_sokoban(int line, int column, char array[line][column]);
void put_in(char *buffer, int *line, int val);
int my_get_nbr(char const *str);
