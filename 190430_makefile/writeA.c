#include "write.h"
int varAwrite=100;
void writeA()	{
	printf ("Start of writeA()\n");
	printf ("\tvarAwrite %d \n", varAwrite);
	printf ("\tvarBwrite %d \n", varBwrite);
}

main()	{
	writeA();
	writeB();
	rnw1();
	printf ("varAwrite: %d, varBwrite: %d\n", varAwrite, varBwrite);
}

