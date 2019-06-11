/*
    쉘 인터프리터 interpreter.c를 작성한다. 
    "Type the command: " 라고 나오면 쉘 커멘드를 입력할 수 있다. 
    쉘 커맨드를 입력하면 실행결과가 출력된 후 다시 "Type the command: " 라고 나온다. 
    "Type the command: " 라고 나올 때 "quit"을 입력하면 종료된다. 
    잘못된 쉘커멘드를 입력할 시에도 프로그램이 중단되어서는 안된다. 오류메시지만 출력된 후 "quit"이 입력될 때까지 계속되어야 한다. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    printf("인수가 1개인 명령만 실행할 수 있습니다.\n");
    char command[BUFSIZ];
    int i;

    while (1) {
        printf("Type the command: ");
        scanf(" %s", command);

        if (0 == strcmp(command, "quit")) {
            break;
        } else if (!fork()) {
            execlp(command, command, NULL);
            fprintf(stderr, "그런 명령어는 존재하지 않습니다\n");
            return 0;
        }
        wait((int*)NULL);

        while ('\n' != getchar()) {
        }  //입력버퍼 비우기
    }

    return 0;
}