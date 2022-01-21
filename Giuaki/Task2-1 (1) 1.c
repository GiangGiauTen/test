#include <stdio.h>
#include <string.h>
char stack[100];
int top=-1;
void push(char c){
	top++;
	stack[top]=c;
}
char pop(){
	if(top<-1)
		printf("\nStack rong");
	else
		return stack[top--];
}
int convert(char *eqn, char *rpn)
{
	int i;
	int c=0;
	for (i=0;i<strlen(eqn);i++)
	{
		if (eqn[i]>'0'&&eqn[i]<='9')
		{
			rpn[c++]=eqn[i];
			rpn[c++]=' ';	
		}
		else if (eqn[i]=='(')
			push(eqn[i]);
		else if (eqn[i]=='*'||eqn[i]=='/')
		{
			while (top>-1&&(stack[top]=='*'||stack[top]=='/'))
			{
				rpn[c++]=pop();
				rpn[c++]=' ';
			}
			push(eqn[i]);
		}
		else if (eqn[i]=='+'||eqn[i]=='-')
		{
			while (top>-1&&stack[top]!='(')
			{
				rpn[c++]=pop();
				rpn[c++]=' ';
			}
			push(eqn[i]);
		}
		else if (eqn[i]=='+'||eqn[i]=='-')
		{
			while (top>-1&&stack[top]!='(')
			{
				rpn[c++]=pop();
				rpn[c++]=' ';
			}
			push(eqn[i]);
		}
		else if (eqn[i]==')')
		{
			while (top>-1&&stack[top]!='(')
			{
				rpn[c++]=pop();
				rpn[c++]=' ';
			}
			if (top==-1)
				return 0;
			else 
				pop();
		}
	}
	while (top>-1)
	{
		if (stack[top]=='(')
			return 0;
		else
		{
			rpn[c++]=pop();
			rpn[c++]=' ';
		}
	}
	rpn[c]='\0';
	return 1;
}
int calc(char *rpn)
{
	int i;
	int a;
	int b;
	top=-1;
	for (i=0;i<strlen(rpn);i++)
	{
		if (rpn[i]>'0'&&rpn[i]<='9')
			push(rpn[i]-'0');
		else if (rpn[i]=='+'||rpn[i]=='-'||rpn[i]=='*'||rpn[i]=='/')
		{
			if (top>-1) 
				a=pop();
			else return 0;
			if (top>-1)
				b=pop();
			else return 0;	
			switch(rpn[i])
			{
				case '+': push(b+a); break;
				case '-': push(b-a); break;
				case '*': push(b*a); break;
				case '/': push(b/a); break;
			}
		}
	}
	return stack[top];
}
int main()
{
	char s;
	int result;
	char one=0;
	char eqn[100];
	char rpn[100];
	while(1)
	{
		printf("Menu\n");
		printf("\t1. Chuyen doi sang ham hau to.\n");
		printf("\t2. Tinh ket qua.\n");
		printf("\t3. Thoat.\n");
		do
		{
			printf("Nhap lua chon: ");
			fflush(stdin);
			scanf("%c",&s);
			if (s!='1'&&s!='2'&&s!='3')
				printf("Nhap sai, vui long nhap lai.\n");
		} while (s!='1'&&s!='2'&&s!='3');
		switch (s)
		{
			case '1':
				printf("nhap phep tinh: ");
				fflush(stdin);
				fgets(eqn,100,stdin);
				if (convert(eqn,rpn)==0)
				{
					printf("Nhap sai, vui long nhap lai.\n");
					break;
				}
				result=calc(rpn);
				if (top!=0)
				{
					printf("Nhap sai, vui long nhap lai.\n");
					break;
				}
				printf("ham hau to cua phep tinh la: %s\n",rpn);
				one=1;
				break;
			case '2':
				if (one!=1)
				{
					printf("Chua nhap bieu thuc.\n");
					break;
				}
				printf("The result is: %d\n",result);
				break;
			case '3': return 0;
		}
	}
}

