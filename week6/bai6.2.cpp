#include<stdio.h>
#define MAX 100
#include<string.h>
typedef struct{
	char name[31];
	char email[31];
	char phone[12];
}Address;
Address abd[MAX];
int timkiem(){
	int k=0;
	while(strcmp(abd[k].name,abd[10].name)!=0){
		k++;
	}
	return k;
}
int main(){
	FILE* in= fopen("alo.txt","r");
	for(int i=0;i<10;i++){
		fgets(abd[i].name,30,in);
		fgets(abd[i].email,30,in);
		fgets(abd[i].phone,11,in);
	}
	printf("nhap dia chi can tim kiem:");
	fflush(stdin);
	fgets(abd[10].name,30,stdin);
	fclose(in);
	printf("%s\n",abd[1].name);
	int k=timkiem();
	if(k==10)
		printf("HongKong1");
	else{
	 	FILE* out= fopen("goodbye.txt","a+");
	 	fprintf(out,"%s",abd[k].name);
	 	fprintf(out,"%s",abd[k].email);
	 	fprintf(out,"%s\n",abd[k].phone);
	 	fclose(out);
	 }
	return 0;
}
