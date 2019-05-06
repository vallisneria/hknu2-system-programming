/*
    2019년 5월 6일
    시스템프로그래밍 실습과제

    두 개의 파일을 비교하는 프로그램 ch10cmp.c를 작성하라.
    파일 시작부터 비교하면서 달라지는 처음 줄을 출력하라.
    두 파일이 같다면 아무것도 출력하지 않는다.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file1, *file2;
    int line = 1;
    char *file1Contents, *file2Contents;

    if (argc != 3) {
        // 입력된 인수의 개수가 2개가 아닐 경우 오류 메시지 출력
        printf("사용 방법: ch10cmp [file1] [file2]");

        return -1;
    }

    file1 = fopen(argv[1], "r");
    file2 = fopen(argv[2], "r");

    while (1) {
        fgets(file1Contents, 100, file1);
        fgets(file2Contents, 100, file2);

        if (!strcmp(file1Contents, file2Contents)) {
            printf("%s line %d: %s\n", argv[1], line, file1Contents);
            printf("%s line %d: %s\n", argv[2], line, file2Contents);
        }

        if (file1Contents == NULL) {
            printf("%s line %d: %s\n", argv[1], line, "NULL");
            printf("%s line %d: %s\n", argv[2], line, file2Contents);
        } else if (file2Contents == NULL) {
            printf("%s line %d: %s\n", argv[1], line, file1Contents);
            printf("%s line %d: %s\n", argv[2], line, "NULL");
        }
    }
}