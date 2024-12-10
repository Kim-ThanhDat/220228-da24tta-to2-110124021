#include<stdio.h>
#include<string.h>


struct NGAY_THANG{
	int ngay, thang, nam;
};
typedef struct NGAY_THANG NT;
struct MON_HOC{
	char mamon[15];
	float diem;
};
typedef struct MON_HOC MH;
struct SINH_VIEN{
	char mssv[9], hoten[50], gioitinh[3], diachi[100]; 
	struct NGAY_THANG NT;
	struct MON_HOC MH[10];
	int somon;
};
typedef struct SINH_VIEN SV;
void nhap(SV *a);
void xuat(SV a);
int main () {
	SINH_VIEN a;
	
	nhap(&a);
	xuat(a);
	return 0;
}
void nhap(SV *a) {
	printf("\nNhap mssv: ");
	fflush(stdin);
	gets(a->mssv);
	
	printf("\nNhap vao ho ten: ");
	fflush(stdin);
	gets(a->hoten);
	
	printf("\nNhap ngay thang nam sinh: ");
	scanf("%d/%d/%d", &a->NT.ngay, &a->NT.thang, &a->NT.nam);
	
	printf("\nNhap gioi tinh cua ban: ");
	fflush(stdin);
	gets(a->gioitinh);

	printf("\nNhap dia chi: ");
	fflush(stdin);
	gets(a->diachi);
	
	printf("\nNhap so mon: ");
	scanf("%d", &a->somon);
	
	printf("\nNhap thong tin cac mon hoc: ");
	for (int i=0; i<a->somon; i++) {
		printf("\nMon hoc thu %d: ",i+1);
		printf("\nMa mon hoc: ");
		fflush(stdin);
		gets(a->MH[i].mamon);
		printf("Diem: ");
		scanf("%f", &a->MH[i].diem);
	}
}
void xuat(SV a) {
	printf("\nMssv: %s", a.mssv);
	printf("\nHo ten: %s", a.hoten);
	printf("\nNgay sinh: %d/%d/%d", a.NT.ngay, a.NT.thang, a.NT.nam);
	printf("\nGioi tinh: %s", a.gioitinh);
	printf("\nDia chi: %s", a.diachi);
	printf("\nSo mon hoc: %d",a.somon);
	
	printf("\nDanh sach mon hoc: ");
	for (int i=0; i<a.somon; i++) {
		printf("\nMon %d: %s  Diem: %.2f", i+1, a.MH[i].mamon, a.MH[i].diem);
	}
	
}

