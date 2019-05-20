/*
    2019년 5월 21일
    시스템프로그래밍 실습과제

    명령줄 인수로 파일 이름을 입력받아, group의 permission에 'r'과 'w'를 추가하는 프로그램 ch11chmod2를 작성하라.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "사용 방법: ch11chmod2 [파일+]\n");
        return -1;
    }

    int i;
    int newmode;  // 새로 바꿀 permission
    struct stat inputfile;

    for (i = 1; i < argc; i++) {
        stat(argv[i], &inputfile);

        // 111111111(511)과 비트 and 연산해서 맨 뒤 9자리만 남기기
        newmode = (int)inputfile.st_mode & 0b111111111;

        // 110000(48)과 비트 or 연산해서 group rw 추가하기
        newmode = newmode | 0b110000;

        chmod(argv[i], newmode);

        printf("%s의 permission을 %o으로 변경했습니다.\n", argv[i], newmode);
    }
    return 0;
}