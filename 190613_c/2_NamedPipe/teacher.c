/*
    teacher.c와 student.c를 작성하여 질문과 답변을 할 수 있게 한다.
    student가 질문을 적어 보내면 teacher는 답변을 student에게 보낸다.
*/

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void sigusr1() {
    static int connection = 1;
    printf("연결 성공\n\n");
}

// 답변을 받아서 question으로 보냄
int main(int argc, char* argv[]) {
    // 초기 설정
    int Q_fd_r, A_fd_w, Question_pid;
    char question[BUFSIZ], response[BUFSIZ];
    signal(SIGUSR1, sigusr1);

    // Named Pipe 설정
    unlink("Question");
    unlink("Answer");

    mkfifo("Question", 0660);
    mkfifo("Answer", 0660);

    Q_fd_r = open("Question", O_WRONLY);
    A_fd_w = open("Question", O_RDONLY);

    // 상대 프로세스에게 시그널을 보내기 위한 PID 교환 작업 (생략가능)
    write(A_fd_w, getpid(), sizeof(int));
    read(Q_fd_r, &Question_pid, sizeof(Question_pid));

    // 파이프가 제대로 연결되었는지 확인하는 과정 (생략가능)
    // 서로 "연결 성공"이 출력되지 않으면 파이프가 제대로 연결되지 않은 것이다.
    kill(Question_pid, SIGUSR1);

    do {
        // 질문을 받음
        read(Q_fd_r, question, BUFSIZ);

        // 미리 입력해둔 질문들에서 적절한 답변을 찾음
        if (question == "Hello") {
            strcpy(response, "World!");
        } else if (question == "Your name") {
            strcpy(response, *argv[0]);
        } else if (question == "the answer to life the universe and everything") {
            strcpy(response, "42");
        } else if (question == "0") {
            //종료
        } else {
            strcpy(response, "what?");
        }

        // 답변을 보냄
        write(A_fd_w, response, strlen(response) + 1);
    } while (question != 0);

    close(Q_fd_r);
    close(A_fd_w);

    return 0;
}