/*
    2019년 5월 16일
    시스템프로그래밍 실습과제

    명령줄 인수로 받은 파일의 소유자와 그룹의 이름을 프린트하는 프로그램 ch11lstate.c를 작성하여라.

    - 명령줄 인수로 한 개 이상의 파일을 받을 수 있어야 한다.
    - getpwuid()와 getgrgid()를 사용하라.
*/

#include <fcntl.h>
#include <grp.h>
#include <pwd.h>  // 이 둘은 windows에서는 include할 수 없음
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "사용 방법: ch11lstate [file]+");
        return -1;
    }

    int i;
    int fin;
    struct stat info;
    struct passwd *user;
    struct group *gr;

    for (i = 0; i < argc - 1; i++) {
        printf("파일 이름: %s\n", argv[i + 1]);
        stat(argv[i + 1], &info);
        user = getpwuid(info.st_uid);
        gr = getgrgid(info.st_gid);
        printf("user: %s\ngroup: %s\n", user->pw_name, gr->gr_name);
    }

    return 0;
}