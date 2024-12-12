#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	int *p;
	FILE *fp;
	
	fp=fopen("D:/output.txt", "r");
	if (fp == NULL) {
		printf("Loi mo file!\n");
		exit(1);
	}
	
	fscanf(fp, "%d ", &n);
	
	p=(int*)malloc(n*sizeof(int));
	if (p==NULL) {
		printf("Loi cap phat bo nho!\n");
		exit(1);
	}
	
	for (int i=0; i<n; i++) {
		fscanf(fp, "%d " ,&p[i]);
	}
	
	fclose(fp);
	
	printf("Danh sach cac gia tri trong mang: \n");
	for(int i=0; i<n ;i++) {
		printf("%d ", p[i]);		
	}
	printf("\n");
	
	free(p);
	
	return 0;
}
