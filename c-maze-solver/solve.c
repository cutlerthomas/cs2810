#include <stdio.h>
#include "solve.h"
#include <string.h>
#include <stdbool.h>

// write your code here
// note that solve.h is included. Look at that file
// to see what values are already defined for you and
// what your function signatures should match. You do not
// need to copy anything from main.c or solve.h into this file.

void print_maze(char field[SIZE_Y][SIZE_X]) {
	for(int i = 0; i < SIZE_Y; i++) {
		for(int j = 0; j < SIZE_X; j++) {
			printf("%c", field[i][j]);
		}
		printf("\n");
	}
}

void solve_maze(char field[SIZE_Y][SIZE_X]) {
	bool looper = true;
	while (looper != false) {
		int change = 0;
    		for (int i = 1; i < SIZE_Y-1; i++) {
        		for (int j = 1; j < SIZE_X-1; j++) {
            			if (field[i][j] == '.') {
            			int wcoun = 0;
                			if (field[i+1][j] == '@') {
                    				wcoun++;
                			}
                			if (field[i-1][j] == '@') {
                    				wcoun++;
                			}
                			if (field[i][j+1] == '@') {
                    				wcoun++;
                			}
                			if (field[i][j-1] == '@') {
                    				wcoun++;
                			}
				if (wcoun >= 3) {
                			field[i][j] = '@';
                			change++;
				}
				}
        		}
		}
    		if (change == 0) {
        		looper = false;
    		}
	}
}
