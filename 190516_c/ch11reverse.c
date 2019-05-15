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
        fprintf(stderr, "사용 방법: ch11reverse [in] [out]\n");
        return -1;
    }

    int fin = open(argv[1], O_RDONLY);
    int fout = creat(argv[2], O_WRONLY);
    char ent = '\n';
    char buf, lbuf[BUFSIZ];
    int i = 0, j = 0;
    long isFilehead = 0;

    lseek(fin, -1 * sizeof(buf), SEEK_END);  // 파일 포인터를 맨 뒤에서 한 칸 앞으로 옮긴다

    do {
        read(fin, &buf, sizeof(buf));  // 한 단어를 읽는다
        lbuf[i] = buf;                 // 읽은 단어를 배열에 저장한다.
        i++;

        if (buf == '\n') {  // 만약 '\n'을 읽었을 경우
            for (j = i - 1; j >= 0; j--) {
                write(fout, &(lbuf[j]), sizeof(char));  // 배열 한 칸씩 파일에 쓴다.
            }
            write(fout, &ent, sizeof(ent));  // 마지막줄에는 '\n'을 입력한다.
            i = 0;                           // i를 0으로 초기화
        }

        isFilehead = lseek(fin, -2 * sizeof(buf), SEEK_CUR);
        printf("isFilehead=%d, buf=%c\n", isFilehead, buf);
    } while (isFilehead != -1);

    for (j = i - 1; j >= 0; j--) {
        write(fout, &(lbuf[j]), sizeof(char));
    }

    close(fin);
    close(fout);

    return 0;
}