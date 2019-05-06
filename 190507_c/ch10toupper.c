/*
    2019년 5월 7일
    시스템프로그래밍 실습과제

    소문자를 모두 대문자로 변경하는 프로그램 ch10toupper.c를 작성하시오.
*/

#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용 방법: ch10toupper [inputfile] [outputfile]\n");

        return -1;
    }

    FILE *fin, *fout;
    char contents;

    fin = fopen(argv[1], "rb");
    fout = fopen(argv[2], "wb");

    while (1) {
        fread(contents, sizeof(char), 1, fin);

        if (contents == NULL) {
            // 파일의 끝에 도달하면 while문을 나감
            break;
        }

        if (contents >= 97) {
            // contents가 97(a)보다 크거나 같으면
            // 대문자로 만든다.
            contents = toupper(contents);
        }

        fwrite(contents, sizeof(char), 1, fout);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}