// myprog1.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i, s, l;

    if (argc < 2) {
        printf("Usage: %s number\n", argv[0]);
        return -1;
    }
    l = strtol(argv[1], 0, 0);

    for (s = 0, i = 1; i <= l; i++) {
        s += 1;
    }

    printf("s = %d\n", s);
}