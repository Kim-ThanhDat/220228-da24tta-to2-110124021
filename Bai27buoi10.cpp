#include<stdio.h>

main() {
	FILE *fp;
	char path[50];
	printf("\nNhap duong dan: ");
	fflush(stdin);
	gets(path);
	fp=fopen(path,"wt");
	if(fp==NULL){
		printf("\nLoi moi file");
	}else{
		fprintf(fp,"Hoc phai di doi voi hanh");
		fclose(fp);
	}
}