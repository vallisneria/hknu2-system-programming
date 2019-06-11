#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    int fp_r, fp_w, j = 2;
    if ((fp_w = open("myPipeAsk", O_WRONLY)) == -1)
        perror("open error");

    if ((fp_r = open("myPipeRpl", O_RDONLY)) == -1)
        perror("open error");

    while (1) {
        write(fp_w, &j, sizeof(int));
        fprintf(stdout, " %d is sended.\n", j);
        read(fp_r, &j, sizeof(int));
        fprintf(stdout, " %d is received.\n", j);
        sleep(3);
    }
}