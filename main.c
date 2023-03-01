#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stack_size 100
typedef struct
{
	int data[stack_size];
	int top;
}stack;

void reset(stack *stk)
{
	stk->top=-1;
}

void push(stack *stk,char c)
{
	if(stk->top==stack_size-1)
	{
		printf("FULL");
	}
	else
	{
		stk->top++;
		stk->data[stk->top]=c;	
	}
}
int pop(stack *stk)
{
	if(stk->top==-1)
	{
		return 0;
	}
	else
	{
		char key= stk->data[stk->top];
		stk->top--;
		return key;	
	}
}

void sonuc(stack *stk)
{
	if(stk->top==-1)
		{
			printf("no error");
			
		}
		else
		{
			printf("yes error");
		}
}
int main(int argc, char *argv[]) {
	
	
	stack s;
	reset(&s);
	char ch;
	char kod[999];
	
	printf("kodu giriniz:\n");
	gets(kod);
	
	int x= strlen(kod);
	printf("%d\n", x);
	
	int i=0;
	char y;
	
	for(i=0;i<x;i++)
	{
		
		if(kod[i]=='('||kod[i]=='{'|| kod[i]=='[')
		{
			push(&s,kod[i]);
		}
		if(kod[i]==')')
		{
			if(pop(&s)!='(')
			{
				printf("hata vardir");
				return 0;
			}
		}
		if(kod[i]=='}')
		{
			if(pop(&s)!='{')
			{
				printf("hata vardir");
				return 0;
			}
		}
		if(kod[i]==']')
		{
			if(pop(&s)!='[')
			{
				printf("hata vardir");
				return 0;
			}
		}
		
	}
	
	sonuc(&s);
	
	
	
	return 0;
}
