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

// 입력된 char가 특수문자(공백 포함)가 아닌지 체크하는 함수
int isWord(char x){
    switch (x) {
        case ' ':
        case '\n':
        case '\t':
        case '\b':
        case '\r':
        case '\f': return 0;    // false
        default: return 1;      // true
    }
}

// 입력된 char가 특수문자(공백 제외)가 아닌지 체크하는 함수
int isWordAndSpace(char x){
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
    unsigned int cc=0;   // char count
    unsigned int wc=0;   // word count
    unsigned int lc=0;   // line count
    char buf, preBuf;  // buffer

    if(argc>=2){
        // 명령줄 인수가 1개 이상이면
        // 첫번째로 입력한 명령줄 인수를 open
        fin=open(argv[1],O_RDONLY);
    }
    else{
        // 명령줄 인수가 없으면
        // 표준입력
        printf("입력을 종료하려면 [ctrl]+[d](리눅스)를 입력하세요.\n");
        fin=fileno(stdin);
    }
    
    while(read(fin,&buf,sizeof(buf))>0){
        if(isWordAndSpace(preBuf) && !isWordAndSpace(buf)){
            // 이전 char가 (space를 포함한) 특수한 문자가 아니고
            // 이번 char가 (space를 포함한) 특수한 문자이면
            // 단어이므로 wc를 추가함
            wc++;
        }
        else if(buf == '\n'){
            // 이번 char가 '\n'이면
            // 다음 줄로 넘어가므로 lc를 추가함.
            lc++;
        }

        if(isWordAndSpace(buf)){
            // 이번 char가 (공백을 제외한) 특수한 문자가 아닐 경우에는
            // cc도 하나 추가함.
            cc++;
        }
        preBuf=buf;
    }

    
    
    printf("char %d\tword %d\tline %d\n",cc,wc,lc);

    close(fin);
    return 0;
}
