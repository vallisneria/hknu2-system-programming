#include "read.h"
int varBread;
void readB() {
	printf("Start of readB():\n");
	printf("\tType varBread: ");
	scanf("%d", &varBread);
}
main()	{

	readA();
	readB();
	printf("-----varAread: %d varBread: %d\n", varAread, varBread);
}

