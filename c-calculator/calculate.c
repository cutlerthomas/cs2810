// write your code here
//
// note: you should write a function that matches the prototype in `main.c`
// do NOT copy anything else from main.c
#include <stdio.h>
#include <string.h>

int calculate(char *line) {
    int a;
    int b;
    int n;
    if (strcmp(line, "What is %d added to %d?\n")) {
    	n = sscanf(line, "What is %d added to %d?\n", &a, &b);
    	printf("%d + %d = %d\n", a, b, a+b);
    	return n;
	}
    else {
    }	printf("I do not understand the question, sorry!\n");
return 0;
}
