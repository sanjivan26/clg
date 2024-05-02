#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"


int main()
{
	char exp[100],arr[100];
	Stack stack,s1;
	int i,n,j=0;
		char x;
	int opp;
	int m,k1;
	while(1)
	{
	printf("\n ENTER THE OPTION\n1.ENTER THE STRING\n2.INFIX TO POSTFIX CONVERSION\n3.POSTFIX EVALUATION\n4.EXIT");
	scanf("%d",&opp);

	
	switch(opp)
	{
		
	case 1:
	printf("\n Enter the expression");
	scanf("%s",&exp);
	n = strlen(exp);
	break;
	case 2:
	for(i=0;i<n;i++)
	{
	
		int c;
		c = stack.isempty();
		if(exp[i]!='+' && exp[i]!='-' && exp[i]!='=' && exp[i]!='*'&& exp[i]!='/')
		{
			arr[j] = exp[i];
			j++;
		}
			
		else if(c==1)
		{	
				stack.push(exp[i]);	
		}
		else 
		{
			char p;
			p = stack.peek();
			if(p=='=')
			{
				stack.push(exp[i]);
			}
			else if(p=='+' || p=='-')
			{
				if(exp[i]=='*' || exp[i]=='/')
				{
					stack.push(exp[i]);
				}
				else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='=' )
				{
					char k;
				  k  =	stack.pop();
				  arr[j]= k;
				  j++;
				  stack.push(exp[i]);
					
					
				}
			
			}
			else if(p=='*' || p=='/')
			{
				char k;
				  k  =	stack.pop();
				  arr[j]= k;
				  j++;
				  char y;
				  y = stack.peek();
				  if(y=='+'|| y=='-')
				  {
				  	if(exp[i]=='+' || exp[i]=='-')
				  	{
				  	char o;
				  o  =	stack.pop();
				  arr[j]= o;
				  j++;
				  stack.push(exp[i]);
					  }
				  }
			}
			
			
		}
	
		}
		int k;
	
		 m =j;
		
		for (k=0;k<n-m;k++)
		{
		  x = stack.pop();
		  arr[j]= x;
		  j++;
		}
		
		for(i=0;i<j;i++)
		{
			printf("%c ",arr[i]);
		}
	
		break;
		case 3:
			
		int temp;
		for(k1=0;k1<n;k1++)
		{
		
		if(arr[k1]!='+' && arr[k1]!='-' && arr[k1]!='=' && arr[k1]!='*' && arr[k1]!='/')
		{
			temp = arr[k1]-'0';
			s1.push(temp);
		}
		else
		{
			char opp;
			opp = arr[k1];
			int res;
			char res1;
			char var1;
			char var2;
			int num1,num2;
			switch(opp)
			{
				case '+':
				
					char idonno;
					var2 = s1.pop();
					var1 = s1.pop();
					num2 = int(var2);
					num1 = int(var1);
					printf("\n %d  %d",num2,num1);
					res = num2 + num1;
					s1.push(char(res));
		
					break;
				case '-':
				
					var2 = s1.pop();
					var1 = s1.pop();
					num2 = int(var2);
					num1 = int(var1);
					printf("\n %d  %d",num2,num1);
					res = num1 - num2;
					s1.push(char(res));
					break;
				case '*':
				
					var2 = s1.pop();
					var1 = s1.pop();
					num2 = int(var2);
					num1 = int(var1);
					printf("\n %d  %d",num2,num1);
					res = num2 * num1;
					s1.push(char(res));
					break;
				case '/':
					
					var2 = s1.pop();
					var1 = s1.pop();
					num2 = int(var2);
					num1 = int(var1);
					printf("\n %d  %d",num2,num1);
					res = num1 / num2;
					s1.push(char(res));
					break;
				case '=':
				
					
					var2 = s1.pop();
					var1 = s1.pop();
					var1 = var2;
					s1.push(var1);
					break;
				default:
					printf("\n enter a valid option");
					break;
					
					
			}
		}
	}
	char final;
		char t;
	
	final = s1.pop();
int pls;
pls = int(final);
	
	printf("\n Final result is %d",pls);
	break;
	case 4:
		exit(0);
		break;
	default:
		printf("\n ENTER A VALID VALUE");
		break;
	}
}
		}
		
		
		
	



