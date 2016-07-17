/*
*TITLE: Write a C program to find if a mathematical expression is valid or not.
*Author: surakshya thapa
Reference:  Data structures using C and C++
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct{
	int top;
	char items[MAX];
}stack;

void push(stack *,char);
char pop(stack*);
char opening(char);
int main()
{
	char a[MAX],w,d;
	stack s;
	s.top=-1;
	int i,valid=1;
	
	printf("Enter the equation:\n");
	scanf("%s",&a);
	
	for(i=0;i<strlen(a);i++)
	{
		printf("%d\n",i);
		if(a[i]=='(' || a[i]=='{' || a[i]=='[')
		{
			push(&s,a[i]);
		}
		if (a[i]==')' || a[i]=='}' || a[i]==']')
		{	
			if(s.top==-1)
			{
			valid=0;
			}
			
			else
			{
			w=pop(&s);
			d=opening(a[i]);
			
			
			if(w!=d)
			{
			valid=0;
			}
			}
		
		}
		
	}
	
if(!(s.top==-1))
{
	valid=0;
}

if(valid==1)
{
	printf("The mathematical expression you entered is VALID.");
}

else
{
	printf("The mathematical expression you entered is INVALID.");
}
}

void push(stack *s, char x)
{
	s->items[++(s->top)]=x;
}

char pop(stack *s)
{
	return s->items[(s->top)--];
}

char opening(char c)
{
	if(c==')')
	{
		return'(';
	}
	else if(c=='}')
	{
		return'{';
	}
	else if(c==']')
	{
		return'[';
	}
}


