#include "phonenumber.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void format_phone_number(char *line) {
	size_t len = strlen(line);
	unsigned int i = 0;
	char *pt1 = malloc(3);
	char *pt2 = malloc(3);
	char *pt3 = malloc(4);
	for (i=i; i < len; i++) {
		if (isdigit(line[i]) != 0) {
			if (isdigit(line[i+1]) != 0) {
				if (isdigit(line[i+2]) != 0) {
					pt1[0] = line[i];
					pt1[1] = line[i+1];
					pt1[2] = line[i+2];
					i = i + 3;
					break;	
				}
				else {
					printf("%s\n", "Invalid input");
					return;
				}
			}
			else {
				printf("%s\n", "Invalid input");
				return;
			}
		}		
	}
	for (i=i; i < len; i++) {
		if (isdigit(line[i]) != 0) {
			if (isdigit(line[i+1]) != 0) {
				if (isdigit(line[i+2]) != 0) {
					pt2[0] = line[i];
					pt2[1] = line[i+1];
					pt2[2] = line[i+2];
					i = i + 3;
					break;		
				}
				else {
					printf("%s\n", "Invalid input");
					return;
				}
			}
			else {
				printf("%s\n", "Invalid input");
				return;
			}	
		}	
	}
	for (i=i; i < len; i++) {
		if (isdigit(line[i]) != 0) {
			if (isdigit(line[i+1]) != 0) {
				if (isdigit(line[i+2]) != 0) {
					if (isdigit(line[i+3]) != 0) {
						if (isdigit(line[i+4]) != 0) {
							printf("%s\n", "Invalid input");
							return;
						}
						pt3[0] = line[i];
						pt3[1] = line[i+1];
						pt3[2] = line[i+2];
						pt3[3] = line[i+3];
						printf("(%s) %s-%s\n", pt1, pt2, pt3);
						break;		
					}
					else {
						printf("%s\n", "Invalid input");
						return;
					}
				}
				else {
					printf("%s\n", "Invalid input");
					return;
				}
			}
			else {
				printf("%s\n", "Invalid input");
				return;
			}
		}
	}	
}
