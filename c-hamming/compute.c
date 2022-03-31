#include "compute.h"
#include <string.h>

int compute(char *a, char *b) {
	int alen = strlen(a);
	int blen = strlen(b);
	int i = 0;
	int count = 0;
	if (alen != blen) {
		return -1;
	
	} else {
		for(i=0; i < alen; i++) {
			if (a[i] != b[i]) {
				count++;
			};			
		};
	};
	return count;	
}
