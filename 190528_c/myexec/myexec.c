/*
    myprog1과 myprog2를 만든 후 지시에 따라 myexec.c를 작성하시오

    - myexec의 사용법은 "myexec[a|b]"이다. 즉, 입력으로 a또는 b를 받는다.

    - 파라미터로 a를 입력하면 "myprog1 14"를 수행하되 execl()함수를 사용한다.

    - 파라미터로 b를 입력하면 "myprog2 12"를 수행하되 execlp()함수를 사용한다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (*argv[1] != 'a' && *argv[1] != 'b') {
        fprintf(stderr, "사용법: myexec [a|b]\n");
    }

    if (*argv[1] == 'a') {
        if (!fork()) {
            execl("./myprog1", "myprog1", "14", NULL);
            exit(0);
        }
    } else if (*argv[1] == 'b') {
        if (!fork()) {
            execlp("./myprog2", "myprog2", "12", NULL);
            exit(0);
        }
    }

    exit(0);
}