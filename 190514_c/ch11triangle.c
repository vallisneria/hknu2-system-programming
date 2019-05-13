/*
    2019년 05월 13일
    시스템프로그래밍 실습과제

    파일에 직각삼각형을 출력하는 프로그램 ch11triangle.c를 작성하시오.
    가로 및 세로의 길이는 19로 한다.
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "errprint.h"

#define MAXLINE 19

int main(int argc, char* argv[]) {
    if (argc != 2) {
        errprint("사용 방법: ch11triangle [파일명]\n");
        return -1;
    }

    const int fin = open(argv[1], O_WRONLY);
    const char tri = '$';
    const char ent = '\n';

    for (int i = 0; i < MAXLINE; i++) {
        for (int j = 0; j < i; j++) {
            write(fin, &tri, sizeof(tri));
        }
        write(fin, &ent, sizeof(ent));
    }

    close(fin);

    return 0;
}