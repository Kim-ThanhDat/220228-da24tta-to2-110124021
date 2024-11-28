#define COL 100
#define ROW 100
#include <math.h>
#include <stdio.h>
void nhapMang(int a[][COL],int m, int n);
void xuatMang(int a[][COL],int m, int n);
int tongMang(int a[][COL], int m, int n);
int tongDong(int a[][COL], int m, int n, int k);
int tongCot(int a[][COL], int m, int n, int k);
int ktrSoAmDong(int a[][COL], int m, int n, int k);
int kiemTraSoNguyenToTrongCot(int a[][COL], int m, int n, int k),laSoNguyenTo(int n) ;
void sapXepGiamDanDong(int a[][COL], int m, int n, int k);
int kiemTraCotToanSoLe(int a[][COL], int m, int n, int k);
int kiemTraTonTai(int a[][COL], int m, int n, int x);
void timViTri(int a[][COL], int m, int n, int x); 
int timGiaTriLonNhatTrenDong(int a[][COL], int m, int n, int k); 
int timGiaTriNhoNhatTrenDong(int a[][COL], int m, int n, int k); 
void inSoNguyenToTrenDong(int a[][COL], int m, int n, int k);
int kiemTraSoNguyenTo(int n);


int main()
{
	int a[COL][ROW];
	int m,n,k,x;
	//m la dong
	printf ("Nhap so dong: ");
	scanf("%d",&m);
	//n la cot
	printf("Nhap so cot: ");
	scanf("%d",&n);
	
	nhapMang(a, m, n);//cau A
	xuatMang(a, m, n);//cau B
	//cau C
	int tong=tongMang(a, m, n);
	printf("Tong cua mang la: %d\n", tong);
	//cau D
	printf("Nhap vi tri dong can tinh tong(0<=k<%d): ",m);
	scanf("%d",&k);
	
	int tongdong=tongDong(a, m, n, k);
	if (tongdong != -1){
			printf("Tong cac gia tri tren dong %d la: %d\n",k ,tongdong);

	}
	//cau E
	printf("Nhap vi tri cot can tinh tong(0<=k<%d): ",n);
	scanf("%d",&k);
	
	int tongcot=tongCot(a, m, n, k);
	if (tongcot != -1){
			printf("Tong cac gia tri tren cot %d la: %d\n",k ,tongcot);
	}
	//cau F
	printf("Nhap vi tri dong can kiem tra(0<=k<%d): ",m);
	scanf("%d",&k);
	int coSoAm = ktrSoAmDong(a, m, n, k);
	if (coSoAm == -1) {
			printf("Vi tri dong khong hop le!\n");
	}else if (coSoAm == 1) {
		printf("Dong %d co chua so am.\n",k);
	}else {
			printf("Dong %d khong chua so am.\n",k);
	}
	//cau G
	printf("Nhap vi tri cot can kiem tra (0 <= k < %d): ", n);
	scanf("%d", &k);
	
	int coSoNguyenTo = kiemTraSoNguyenToTrongCot(a, m, n, k);
	if (coSoNguyenTo == -1) {
    printf("Vi tri cot khong hop le!\n");
	} else if (coSoNguyenTo == 1) {
    	printf("Cot %d co chua so nguyen to.\n", k);
	} else {
    	printf("Cot %d khong co so nguyen to.\n", k);
	}
	//cau H
	printf("Nhap vi tri dong can sap xep (0 <= k < %d): ", m);
	scanf("%d", &k);

	sapXepGiamDanDong(a, m, n, k);
	printf("Mang sau khi sap xep:\n");
	xuatMang(a, m, n);
	//cau I
	printf("Nhap vi tri cot can kiem tra (0 <= k < %d): ", n);
	scanf("%d", &k);

	int ketQua = kiemTraCotToanSoLe(a, m, n, k);
	if (ketQua == -1) {
    	printf("Vi tri cot khong hop le!\n");
	} else if (ketQua == 1) {
    	printf("Cot %d toan so le.\n", k);
	} else {
    	printf("Cot %d khong toan so le.\n", k);
	}
	//cau J
	 printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    if (kiemTraTonTai(a, m, n, x)) {
        printf("Gia tri %d co ton tai trong mang.\n", x);
    } else {
        printf("Gia tri %d khong ton tai trong mang.\n", x);
    }
    //cau K
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    timViTri(a, m, n, x);
    //cau L
    printf("Nhap vi tri dong can tim gia tri lon nhat (0 <= k < %d): ", m);
	scanf("%d", &k);

	int giaTriLonNhat = timGiaTriLonNhatTrenDong(a, m, n, k);
	if (giaTriLonNhat != -1) {
    	printf("Gia tri lon nhat tren dong %d la: %d\n", k, giaTriLonNhat);
	}
	//cau M
	printf("Nhap vi tri dong can tim gia tri nho nhat (0 <= k < %d): ", m);
	scanf("%d", &k);

	int giaTriNhoNhat = timGiaTriNhoNhatTrenDong(a, m, n, k);
	if (giaTriNhoNhat != -1) {
    	printf("Gia tri nho nhat tren dong %d la: %d\n", k, giaTriNhoNhat);
	}
	//cau N
	printf("Nhap vi tri dong can in cac so nguyen to (0 <= k < %d): ", m);
	scanf("%d", &k);

	inSoNguyenToTrenDong(a, m, n, k);
			
	return 0;
}
void nhapMang(int a[][COL],int m, int n)//cau A
{
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("Nhap phan tu a[%d][%d]: ", i, j);
			scanf ("%d", &a[i][j]);
		}
	}
}
void xuatMang(int a[][COL],int m, int n)//cau B
{
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}
int tongMang(int a[][COL], int m, int n)//cau C
{
	int tong = 0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			tong+= a[i][j];
		}
	}
	return tong;
}
int tongDong(int a[][COL], int m, int n, int k)//cau D
{
	if (k<0||k>=m){
		printf("Vi tri dong khong hop le!\n");
		return -1;
	}
	int tongdong =0;
	for (int j=0; j<n; j++){
		tongdong += a[k][j];
	}
	return tongdong;
}
int tongCot(int a[][COL], int m, int n, int k)//cau E
{
	if (k<0||k>=n){
		printf("Vi tri dong khong hop le!\n");
		return -1;
	}
	int tongcot =0;
	for (int i=0; i<m; i++){
		tongcot += a[i][k];
	}
	return tongcot;
}
int ktrSoAmDong(int a[][COL], int m, int n, int k)//cau F
{
	if (k<0||k>=m){
		printf("Vi tri dong khong hop le!\n");
		return -1;
	}
	for(int j=0; j<n; j++){
		if(a[k][j]<0){
			return 1;
		}
	}
	return 0;
}
int kiemTraSoNguyenToTrongCot(int a[][COL], int m, int n, int k) //cau G
{
    if (k < 0 || k >= n) {
        printf("Vi tri cot khong hop le!\n");
        return -1;
     for (int i = 0; i < m; i++) {
        if (laSoNguyenTo(a[i][k])) {
            return 1;
        }
    }

    return 0;
}
}

