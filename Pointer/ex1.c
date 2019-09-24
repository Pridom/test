#include <stdio.h>

//uses of const

int main(){
	int a = 20;
	const int * ptr = &a;

	printf("value: %d \n", *ptr);
//	*ptr = 40;  the code will not be executed since the pointer is
//	            constant - the value of it can't be changed
	printf("value: %d \n", *ptr);

	return 0;
}



