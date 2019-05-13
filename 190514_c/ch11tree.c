/*
    2019년 05월 13일
    시스템프로그래밍 실습과제

    파일에 트리를 출력하는 프로그램 ch11tree.c를 작성하시오.
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "errprint.h"

#define MAXLINE 19

int main(int argc, char* argv[]) {
    if (argc != 2) {
        errprint("사용법: ch10tree [파일명]\n");
        return -1;
    }

    const int fin = open(argv[1], O_WRONLY);
    const char tree = '$';
    const char enter = '\n';
    const char space = ' ';

    for (int i = 0; i < MAXLINE; i++) {
        for (int j = 0; j < MAXLINE; j++) {
            if (j == MAXLINE - i * 2 + 1) {
                for (int k = 0; k < MAXLINE - i * 2 + 1; k++) {
                    write(fin, &tree, sizeof(tree));
                }
                break;
            }
            write(fin, &space, sizeof(space));
        }
        write(fin, &enter, sizeof(enter));
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (int)MAXLINE / 2 + 1; j++) {
            if (j == (int)MAXLINE / 2 + 1) {
                write(fin, &tree, sizeof(tree));
            }
            write(fin, &space, sizeof(tree));
        }
    }

    close(fin);
    return 0;
}