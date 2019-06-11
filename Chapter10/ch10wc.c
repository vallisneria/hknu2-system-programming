/*
	10장 18페이지
	명령줄 인수로 받은 텍스트 파일 내의 문자의 수와 줄의 수를
	출력하는 프로그램 ch10wc.c를 작성한다.
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *inFile;
    int word = 0, line = 0;
    char read;
    inFile = fopen(argv[1], "r");

    while (1) {
        read = fgetc(inFile);
        if (read == EOF) {
            break;
        }

        else if (read != '\n') {
            word++;
        }

        else if (read == '\n') {
            line++;
        }
    }

    fclose(inFile);

    printf("%d char, %d line\n", word, line);

    return 0;
}
