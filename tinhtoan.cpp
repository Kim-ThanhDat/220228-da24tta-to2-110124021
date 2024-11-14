#include <stdio.h>
int main(){
	int n;long long p=1, s=0;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<=0);
	s=(n+1)*n/2;
	for (int i=1;i<=n;i++){
		p*=i;
	}
	printf("tong la: %lld",s);
	printf("\ntich la: %lld",p);
	return 0;
}
