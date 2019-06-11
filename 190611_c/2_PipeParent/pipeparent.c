/* 
    부모 프로세스에서 자식 프로세스로
    메시지 "I am your parent"를 보내는 프로그램
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char* argv[]) {
    int pi[2];
    int child_pid;

    if (pipe(pi) != 0) {
        fprintf(stderr, "파이프 생성 오류\n");
        return -1;
    }

    if ((child_pid = fork()) != 0) {
        // 부모 프로세스
        close(pi[0]);
        char* send_message = "I am your child";
        unsigned int length = strlen(send_message) + 1;

        write(pi[1], send_message, length);

        printf("[%d] sent '%s'\n", getpid(), send_message);

        exit(0);
    } else {
        // 자식 프로세스
        close(pi[1]);
        char* receive_message;

        // 자식프로세스가 끝날 때까지 기다린다.
        wait((int*)NULL);
        read(pi[0], receive_message, 100);

        printf("[%d] received '%s'\n", getpid(), receive_message);
    }

    return 0;
}
