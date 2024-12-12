#include <stdio.h>
 
int main() {
	int n;
	printf("Nhap so phan tu cua mang: \n");
	scanf("%d", &n);
	
	int a[n];
	printf("Nhap cac phan tu cua mang: \n");
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	FILE *fp;
	fp = fopen("D:/output.txt", "w");
	if(fp == NULL) {
		printf("Loi moi file!\n");
		return 1;
	}
	fprintf(fp, "%d\n", n);
	for (int i=0; i<n; i++) {
		fprintf(fp, "%d ", a[i]);

	}
	fclose(fp);
	printf("Da ghi du lieu vao file 28output.txt thanh cong!\n");
	return 0;
}
