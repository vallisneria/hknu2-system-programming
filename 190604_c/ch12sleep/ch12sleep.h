/*
    2019년 6월 4일
    시스템프로그래밍 실습과제
    12장 49페이지

    함수 ch12sleep()을 구현한 후 메인 함수에서 테스트하라.
    ch12sleep()은 기존 함수 sleep()와 매우 유사하나 sleep()을 쓰지 않고 직접 구현해야 한다.

    - ch12sleep()은 현재 프로세스를 second 초 동안 중지시킨다.
    - alarm()과 pause() 시스템 호출을 이용한다.
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

// 정지한 시간을 return 한다.
unsigned int ch12sleep(unsigned int second) {
    if (fork() == 0) {
        // 자식 프로세스가 진행할 내용
        alarm(second);
        pause();

    } else {
        // 부모 프로세스가 진행할 내용
        wait((int*)NULL);

        // 자식 프로세스가 알람을 울리면 함수를 종료한다.
        return second;
    }
}