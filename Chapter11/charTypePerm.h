#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int charTypePerm(int mode, char* strperm) {
    int intPerm;

    if (isdigit(strperm[0])) {
        return strtol(strperm, NULL, 8);
    }

    switch (strperm[2]) {
        case 'r':
            intPerm = 0b100;
            break;
        case 'w':
            intPerm = 0b10;
            break;
        case 'x':
            intPerm = 0b1;
            break;
    }

    switch (strperm[0]) {
        case 'u':
            intPerm = (intPerm << 6);
            break;
        case 'g':
            intPerm = (intPerm << 3);
            break;
        case 'o':
            intPerm = (intPerm << 0);
            break;
    }

    switch (strperm[1]) {
        case '+':
            intPerm = intPerm | mode;
            break;
        case '-':
            intPerm = (intPerm ^ 0b111111111) & mode;
            break;
    }

    return intPerm;
}