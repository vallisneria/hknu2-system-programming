/*
    2019년 5월 8일
    시스템프로그래밍

    텍스트 파일을 역순으로 출력하는 프로그램 ch10reverse.c를 작성하라.
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    if(argc!=3){
        fprintf(stderr,"사용 방법: ch10reverse [입력파일] [출력파일]");
        return 1;
    }

    FILE *fin, *fout;
    char* buffer;
    
    fin=fopen(argv[1],"r");
    fout=fopen(argv[2],"w");

    fseek(fin,0,SEEK_END);
    do{
        fseek(fin,-1*sizeof(char),SEEK_CUR);
        fread(buffer,sizeof(char),1,fin);
        fprintf(fout,"%c",buffer);
    }while(ftell(fin)!=SEEK_SET);

    fclose(fin);
    fclose(fout);
}