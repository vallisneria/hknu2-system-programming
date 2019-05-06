#include "rnw.h"
int var2rw=10000;
void rnw2()	{
	printf ("Start of rnw2()\n");
	printf ("\tType var2rw:");
	scanf ("%d", &var2rw);
	printf ("\tvar2rw: %d\n", var2rw);
}
main()	{
	writeB();
	rnw1();
	rnw2();
	readA();
	printf ("var1rw: %d, var2rw: %d\n", var1rw, var2rw);
}

