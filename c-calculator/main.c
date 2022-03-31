#include <stdio.h>

// Your calculate function should match this prototype:
void calculate(char *line);

int main(void) {
    char line[128];

    /* turn off stdout buffering */
    setbuf(stdout, NULL);

    /* read one line at a time and pass it to calculate */
    while ((fgets(line, 128, stdin)) != NULL) {
        calculate(line);
    }

    return 0;
}
