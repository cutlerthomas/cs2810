#include "letters.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void letters_used(char *line) {
	size_t len = strlen(line);
	char *ans = "";
	ans = malloc(len);
	int k = 0;
	char *copy = malloc(len + 1 + 1);
	strcpy(copy, line);
	// add all letters to ans string
	for (unsigned int i = 0; i < len; i++) {
		if (isalpha(copy[i])) {
			char lowlet = tolower(copy[i]);
			if (strchr(ans, lowlet) == NULL) {
				ans[k] = tolower(lowlet);
				k++;	
			}	
		}	
	}
	// sort the ans string
	size_t anslen = strlen(ans);
	char temp;
	for (unsigned int i = 0; i < anslen; i++) {
		for (unsigned int j = 0; j < anslen; j++) {
			if (ans[i] < ans[j]) {
				temp = tolower(ans[i]);
				ans[i] = tolower(ans[j]);
				ans[j] = tolower(temp);
			}
		}
	}
	printf("%s\n", ans);
}
