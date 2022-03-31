#include "wordle.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_word_list(char *filename) {
	char line[16];
	int len = 0, cap = 32;
	char **words = malloc(sizeof(char *) * cap);
	FILE *fp = fopen(filename, "r");
	assert(words != NULL);
	while (fgets(line, 16, fp) != NULL) {

		int wordlen = 5;
		char *word = malloc(wordlen + 1);
		assert(word != NULL);
		strncpy(word, line, wordlen);
		word[wordlen] = '\0';
		if (len == cap) {
			cap *= 2;
			words = realloc(words, sizeof(char *) * cap);
			assert(words != NULL);
		}
		words[len++] = word;	
	}
	words[len++] = '\0';
	fclose(fp);
	return words;
}

void free_word_list(char **list) {
	int i = 0;
	while (list[i] != NULL) {
		free(list[i]);
		i++;
	}
	if (list[i] == NULL) {
		free(list);
	}	
}
