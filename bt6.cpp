#include <stdio.h>
int main (){
	int a=5, b=6;
	float x=a/b;
	printf("x=%d",x);
	x = (float)a/b;
	printf("\nx=%f",x);
	return 0;
}
