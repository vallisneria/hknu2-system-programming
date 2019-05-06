#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *inFile;
	int word=0, line=0;
	char read;
	inFile=fopen(argv[1],"r");

	while(1){
		read=fgetc(inFile);
		if(read==EOF){
			break;
		}

		else if(read!='\n'){
			word++;
		}

		else if(read=='\n'){
			line++;
		}
	}

	fclose(inFile);

	printf("%d char, %d line\n", word, line);

	return 0;
}