int laSoNguyenTo(int n){
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
void sapXepGiamDanDong(int a[][COL], int m, int n, int k)//cau H
{
    if (k < 0 || k >= m) {
        printf("Vi tri dong khong hop le!\n");
        return ;
    }

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[k][j] > a[k][maxIndex]) {
                maxIndex = j;
            }
        }
        int temp = a[k][i];
        a[k][i] = a[k][maxIndex];
        a[k][maxIndex] = temp;
    }
}	
int kiemTraCotToanSoLe(int a[][COL], int m, int n, int k) //cau I
{
    if (k < 0 || k >= n) {
        printf("Vi tri cot khong hop le!\n");
        return -1;
    }

    for (int i = 0; i < m; i++) {
        if (a[i][k] % 2 == 0) {
            return 0;
        }
    }

    return 1;
}
int kiemTraTonTai(int a[][COL], int m, int n, int x) //cau J
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                return 1;
            }
        }
    }
    return 0;
}
void timViTri(int a[][COL], int m, int n, int x) //cau K
{
    int found = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                printf("Gia tri %d nam o dong %d, cot %d\n", x, i, j);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Khong tim thay gia tri %d trong mang.\n", x);
    }
}
int timGiaTriLonNhatTrenDong(int a[][COL], int m, int n, int k) //cau L
{
    if (k < 0 || k >= m) {
        printf("Vi tri dong khong hop le!\n");
        return -1;
    }

    int max = a[k][0];
    for (int j = 1; j < n; j++) {
        if (a[k][j] > max) {
            max = a[k][j];
        }
    }
    return max;
}
int timGiaTriNhoNhatTrenDong(int a[][COL], int m, int n, int k) //cau M
{
    if (k < 0 || k >= m) {
        printf("Vi tri dong khong hop le!\n");
        return -1;
    }

    int min = a[k][0];
    for (int j = 1; j < n; j++) {
        if (a[k][j] < min) {
            min = a[k][j];
        }
    }
    return min;
}	
void inSoNguyenToTrenDong(int a[][COL], int m, int n, int k)//cau N
{
    if (k < 0 || k >= m) {
        printf("Vi tri dong khong hop le!\n");
        return;
    }

    printf("Cac so nguyen to tren dong %d la: ", k);
    for (int j = 0; j < n; j++) {
        if (kiemTraSoNguyenTo(a[k][j])) {
            printf("%d ", a[k][j]);
        }
    }
    printf("\n");
}

int kiemTraSoNguyenTo(int n)
{
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

