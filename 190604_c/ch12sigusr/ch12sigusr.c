/*
    2019년 6월 4일 
    시스템프로그래밍 실습과제
    12장 55페이지
    
    시그널 SIGUSR1(10)과 SIGUSR2(12)를 받아 처리하는 프로그램 ch12sigusr.c를 작성한다.

    - 프로그램은 기본적으로 무한 루프를 수행하면서 시그널을 기다린다.
    - SIGUSR1을 받으면 "Oops! SIGUSR1!"을 출력
    - SIGUSR2를 받으면 "Oooooops! SIGUSR2!"를 출력
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// SIGUSR1 시그널을 받으면 할 일
void SIGUSR1_todo() {
    fprintf(stderr, "Oops! SIGUSR1!\n");
}

// SIGUSR2 시그널을 받으면 할 일
void SIGUSR2_todo() {
    fprintf(stderr, "Oooooops! SIGUSR2\n");
    exit(SIGUSR2);
}

int main(int argc, char* argv[]) {
    int pid;
    signal(SIGUSR1, SIGUSR1_todo);
    signal(SIGUSR2, SIGUSR2_todo);

    if ((pid = fork()) == 0) {
        // 자식 프로세스가 실행할 내용
        while (1) {
            //무한 루프
        }
    } else {
        // 부모 프로세스가 실행할 내용
        sleep(2);
        kill(pid, SIGALRM);
    }
}