#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct NGAY_THANG {
    int ngay, thang, nam;
};
typedef struct NGAY_THANG NT;

struct MON_HOC {
    char mamon[15];
    float diem;
};
typedef struct MON_HOC MH;

struct SINH_VIEN {
    char mssv[9], hoten[50], gioitinh[3], diachi[100]; 
    struct NGAY_THANG NT;
    struct MON_HOC MH[10];
    int somon;
};
typedef struct SINH_VIEN SV;

void nhap(SV *a);
void xuat(SV a);
void nhapDSSV(SV* list, int n);
void xuatDSSV(SV* list, int n);

int main () {
    SINH_VIEN *a;
    int n;

    printf("\nNhap vao so luong sinh vien: ");
    scanf("%d", &n);
    
    a = (SV*)malloc(sizeof(SV) * n);
    
    nhapDSSV(a, n);
    xuatDSSV(a, n);
    
    char path[100];
    printf("\nNhap duong dan can ghi du lieu: ");
    fflush(stdin);
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = '\0';
    
    FILE *fp = fopen(path, "wb");
    
    if(fp != NULL) {
        // Ghi du lieu
        fwrite(a, sizeof(SV), n, fp);
        // Dong tap tin
        fclose(fp);
    } else {
        printf("\nLoi mo file!");
    }
    
    free(a);
    return 0;
}

void nhap(SV *a) {
    printf("\nNhap mssv: ");
    fflush(stdin);
    fgets(a->mssv, sizeof(a->mssv), stdin);
    a->mssv[strcspn(a->mssv, "\n")] = '\0';
    
    printf("\nNhap vao ho ten: ");
    fflush(stdin);
    fgets(a->hoten, sizeof(a->hoten), stdin);
    a->hoten[strcspn(a->hoten, "\n")] = '\0';
    
    printf("\nNhap ngay thang nam sinh: ");
    scanf("%d/%d/%d", &a->NT.ngay, &a->NT.thang, &a->NT.nam);
    
    printf("\nNhap gioi tinh cua ban: ");
    fflush(stdin);
    fgets(a->gioitinh, sizeof(a->gioitinh), stdin);
    a->gioitinh[strcspn(a->gioitinh, "\n")] = '\0';

    printf("\nNhap dia chi: ");
    fflush(stdin);
    fgets(a->diachi, sizeof(a->diachi), stdin);
    a->diachi[strcspn(a->diachi, "\n")] = '\0';
    
    printf("\nNhap so mon: ");
    scanf("%d", &a->somon);
    
    printf("\nNhap thong tin cac mon hoc: ");
    for (int i = 0; i < a->somon; i++) {
        printf("\nMon hoc thu %d: ", i + 1);
        printf("\nMa mon hoc: ");
        fflush(stdin);
        fgets(a->MH[i].mamon, sizeof(a->MH[i].mamon), stdin);
        a->MH[i].mamon[strcspn(a->MH[i].mamon, "\n")] = '\0';
        
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
    printf("\nSo mon hoc: %d", a.somon);
    
    printf("\nDanh sach mon hoc: ");
    for (int i = 0; i < a.somon; i++) {
        printf("\nMon %d: %s  Diem: %.2f", i + 1, a.MH[i].mamon, a.MH[i].diem);
    }
}

void nhapDSSV(SV* list, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien tai vi tri %d: ", i + 1);
        nhap(list + i);
    }
}

void xuatDSSV(SV* list, int n) {
    for (int i = 0; i < n; i++) {
        xuat(*(list + i));
        printf("\n");
    }
}

