/*
    2019년 5월 8일
    시스템프로그래밍

    명령줄 인수로 받은 텍스트 파일 내의 문자의 수와 단어의 수를
    출력하는 프로그램인 ch11wc.c를 작성한다.

    명령줄 인수가 없는 경우에는 표준입력에서 받은 내용을 대상으로 한다.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// 입력된 char가 단어인지 체크하는 함수
int isWord(char x){
    switch (x) {
        case '\n':
        case '\t':
        case '\b':
        case '\r':
        case '\f': return 0;    // false
        default: return 1;      // true
    }
}

int main(int argc, char* argv[]){
    int fin;    // file input
    int cc=0;   // char count
    int wc=0;   // word count
    int lc=0;   // line count
    char buf;
    fin=open(argv[1],O_RDONLY);
    
    while(read(fin,&buf,sizeof(buf))){
        if(buf==' '){
            // 띄어쓰기가 나오면 한 단어가 끝난 것이므로 wc를 하나 추가함.
            wc++;
        }
        else if(buf == '\n'){
            // '/n'가 나오면 한 줄을 끝내고
            // 다음줄로 넘어가기 때문에 lc를 하나 추가함.
            lc++;
        }
        else if(!isWord(buf)){
            // 나머지 경우(특수한 문자가 아닐 경우)에는
            // cc를 하나 추가함.
            cc++;
        }
    }

    lc++;
    wc++;
    printf("char %d\tword %d\tline %d\n",cc,wc,lc);

    return 0;
}