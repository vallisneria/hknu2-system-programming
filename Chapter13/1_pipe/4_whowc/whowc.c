/*
    who 명령의 출력을 입력으로 받아서 wc하여 표준출력으로 출력하는 프로그램 whowc.c

    - fork()를 사용하여 자식 프로세스를 만들고 부모와 자식프로세스에 각각 dup2를 적용하여 파이프로 연결한다.
    - 쉘명령어 who|wc와 같은 출력을 내는지 확인하라.
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char* argv[]) {
    int fd[2];
    unsigned int who_pid, wc_pid, parent_pid = getpid();
    pipe(fd);

    if (who_pid = fork()) {
        // 부모 프로세스
        close(fd[1]);
        char* receive_message;
        read(fd[0], receive_message, 100);

        printf("%s\n%ld", receive_message, strlen(receive_message));

    } else {
        // 자식(who) 프로세스
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);

        execlp("who", "who", NULL);
        fprintf(stderr, "그런 파일은 존재하지 않습니다.\n");
    }
}