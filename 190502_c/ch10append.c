#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *copyFile, *pasteFile;
	char text;
	
	copyFile=fopen(argv[2],"r");
	pasteFile=fopen(argv[1],"w");

	while(1){
		while(fgetc(pasteFile)!=EOF){}

		text=fgetc(copyFile);
		fprintf(pasteFile,"%c",text);

		if(text==EOF){
			break;
		}
	}

	return 0;
}
