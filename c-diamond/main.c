#include <stdio.h>

void print_diamond(int);

int main(void) {
    int size;
    char *newline = "";
    while (scanf("%d", &size) == 1) {
        printf("%s", newline);
        newline = "\n";

        print_diamond(size);
    }

    return 0;
}
