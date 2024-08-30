#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"liststack.h"

int preccalc(char);

int main()
{     
    int n, choice;  
            printf("\n Enter the length of string:");
            scanf("%d",&n);
            char input[n];
            printf("\n Enter the equation:");
            scanf("%s",input);

            LinkList l1;
            char l[n];
            int ltop=-1;
            int prec[2];
            for(int i=0;i<n;i++)   
            {
                if(i%2==0)
                {
                    ltop++;
                    l[ltop]=(l1.popreturn());
                    break;
                }
                else if(l1.check()==0)
                {
                    l1.push(input[i]);
                    prec[1]=preccalc(input[i]);
                    prec[0]=prec[1];
                }
                else
                {
                    prec[1]=preccalc(input[i]);
                    if(prec[0]<prec[1])
                    {
                        l1.push(input[i]);
                        prec[0]=prec[1];
                    }
                    else if(prec[0]>prec[1])
                    {   
                        ltop++;
                        l[ltop]=(l1.popreturn());
                        prec[0]=prec[1];                        
                    }
                    else if(prec[0]==prec[1])
                    {
                        if(prec[1]==1)
                        {
                           l1.push(input[i]); 
                        }
                        else
                        {   
                            ltop++;
                            l[ltop]=(l1.popreturn());
                        }
                        prec[0]=prec[1];
                    }         
                    
                }
            printf("%d%d",prec[0],prec[1]);
            }
            for(int i=0;i<=ltop;i++)
            {
                printf("%c",l[i]);
            }     
        }




int preccalc(char c)
{
    if(c=='+'||c=='-')
    {
        return 2;
    }
    else if(c=='/'||c=='*')
    {
        return 3;
    }
    else
    {
        return 1;
    }
}

/*To calculate final answer, 
    push operands into stack until operator encounter
        pop value
        calculate with first 3 values in array
            (only applicable for operators requiring 2 operands)
    repeat*/