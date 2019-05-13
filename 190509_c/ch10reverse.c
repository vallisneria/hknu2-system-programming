/*
    2019년 5월 8일
    시스템프로그래밍

    텍스트 파일을 역순으로 출력하는 프로그램 ch10reverse.c를 작성하라.
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    if(argc!=3){
        fprintf(stderr,"사용 방법: ch10reverse [입력파일] [출력파일]\n");
        return 1;
    }

    FILE *fin, *fout;
    char buffer;
    
    fin=fopen(argv[1],"r");
    fout=fopen(argv[2],"w");

    fseek(fin,-1*sizeof(char),SEEK_END);
    while(ftell(fin)!=0){
        fread(&buffer,sizeof(buffer),1,fin);
        fprintf(fout,"%c",buffer);
        fseek(fin,-2*sizeof(buffer),SEEK_CUR);
    }
    fread(&buffer,sizeof(buffer),1,fin);
    fprintf(fout,"%c",buffer);

    fclose(fin);
    fclose(fout);
    return 0;
}
