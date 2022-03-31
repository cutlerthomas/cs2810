#include "wordle.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int score(char **word_list, char *candidate, guess *guesses, int guess_count) {
	int score = 0;
	int i = 0;
	while (word_list[i] != NULL) {
		strcpy(char *copy, word_list[i]);
		bool match = is_viable_candidate(copy, guesses, guess_count);
		if (match == true) {
			for (int j = 0; j < 5; j++) {
				if (candidate[j] == copy[j]) {
					score += EXACT_HIT_POINTS;
					copy[j] = '_';
				}
			}
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (candidate[j] == copy[k]) {
						score += PARTIAL_HIT_POINTS;
						copy[k] = '_';
						break;
					}
				}
			}
		i++;
		return score;
		}
	}
}
