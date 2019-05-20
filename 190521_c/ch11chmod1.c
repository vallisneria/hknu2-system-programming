/*
    2019년 5월 21일
    시스템프로그래밍 실습과제

    명령줄 인수로 파일 이름을 입력받아, owner의 permission에 'x'를 추가하는
    프로그램 ch11chmod1을 작성하라
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "사용 방법: ch11chmod1 [파일+]");
        return -1;
    }
    int i;
    int chper;  // 변경할 permission
    struct stat inputfile;

    for (i = 0; i < argc - 1; i++) {
        stat(argv[i], &inputfile);

        // 원래 파일의 permission과 001000000을 비트 or 연산해서 owner x를 추가함
        chper = strtol((const char *)inputfile.st_mode, (char **)NULL, 8) | (001000000);

        chmod(argv[i], chper);
    }

    return 0;
}