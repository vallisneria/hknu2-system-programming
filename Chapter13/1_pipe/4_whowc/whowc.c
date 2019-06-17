#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char line[BUFSIZ];
    FILE *fpin1, *fpin2;

    fpin1 = popen(argv[1], "r");
    fpin2 = popen(argv[2], "w");

    while (fgets(line, BUFSIZ, fpin1)) {
        fputs(line, fpin2);
    }

    pclose(fpin1);
    pclose(fpin2);
    exit(0);
}