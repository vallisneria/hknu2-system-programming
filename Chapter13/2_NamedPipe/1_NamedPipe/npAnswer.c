/*
    npQuestioner에서 npAnswerer로 숫자를 보내면 3을 더해서 돌려준다. 
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
    int question, response, Q_fd_r, A_fd_w, Question_pid, mypid = getpid();
    signal(SIGUSR1, sigusr1);

    // Named Pipe 설정
    mkfifo("QuestionPipe", 0660);
    mkfifo("AnswerPipe", 0660);

    Q_fd_r = open("QuestionPipe", O_RDONLY);
    A_fd_w = open("AnswerPipe", O_WRONLY);

    // 상대 프로세스에게 시그널을 보내기 위한 PID 교환 작업 (생략가능)
    write(A_fd_w, &mypid, sizeof(int));
    read(Q_fd_r, &Question_pid, sizeof(Question_pid));

    // 파이프가 제대로 연결되었는지 확인하는 과정 (생략가능)
    // "연결 성공"이 출력되지 않으면 파이프가 제대로 연결되지 않은 것이다.
    kill(Question_pid, SIGUSR1);
    sleep(1);

    do {
        // 질문을 받음
        read(Q_fd_r, &question, BUFSIZ);
        printf("질문을 받음: %d\n", question);

        // 계산함
        response = question + 3;

        // 답변을 보냄
        write(A_fd_w, &response, sizeof(int));
        printf("답변을 보냄: %d\n", response);
    } while (question != 0);

    close(Q_fd_r);
    close(A_fd_w);

    unlink("QuestionPipe");
    unlink("AnswerPipe");

    return 0;
}
