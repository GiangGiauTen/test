#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node* next;
};
struct node* root=NULL;
struct node* cur;
struct node* prev;
struct node* gi;
int tmp;
struct node * New;
int main(){
	for(int i=0;i<11;i++){
		New = (struct node*) malloc(sizeof(struct node));
		scanf("%d",&tmp);
		New->num=tmp;
		New->next=NULL;
		if(root==NULL){
			root=New;
			cur=root;	
		}
		else{
			cur->next = New;
			cur = cur->next;
		}
	}
	prev=NULL;
	gi=root;
	while(gi!=NULL){
		cur=gi;
		gi=cur->next;
		cur->next=prev;
		prev=cur;
	}
	root=cur;
	for(cur=root;cur!=NULL;cur=cur->next){
		printf("%d ",cur->num);
	}
	return 0;
}
