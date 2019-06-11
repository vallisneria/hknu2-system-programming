/*
	10장 20페이지

	파일 추가 프로그램 append.c를 작성한다.

	사용 방법: append file1 file2
	file2의 내용을 file1에 덧붙인다.
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *copyFile, *pasteFile;
    char text;

    copyFile = fopen(argv[2], "r");
    pasteFile = fopen(argv[1], "w");

    while (1) {
        while (fgetc(pasteFile) != EOF) {
        }

        text = fgetc(copyFile);
        fprintf(pasteFile, "%c", text);

        if (text == EOF) {
            break;
        }
    }

    return 0;
}
