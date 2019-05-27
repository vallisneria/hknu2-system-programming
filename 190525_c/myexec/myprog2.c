// myprog2.c
#include <stdio.h>

int main(int argc, char* argv[]) {
    int i, p, l;

    if (argc < 2) {
        printf("Usage: %s number\n", argv[0]);
        exit(-1);
    }
    l = strtol(argv[1], 0, 0);

    for (p = i = 1; i <= l; i++) {
        p *= i;
    }
    printf("p = %d\n", p);
}