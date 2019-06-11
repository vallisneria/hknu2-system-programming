/*
    2019년 5월 7일
    시스템프로그래밍 실습과제

    입력파일의 홀수 줄만을 출력파일에 저장하는 프로그램 ch10cp.c를 작성하라.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        //입력된 인수가 2개가 아닐 경우 다음과 같은 오류 메시지 출력
        printf("사용 방법: ch10cp [file1] [file2]\n");

        return -1;
    }

    FILE *fin, *fout;
    int line = 1;
    char lineContents[100];

    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    while (1) {
        if (line % 2 == 1) {
            // fin 파일에서 한줄(최대 100글자)를 읽어 lineContents에 저장
            fgets(lineContents, 100, fin);

            line++;

            if (strcmp(lineContents, NULL)) {
                // 만약 lineContents에 NULL이 저장되어 있으면
                // 마지막 줄이므로 while문을 빠져나간다
                break;
            }

            // lineContents에 저장된 문자열을 fout 파일에 출력
            fputs(lineContents, fout);
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}