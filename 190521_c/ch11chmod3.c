/*
    2019년 5월 21일
    시스템프로그래밍 실습과제

    명령줄 인수로 permission과 파일 이름을 입력받아,
    그 파일의 permission을 변경하는 프로그램 ch11chmod3을 작성하라.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "charTypePerm.h"

int main(int argc, char* argv[]) {
    if (argc <= 2 && argc % 2 == 0) {
        fprintf(stderr, "사용 방법: ch11chmod3 [permission] [file] ...");
        return -1;
    }

    int i;
    int newperm;
    struct stat inputfile;

    for (i = 1; i < argc; i += 2) {
        stat(argv[i + 1], &inputfile);
        newperm = (int)inputfile.st_mode & 0b111111111;

        newperm = charTypePerm(newperm, argv[i]);
        chmod(argv[i + 1], newperm);

        printf("파일 %s의 권한을 %o로 변환했습니다.\n", argv[i + 1], newperm);
    }

    return 0;
}