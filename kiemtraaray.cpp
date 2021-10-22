#include<stdio.h>
#include <string.h>
#define MAX 100
int n1,n2;
int str1[MAX];
int str2[MAX];
int kiemtra (int str1[MAX],int str2[MAX]){
	int i;
    if(n1!=n2)
        return 0;
    else 
        for(i=0;i<n1;i++)
            if(str1[i]!=str2[i])
                return 0;
    return 1;
}
int main(){
    do{
        printf("nhap so phan tu cua day 1:");
        scanf("%d",&n1);
        if(n1<=0)
        	printf("loi,nhap lai \n");
    }while(n1<=0);
    for(int i=0;i<n1;i++){
    	printf("so thu %d cua str1:",i+1);
    	scanf("%d",&str1[i]);
	}
	   do{
        printf("nhap so phan tu cua day 2:");
        scanf("%d",&n2);
        if(n2<=0)
        	printf("loi,nhap lai \n");
    }while(n2<=0);
    for(int i=0;i<n2;i++){
    	printf("so thu %d cua str2:",i+1);
    	scanf("%d",&str2[i]);
	}
	
	if(kiemtra(str1,str2)==1)
		printf("giong nhau");
	else
	 printf("khac nhau");
}
