/*
    2019년 5월 14일
    시스템프로그래밍 실습과제

    실수 20개를 생성하여 파일에 저장하고, 이를 읽어서 출력하는 프로그램 ch11reals.c를 작성하시오.
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "errprint.h"

#define REAL_NUM 20

int main(int argc, char* argv[]) {
    if (argc != 2) {
        errprint("사용 방법: ch11reals [파일]\n");
        return -1;
    }

    const int fin = open(argv[1], O_RDWR);
    double rdNum;
    int i;

    srand(time(NULL));

    for (i = 0; i < REAL_NUM; i++) {
        rdNum = (double)rand() / ((double)rand() + 1);  // 분모가 0이 될 수 없으므로 1을 더해준다.
        write(fin, (char*)&rdNum, sizeof(rdNum));
    }

    i = 0;
    lseek(fin, 0, SEEK_SET);

    do {
        read(fin, (char*)&rdNum, sizeof(rdNum));
        printf("%lf\n", rdNum);
        i++;
    } while (i < REAL_NUM);

    close(fin);
    return 0;
}