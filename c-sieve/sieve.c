#include <stdbool.h>

void sieve(bool *list, int num) {
	for (int i=0; i<=num; i++) {
		list[i] = true;
	}
	for (int i = 2; i*i <= num; i++) {
		if (list[i] != false) {
			for (int j = 2*i; j <= num; j += i) {
				list[j] = false;
			}
		}
	}	
}
