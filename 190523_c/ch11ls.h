#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

char type(mode_t);
char typeF(mode_t);
char* perm(mode_t);
void printStat(char*, char*, struct stat*);
int option[3] = {0, 0, 0};  // [s][n][F]

void printStat(char* pathname, char* file, struct stat* st) {
    if (option[0]) {                                            // s옵션이 있으면
        printf("%ld ", st->st_blocks / 2);                      // 파일의 byte수를 출력
    }                                                           //
                                                                //
    if (option[1]) {                                            // n옵션이 있으면
        struct tm* time;                                        // time 구조체 선언
        time = localtime(&(st->st_ctime));                      // 초를 localtime으로 변환
        printf("%c%s ", type(st->st_mode), perm(st->st_mode));  // 파일의 타입과 권한을 출력
        printf("%ld ", st->st_nlink);                           // 파일의 링크 수를 출력
        printf("%d %d ", st->st_uid, st->st_gid);               // 파일의 소유자와 그룹 ID를 출력
        printf("%ld ", st->st_size);                            // 파일의 크기를 출력
        printf("%d월 %d일 ", time->tm_mon, time->tm_mday);      // 파일의 마지막 수정 날짜를 출력
        printf("%d:%d", time->tm_hour, time->tm_min);           // 파일의 마지막 수정 시간을 출력
    }                                                           //
                                                                //
    printf("%s", file);                                         // 파일의 이름을 출력
                                                                //
    if (option[2]) {                                            // -F 옵션이 있으면
        printf("%c", typeF(st->st_mode));                       // 파일 형식을 알리는 문자 추가
    }

    printf("\n");
}

char type(mode_t mode) {
    if (S_ISREG(mode)) {
        return '-';
    } else if (S_ISDIR(mode)) {
        return 'd';
    } else if (S_ISCHR(mode)) {
        return 'c';
    } else if (S_ISBLK(mode)) {
        return 'b';
    } else if (S_ISLNK(mode)) {
        return 'l';
    } else if (S_ISFIFO(mode)) {
        return 'p';
    } else if (S_ISSOCK(mode)) {
        return 's';
    }
}

char typeF(mode_t mode) {
    if (S_ISDIR(mode)) {
        return '/';
    } else if ((0b001000000) & mode) {
        return '*';
    } else if (S_ISLNK(mode)) {
        return '@';
    } else if (S_ISFIFO(mode)) {
        return '|';
    } else if (S_ISSOCK(mode)) {
        return '=';
    }
}

char* perm(mode_t mode) {
    int i;
    static char perms[10];
    strcpy(perms, "---------");

    for (i = 0; i < 3; i++) {
        if (mode & (0b100000000 >> i * 3)) {
            perms[i * 3] = 'r';
        }
        if (mode & (0b010000000 >> i * 3)) {
            perms[i * 3 + 1] = 'w';
        }
        if (mode & (0b001000000 >> i * 3)) {
            perms[i * 3 + 2] = 'x';
        }
    }
    return perms;
}
