#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include "ch12sleep.h"

int main(int argc, char* argv[]) {
    printf("sleep 시작\n");
    ch12sleep(2);
    printf("sleep 종료\n");
    return 0;
}
