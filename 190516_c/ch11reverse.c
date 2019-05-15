/*
    2019년 5월 16일
    시스템프로그래밍 실습과제

    텍스트 파일의 줄들을 역순으로 바꾸어 파일로 출력하는 프로그램 ch11reverse.c를 작성하여라.
    첫 줄이 마지막 줄이 되고 마지막 줄이 첫줄이 되어야 한다.
*/

#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용 방법: ch11reverse [in] [out]");
        return -1;
    }

    const int fin = open(argv[1], O_RDONLY);
    const int fout = creat(argv[2], O_WRONLY);
    char* buf;

    lseek(fin, 0, SEEK_END);

    do {
        lseek(fin, -1 * sizeof(buf), SEEK_CUR);
        read(fin, buf, sizeof(buf));
        lseek(fin, -1 * sizeof(buf), SEEK_CUR);
        
    } while (1);
}