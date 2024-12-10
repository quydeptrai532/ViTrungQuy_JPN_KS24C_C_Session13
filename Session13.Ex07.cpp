#include<stdio.h>

int matrix(int i,int j){
	   int arr[i][j];
	   printf("nhap cac phan tu cua mang :\n");
	   for(int a=0;a<i;a++){
	   	for(int b=0;b<j;b++){
	   		printf("nhap phan tu [%d][%d]:\n",a,b);
	   		scanf("%d",&arr[a][b]);
		   }
	   }
	   printf("Ma tran vua nhap la:\n");
	   for(int a=0;a<i;a++){
	   	for(int b=0;b<j;b++){
	   		printf("%d ",arr[a][b]);
		   }
		   printf("\n");
	   }
}
int main(){
	int cols,rows;
	printf("nhap so hang\n");
	scanf("%d",&rows);
	printf("nhap so cot\n");
	scanf("%d",&cols);
	matrix(rows,cols);
	return 0;
}
