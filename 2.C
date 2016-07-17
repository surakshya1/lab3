/*
* TITLE: Write a C program to evaluate a postfix expression.
*Author: Surakshya thapa.
Reference:  Data structures using C and C++,
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
	int top;
	char items[MAX];
}stack;

void push(stack *, char);
int pop(stack *);
int isdigit(char),value;
int optn(char, int, int);

int main()
{
	char a[MAX];
	int i,opnd1,opnd2,n,w;
	stack s;
	
	printf("Enter any postfix expression:\n");
	scanf("%s",a);
	
	for(i=0;i<strlen(a);i++)
	{
		if(isdigit(a[i])==1)
		{
			push(&s,(int)(a[i]-'0'));
			printf("The pushed character is %c\n",a[i]);
		}
		
		else if(isdigit(a[i])==0)
		{
			opnd2=pop(&s);
			opnd1=pop(&s);
			//printf("the popped characters are %d and %d\n",opnd1,opnd2);
			//printf("the operator is %c\n",a[i]);
			value=optn(a[i],opnd1,opnd2);
			push(&s,value);
		}
		
	}
	printf("the value of the given postfix operation is %d",pop(&s));
}

void push(stack *s, char x)
{
	s->items[++(s->top)]=x;
}

int pop(stack *s)
{
	int x;
	x=s->items[(s->top)--];
	return x;
	
}

int isDigit(char symb)
{
if(symb>='0' && symb<='9')
return 1;
else
return 0;
}

int operation(char op,int a,int b)
{
	
	switch(op){
		case '+' : return(a+b);
		break;		
		case '-' : return(a-b);
		break;
		case '*' : return(a*b);
		break;
		case '/' : return(a/b);
		break;
		case '$' : return(pow(a,b));	
		break;
		default  : printf("%s","illegal operation");
		exit(1);
	}
}
