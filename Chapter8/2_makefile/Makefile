all:write_only read_n_write read_only

write_only:writeA.o writeB.o rnw1.o
	gcc -o write_only writeA.o writeB.o rnw1.o

writeA.o:writeA.c write.h
	gcc -c writeA.c

writeB.o:writeB.c write.h rnw.h
	gcc -c writeB.c


read_n_write:writeB.o rnw1.o rnw2.o readA.o
	gcc -o read_n_write writeB.o rnw1.o rnw2.o readA.o

rnw1.o:rnw1.c rnw.h
	gcc -c rnw1.c

rnw2.o:rnw2.c rnw.h
	gcc -c rnw2.c


read_only:readA.o readB.o
	gcc -o read_only readA.o readB.o

readA.o:readA.c rnw.h read.h
	gcc -c readA.c

readB.o:readB.c read.h
	gcc -c readB.c
