#include "wordle.h"
#include <stdio.h>
#include <string.h>

guess parse_guess(char *line) {
	guess guess;
	int count = 0;
	int len = strlen(line);
	for (int i = 0; i < len; i++) {
		if (line[i] >= 'a' && line[i] <= 'z') {
			guess.letters[count] = line[i];
			if (line[i+1] == ']') {
				guess.feedback[count] = EXACT_HIT;
			}
			else if (line[i+1] == ')') {
				guess.feedback[count] = PARTIAL_HIT;
			}
			else {
				guess.feedback[count] = MISS;
			}
			count++;
		}	
	}
	guess.letters[5] = '\0';
	return guess;	
}
