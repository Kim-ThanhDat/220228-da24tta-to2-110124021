#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct PHAN_SO{
	int tu, mau;
};
typedef struct PHAN_SO PS;

void nhapPS(PS *a);
void xuatPS(PS a);
void rutgon(PS a);
int ucln(int a, int b);
void cong(PS a, PS b, PS *c);
void tru(PS a, PS b, PS *c);
void nhan(PS a, PS b, PS *c);
void chia(PS a, PS b, PS *c);


int main (){
	PS a, b, c;
	int n;
	
	/*printf("Nhap phan so thu nhat: \n");nhapPS(&a);
	printf("Nhap phan so thu hai: \n");nhapPS(&b);
	printf("Phan so thu nhat: \n");xuatPS(a);
	printf("Phan so thu hai: \n");xuatPS(b);
	printf("Phan so thu nhat sau khi rut gon: \n");rutgon(a);
	printf("Phan so thu hai sau khi rut gon: \n");rutgon(b);
	printf("Tong hai phan so: \n");cong(a, b, &c);
	printf("Hieu hai phan so: \n");tru(a, b, &c);
	printf("Tich hai phan so: \n");nhan(a, b, &c);
	printf("Thuong hai phan so: \n");chia(a, b, &c);*/
	
	printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan so phai lon hon 0.\n");
        return 1;
    }

    PS* p = (PS*)malloc(sizeof(PS) * n);
    

    char path[100];
    printf("\nNhap duong dan can ghi du lieu: ");
    fflush(stdin);
    gets(path);

    FILE* fp = fopen(path, "wt");

    if (fp != NULL) {
        for (int i = 0; i < n; i++) {
            printf("\nNhap phan so thu %d:\n", i + 1);
            nhapPS(&p[i]);

            fprintf(fp, "%d %d\n", p[i].tu, p[i].mau);
        }

        fclose(fp);
        printf("\nGhi du lieu vao file thanh cong!\n");
    } else {
        printf("\nLoi mo file!\n");
    }

    free(p);

    return 0;
}

void nhapPS(PS *a) {
	printf("Nhap tu so: ");
	scanf("%d", &a->tu);
	do{
		printf("Nhap mau so: ");
		scanf("%d", &a->mau);
	}while(a->mau == 0);
}
void xuatPS(PS a) {
	printf("%d/%d", a.tu, a.mau);
}
void rutgon(PS a) {
	int t=ucln(a.tu, a.mau);
	printf("Phan so sau khi rut gon: %d/%d\n", a.tu/t, a.mau/t);
}
int ucln(int a, int b) {
	while(b != 0) {
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
void cong(PS a, PS b, PS *c) {
	c->tu = a.tu * b.mau + b.tu * a.mau;
	c->mau = a.mau * b.mau;
	rutgon(*c);
}
void tru(PS a, PS b, PS *c) {
	c->tu = (a.tu * b.mau) - (b.tu * a.mau);
	c->mau = a.mau * b.mau;
	rutgon(*c);
}
void nhan(PS a, PS b, PS *c) {
	c->tu = a.tu * b.tu ;
	c->mau = a.mau * b.mau;
	rutgon(*c);
}
void chia(PS a, PS b, PS *c) {
	c->tu = a.tu * b.mau;
	c->mau = a.mau * b.tu;
	rutgon(*c);
}
