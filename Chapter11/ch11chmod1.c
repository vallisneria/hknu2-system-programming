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
    int newmode;  // 변경할 permission
    struct stat inputfile;

    for (i = 1; i < argc; i++) {
        stat(argv[i], &inputfile);
        printf("%d\n", inputfile.st_mode);

        // 511(111111111)과 비트 and 연산해서 맨 뒤 9자리(permisson)만 뽑아냄
        newmode = (int)inputfile.st_mode & 0b111111111;
        printf("%d\n", newmode);

        // 원래 파일의 permission과 64(001000000)을 비트 or 연산해서 owner x를 추가함
        newmode = newmode | 0b001000000;

        printf("%d", newmode);

        chmod(argv[i], newmode);
    }

    return 0;
}