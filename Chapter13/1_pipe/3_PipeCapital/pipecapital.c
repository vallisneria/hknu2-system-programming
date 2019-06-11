/*
    자식 프로세스에서 임의의 char를 부모프로세스로 보내면
    대문자로 바꾸어 자식 프로세스로 보낸다.

    예를 들어(자식 101, 부모 100)

    PID 101 sent 'a'
    PID 100 received 'a'
    PID 100 sent 'A'
    PID 101 received 'A'
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void sigusr1() {
    // SIGUSR1을 이용해 프로세스간 일이끝났음을 알려줌
}

int main(int argc, char* argv[]) {
    int fd[2];

    if (pipe(fd) != 0) {
        fprintf(stderr, "파이프 생성 오류\n");
        return -1;
    }

    unsigned const int parent_pid = getpid(),
                       child_pid = fork();

    signal(SIGUSR1, sigusr1);

    if (child_pid != 0) {
        // 부모 프로세스
        char receive_message, capitalized_message;

        // 부모는 자식에게 시그널을 받으면 시작한다.
        pause();

        read(fd[0], &receive_message, sizeof(receive_message));
        printf("[%d] received \'%c\'\n", parent_pid, receive_message);
        capitalized_message = receive_message - 32;

        write(fd[1], &capitalized_message, sizeof(capitalized_message));
        printf("[%d] send \'%c\'\n", parent_pid, capitalized_message);

        //부모는 자식에게 받은 문자를 대문자로 만들어서 시그널과 함께 보낸다.
        kill(child_pid, SIGUSR1);
    } else {
        // 자식 클래스
        char send_message = 'a';
        char receive_message;

        write(fd[1], &send_message, sizeof(send_message));
        printf("[%d] sent \'%c\'\n", getpid(), send_message);

        // 자식은 부모에게 시그널을 보내고 멈춘다
        kill(parent_pid, SIGUSR1);
        pause();

        // 부모에게 시그널을 받으면 다시 일한다.
        read(fd[0], &receive_message, sizeof(receive_message));
        printf("[%d] received \'%c\'\n", getpid(), receive_message);
    }

    return 0;
}