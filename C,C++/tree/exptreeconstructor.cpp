#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"exptree.h"
#include"stack.h"

int main()
{
	char input[100];;
	stack stack, s1;
	char arr[100];
	int arrlen=0;
	char x;
	int n;
	int choice;
	int m,k1;
	while(1)
	{
		getchar();
        getchar();
        system("clear"); 
		printf("\n Enter your choice \n1.Enter the string \n2.Postfix Conversion \n3.Postfix Evaluation \n4.Exit");
		scanf("%d",&choice);

		
		switch(choice)
		{
			case 1:
			{
				printf("\n Enter the expression");
				scanf("%s", input);
				n=strlen(input);
				break;
			}

			case 2:
			{
				for(int i=0;i<n;i++)
				{				
					if(input[i]!='+' && input[i]!='-' && input[i]!='=' && input[i]!='*'&& input[i]!='/')
					{
						arr[arrlen] = input[i];
						arrlen++;
					}
						
					else if(stack.isempty())
					{	
						stack.push(input[i]);	
					}

					else 
					{
						char p;
						p = stack.peek();
						if(p=='=')
						{
							stack.push(input[i]);
						}

						else if(p=='+' || p=='-')
						{
							if(input[i]=='*' || input[i]=='/')
							{
								stack.push(input[i]);
							}

							else if(input[i]=='+' || input[i]=='-' || input[i]=='=' )
							{
								arr[arrlen]=stack.pop();
								arrlen++;
								stack.push(input[i]);	
							}
						
						}

						else if(p=='*' || p=='/')
						{
							arr[arrlen]=stack.pop();
							arrlen++;
							char y;
							y = stack.peek();
							if(y=='+'|| y=='-')
							{
								if(input[i]=='+' || input[i]=='-')
								{
									arr[arrlen]=stack.pop();
									arrlen++;
									stack.push(input[i]);
								}
							}
						}
					}
				}
				m =arrlen;
				for (int k=0;k<n-m;k++)
				{
					x = stack.pop();
					arr[arrlen]= x;
					arrlen++;
				}
					
				for(int i=0;i<arrlen;i++)
				{
					printf("%c ",arr[i]);
				}
				break;
			}

			case 3:
			{
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
						char var1;
						char var2;
						int num1,num2;
						switch(opp)
						{
							case '+':
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
				final = s1.pop();
				int pls;
				pls = int(final);
			
				printf("\n Final result is %d",pls);
				break;
			}

			case 4:
			{
				exit(0);
				break;
			}

			default:
				printf("\n Invalid input");
				break;
		}
	}
}
		
		
		
	



