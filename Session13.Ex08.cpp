#include<stdio.h>

int UCLN(int a,int b);
int main(){
	int so1,so2;
	printf("Nhap vao so thu nhat");
	scanf("%d",&so1);
	printf("Nhap vao so thu hai");
	scanf("%d",&so2);
	printf("uoc chung lon nhat cua 2 so %d va %d la :",so1,so2);
	UCLN(so1,so2);
	return 0;
}
int UCLN(int a,int b){
	int ucln;
	if(a>=b){
		for(int i=1;i<=a;i++){
			if(a%i==0&&b%i==0){
				ucln=i;
			}
		}
	}
	if(b>=a){
		for(int i=1;i<=b;i++){
			if(a%i==0&&b%i==0){
				ucln=i;
			}
		}
	}
  printf("%d",ucln);
}
