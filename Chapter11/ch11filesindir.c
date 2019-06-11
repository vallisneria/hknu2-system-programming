/*
    2019년 5월 23일
    시스템프로그래밍 실습과제

    (11장 69p)
    list2.c를 수정하여 파일의 이름들만 출력하는 프로그램 ch11filesindir.c를 작성한다.
    디렉터리, 문자/블록장치, FIFO, 소켓, 심볼릭링크 등은 출력되지 않고 일반파일만 출력되어야 한다.
*/

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ + 1];

    if (argc == 1) {
        dir = ".";
    } else {
        dir = argv[1];
    }

    if ((dp = opendir(dir)) == NULL) {
        perror(dir);
    }

    while ((d = readdir(dp)) != NULL) {
        sprintf(path, "%s/%s", dir, d->d_name);

        if (lstat(path, &st) < 0) {
            perror(path);
        }

        if (S_ISREG(st.st_mode)) {
            printf("%s\n", d->d_name);
        }
    }
    return 0;
}