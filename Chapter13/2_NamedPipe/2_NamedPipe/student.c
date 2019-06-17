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
    printf("연결 성공\n\n");
}

void stdin_clear() {
    char i;
    while ((i = getchar()) != EOF && i != '\n') {
        // 입력버퍼 비우기
    }
}

// 질문을 입력받고 teacher로 보냄
int main(int argc, char* argv[]) {
    // 초기 설정
    int Q_fd_w, A_fd_r, teacher_pid, mypid = getpid();
    char question[BUFSIZ], response[BUFSIZ];
    signal(SIGUSR1, sigusr1);

    // Named Pipe 설정
    mkfifo("QuestionPipe", 0660);
    mkfifo("AnswerPipe", 0660);

    Q_fd_w = open("QuestionPipe", O_WRONLY);
    A_fd_r = open("AnswerPipe", O_RDONLY);

    // 상대 프로세스에게 시그널을 보내기 위한 PID 교환 (생략가능)
    write(Q_fd_w, &mypid, sizeof(int));
    read(A_fd_r, &teacher_pid, sizeof(teacher_pid));

    // 파이프가 제대로 연결되었는지 확인하는 과정 (생략가능)
    // 서로 "연결 성공"이 출력되지 않으면 파이프가 제대로 연결되지 않은 것이다.
    kill(teacher_pid, SIGUSR1);

    printf("파이프를 통한 질문-답변 프로그램.\n");
    printf("질문으로 0을 입력받으면 종료합니다.\n");

    do {
        // 질문을 입력받음
        printf("Q: ");
        scanf("%s", question);

        if (!strcmp(question, "0")) {
            break;
        }

        // 질문을 teacher로 보냄
        write(Q_fd_w, question, strlen(question) + 1);

        // 답변을 받음
        read(A_fd_r, response, BUFSIZ);

        // 그 답변을 출력함
        printf("A: %s", response);

        // 다음 질문을 입력받기 전 입력버퍼를 초기화
        stdin_clear();
    } while (strcmp(question, "0"));

    close(Q_fd_w);
    close(A_fd_r);

    unlink("QuestionPipe");
    unlink("AnswerPipe");

    return 0;
}