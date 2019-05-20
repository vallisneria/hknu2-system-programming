#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

// 문자열로 들어온 permission을
// 8진수로 변환
int numTypePermission(mode_t mode, char* strperm) {
    int intperm = 0;

    // strperm의 마지막 자리 문자를 보고 판단
    switch (strperm[2]) {
        case 'r':
            intperm = 0b100;
            break;
        case 'w':
            intperm = 0b10;
            break;
        case 'x':
            intperm = 0b1;
            break;
        default:
            fprintf(stderr, "변경할 권한은 r, w, x 중에서만 선택할 수 있습니다.\n");
            return -1;
    }

    // strperm의 첫 번째 자리 문자를 보고 판단
    switch (strperm[0]) {
        case 'u':
            intperm << 6;
            break;
        case 'g':
            intperm << 3;
            break;
        case 'o':
            break;
        default:
            fprintf(stderr, "변경할 대상은 u, g, o 중에서만 선택할 수 있습니다.\n");
            return -1;
    }

    // strperm의 두 번째 자리 문자를 보고 판단.
    switch (strperm[1]) {
        case '+':
            intperm = intperm | mode;
            break;
        case '-':
            intperm = (intperm ^ 0b111111111) & mode;
        default:
            fprintf(stderr, "변경할 대상과 권한 사이의 연산자는 +, - 중에서만 선택할 수 있습니다.\n");
            return -1;
    }

    return intperm;
}