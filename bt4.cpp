#include <stdio.h>
int main(){
	float doanhthu,dongia,ship;
	int soluong;
	printf("Nhap so luong don hang: ");
	scanf("%d",&soluong);
	printf("Nhap don gia: ");
	scanf("%f",&dongia);
	printf("Nhap chi phi ship: ");
	scanf("%f",&ship);
	doanhthu=(float)soluong*dongia-ship;
	printf("\nDoanh thu la: %.2f",doanhthu);
	return 0;
}
