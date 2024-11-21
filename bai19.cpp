#define SIZE 100
#include <stdio.h>
#include <math.h>
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int tongMang(int a[], int n);
int tongDuong(int a[], int n);
int tongLe(int a[],int n);
int demSoAm(int a[],int n);
int demSoLe(int a[],int n);
int laSoNguyenTo(int n);
int demSoNguyenTo(int a[], int n);
int timSoNguyenToDauTien(int a[], int n);
void inSoDuongLe(int a[], int n);
int kiemTraSoAm(int a[], int n);
int kiemTraGiaTri(int a[], int n, int x);

int main()
{
	int A[SIZE];
	int n, kq1, kq2, kq3 ;
	
	do
	{
		printf("\nNhap vao so phan tu: ");
		scanf("%d", &n);
	}while(n<=0||n>100);
	
	//n hop le
	//goi ham cau a
	nhapMang(A,n);
	
	//Goi ham cau b
	printf("\nMang vua nhap la: ");
	xuatMang(A,n);
	
	//Goi ham cau c
	kq1 = tongMang(A,n);
	printf("\nTong cac gia tri trong mang la %d", kq1);
	
	//goi ham cau d
	kq2 = tongDuong(A,n);
	printf("\nTong cac gia tri duong trong mang la %d", kq2);
	
	//goi ham cau e
	kq3 = tongLe(A,n);
	printf("\nTong cac gia tri le trong mang la %d", kq3);
	
	//goi ham cau f
	printf("\nSo luong so am vua nhap la :%d ",demSoAm(A,n));
	
	//goi ham cau g
	printf("\nSo luong so le vua nhap la :%d ",demSoLe(A,n));
	
	//goi ham cau h
	printf("\nSo luong SNT vua nhap la :%d ",demSoNguyenTo(A,n));
	
	//goi ham cau i
	printf("\nSo nguyen to dau tien la:%d ",timSoNguyenToDauTien(A,n));
	
	//goi ham cau j 
	printf("\nCac so duong le trong mang la: ");
	inSoDuongLe(A,n);
	
	//goi ham cau k
	if(kiemTraSoAm(A,n)) 
	{
		printf("\nMang A ton tai so am");
	}else{
		printf("\nMang A khong ton tai so am");}
	
	//goi ham cau l
	int x;
	printf("\nNhap gia tri x: ");
    scanf("%d", &x);
	if (kiemTraGiaTri(A, n, x)) {printf("\nGia tri %d co ton tai trong mang.", x);
    	} else {printf("\nGia tri %d khong ton tai trong mang.", x);}
	
	return 0;
}

int kiemTraGiaTri(int a[], int n, int x) {
    int i = 0;
    while (i < n) {
        if (a[i] == x) {
            return 1;
        }
        i++;
    }
    return 0;
}


int kiemTraSoAm(int a[], int n) {
    int i = 0;
    while (i < n) {
        if (a[i] < 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

void inSoDuongLe(int a[], int n) {
    int i = 0;
    
    do {
        if (a[i] > 0 && a[i] % 2 != 0) {
            printf("%d ", a[i]);
        }
        i++;
    } while (i < n);
}

int timSoNguyenToDauTien(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (laSoNguyenTo(a[i])) {
            return a[i];
        }
    }
    return -1;
}

int laSoNguyenTo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int demSoNguyenTo(int a[], int n) {
    int demsnt = 0;
    for (int i = 0; i < n; ++i) {
        if (laSoNguyenTo(a[i])) demsnt++;
    }
    return demsnt;
}

int demSoLe(int a[],int n)
{
	int i= 0,demle=0;
	do
	{
		if (a[i]%2!=0)
		{
			demle++;
		}
		i++;
	}while(i < n);
	return demle;
}

int demSoAm(int a[],int n)
{
	int i =0,demam=0 ;
	do
	{
		if(a[i] < 0)
		{
			demam++;
		}
		i++;
	}while(i<n);
	return demam;
}

int tongLe(int a[],int n)
{
	int i= 1;
	int tongle =0;
	do
	{
		tongle+=a[i];
		i+=2;
	}while (i<n);
	return tongle;
}

int tongDuong(int a[], int n)
{
	int tongduong =0;
	int i= 0;
	do
	{
		if(a[i]> 0)
		{
			tongduong += a[i];
		}
		i++;
	}while ( i<n);
	return tongduong;
}

int tongMang(int a[], int n)
{
	int tong = 0;
	int i=0;
	do
	{
		tong = tong + a[i];
		i++;
	}while(i<=n-1);
	return tong;
}

void xuatMang(int a[], int n)
{
	int i;
	for(i=0; i<=n-1; i++)
	{
		printf("%8d", a[i]);
	}
}
void nhapMang(int a[], int n)
{
	int i;
	
	i = 0;
	while(i<=n-1)
	{
		printf("\nNhap gia tri tai vi tri %d: ", i);
		scanf("%d", &a[i]); //a+i
		i++;
	}
}
