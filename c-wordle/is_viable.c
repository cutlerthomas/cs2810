#include <stdbool.h>
#include "wordle.h"
#include <string.h>

bool is_viable_candidate(char *candidate, guess *guesses, int guess_count) {
	for (int count = 0; count < guess_count; count++) {
		char copy[6];
		strcpy(copy, candidate);
		for (int i = 0; i < 5; i++) {
			if (guesses[count].feedback[i] == EXACT_HIT) {
				if (copy[i] == guesses[count].letters[i]) {
					copy[i] = '_';
				}
				else {
					return false;				
				}
			}	
		}
		for (int i = 0; i < 5; i++) {
			if (guesses[count].feedback[i] == PARTIAL_HIT) {
				if (copy[i] == guesses[count].letters[i]) {
					return false;
				}	
			}
		}
		for (int i = 0; i < 5; i++) {
			if (guesses[count].feedback[i] == PARTIAL_HIT) {
				for (int j = 0; j < 5; j++) {
					if (copy[j] == guesses[count].letters[i]) {
						copy[j] = '_';
						break;
					}
					else {
						if(j == 4) {
							return false;
						}
					}
				}	
			}
		}
		for (int i = 0; i < 5; i++) {
			if (guesses[count].feedback[i] == MISS) {
				for (int j = 0; j < 5; j++) {
					if (copy[j] == guesses[count].letters[i]) {
						return false;
					}
				}
			}
		}
	}
return true;
}
