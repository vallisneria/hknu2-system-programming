#include<stdio.h>
int a, b, c;
int func1(int arg1, int arg2){
	int i;
	for(i=0;i<0xfffff;i++){
		a=2*4;
	}
	return a;
}

inline void func2(){
	int i;
	for(i=0;i<0xfffff;i++){
		b=2*4;
	}
}

int main(){
	int h,j,k,l;
	for(h=0;h<16;h++){
		func1(1,h);
		func2();
	}

	for(h=0;h<16;h++){
		func1(1,h);
		func2();
	}

	for(h=0;h<16;h++){
		c=func1(1,2);
		func2();
	}

	j=0;

	for(h=0;h<0xfffff;h++){
		k=j+1;
		l=k-1;
	}
}
