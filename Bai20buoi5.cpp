#define SIZE 100
#include <stdio.h>
void nhapMang(float a[], int n);
void xuatMang(float a[], int n);
float tongMang(float A[], int n);
float tinhTrungBinhLe(float A[], int n);
int demSoDuong(float A[], int n);
void sapXepTangDan(float A[], int n);
void inGiaTriLe(float A[], int n);
void inViTriSo0(float A[], int n);
float timGiaTriLonNhat(float A[], int n);
int timViTriLonNhatDauTien(float A[], int n);
void inViTriLonNhat(float A[], int n);
int kiemTraToanAm(float A[], int n);






int main()
{
	float A[SIZE];
	int n, kq;
	do
	{
		printf("\nNhap vao so phan tu: ");
		scanf("%d",&n);
		
	}while(n<=0||n>100);
	
	//cau A
	nhapMang(A,n);
	//cau B
	xuatMang(A,n);
	//cau C
	kq = tongMang(A,n);
	printf("\nTong cac gia tri trong mang la %d", kq);
	//cau D
	float trungBinhLe = tinhTrungBinhLe(A,n);
	printf("\nTrung binh cong gia tri le: %.2f",trungBinhLe);
	//cau E
	int soLuongDuong = demSoDuong(A,n);
	printf("\nSo luong phan tu duong: %d",soLuongDuong);
	//cau F
    sapXepTangDan(A, n);
    //cau G
    inGiaTriLe(A, n);
    //cau H
    inViTriSo0(A, n);
    //cau I
    float max = timGiaTriLonNhat(A,n);
    printf("\nGia tri lon nhat trong mang la: %.2f",max);
    //cau J 
    int viTri = timViTriLonNhatDauTien(A, n);
    printf("\nVi tri cua gia tri lon nhat dau tien la: %d", viTri);
    //cau K
    inViTriLonNhat(A,n);
    //cau L
     if (kiemTraToanAm(A, n)) {
        printf("\nMang chi chua so am.");
    } else {
        printf("\nMang co chua so khong am.");
    }
	
	return 0;
 } 

void nhapMang(float A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%f", &A[i]);
    }
}

void xuatMang(float A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", A[i]);
    }
    printf("\n");
}

float tongMang(float A[], int n) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += A[i];
    }
    return tong;
}
float tinhTrungBinhLe(float A[], int n) {
    int dem=0;
	float tong=0;
	for (int i=0;i<n;i++){
		if (i%2!=0){
			dem++;
			tong+=A[i];
		}
	}
	return tong/dem;
}
int demSoDuong(float A[], int n) {
    int dem = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            dem++;
        }
    }

    return dem;
}
void sapXepTangDan(float A[], int n) {
    for (int i=0;i<n-1;i++){
		for (int j=n-1;j>i;j--){
			if (A[j]<A[i]){
				float temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
	}
	printf("\nMang sau khi da sap xep tang dan: \n");
	
	for (int i=0;i<n;i++){
		printf("%.2f ",A[i]);
	}
}
void inGiaTriLe(float A[], int n) {
    printf("\nCac gia tri tap vi tri le la: ");
    for (int i = 1; i < n; i += 2) {
        printf("%.2f ", A[i]);
    }
    printf("\n");
}
void inViTriSo0(float A[], int n) {
    printf("\nCac vi tri co gia tri la 0: ");
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
float timGiaTriLonNhat(float A[], int n) {
    float max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}
int timViTriLonNhatDauTien(float A[], int n) {
    float max = A[0];
    int viTri = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
            viTri = i;
        }
    }

    return viTri;
}
void inViTriLonNhat(float A[], int n) {
    float max = A[0]; 
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    printf("\nCac vi tri co gia tri lon nhat la: ");
    for (int i = 0; i < n; i++) {
        if (A[i] == max) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int kiemTraToanAm(float A[], int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] >= 0) 
            return 0;
        
    }
    return 1;
}
