/*
    부모가 자식 둘을 생성하고, 각 자식은 다시 자식 둘을 생성하는 프로그램 ch12fork.c를 작성하라

    - 부모는 자식 둘을 생성한 후,
      I am a parent(pid). I created two children!을 출력하고 종료한다.

    - 각 자식은 손자 둘을 생성한 후,
      I am a child(pid). I created two grandchildren!을 출력하고 종료한다.

    - 각 손자는 I am a grandchild(pid). I do not creat any descendant!를 출력하고 종료한다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    short i;

    for (i = 0; 0 != fork() && i < 2; i++) {
        if (i == 1) {
            // 자식 프로세스 2개를 생성하면 아래 문장을 출력하고 나감
            printf("I am a parent(%d). I created two children!\n", getpid());
            exit(0);
        }
    }

    for (i = 0; 0 != fork() && i < 2; i++) {
        if (i == 1) {
            printf("I am a child(%d). I created two grandchildren!\n", getpid());
            exit(0);
        }
    }

    printf("I am a grandchild(%d). I do not creat any descendent!\n", getpid());
    exit(0);
}