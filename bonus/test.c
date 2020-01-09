if (array[k][j] == 'O') {
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
