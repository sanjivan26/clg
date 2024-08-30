#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"liststack.h"

int preccalc(char);

int main()
{     
    int n, choice;
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n 1.Calculate \n 2.Exit");
        scanf("%d",&choice);
        getchar();
        if(choice==1)
        {    
            printf("\n Enter the length of string:");
            scanf("%d",&n);
            char input[n];
            printf("\n Enter the equation:");
            scanf("%s",input);

            LinkList l1;
            char l[n];
            int ltop=-1;
            for(int i=0;i<n;i++)   
            {
                if(i%2==0)
                {
                    ltop++;
                    l[ltop]=input[i];
                }
                else if(l1.check()==0)
                {
                    l1.push(input[i]);
                }
                else
                {
                    if(preccalc(l1.peek())<preccalc(input[i]))
                    {
                        l1.push(input[i]);
                    }
                    else if(preccalc(l1.peek())>preccalc(input[i]))
                    {   
                        ltop++;
                        l[ltop]=(l1.popreturn());    
                        l1.push(input[i]);                
                    }
                    else if(preccalc(l1.peek())==preccalc(input[i]))
                    {
                        if(input[i]=='=')
                        {
                           l1.push(input[i]); 
                        }
                        else
                        {   
                            ltop++;
                            l[ltop]=(l1.popreturn());    
                            l1.push(input[i]);      
                        }
                    }         
                    
                }
            }
            for(int i=0;i<=ltop;i++)
            {
                printf("%c",l[i]);
            }  
            while(l1.check()!=0)
            {
                printf("%c",l1.popreturn());
            }   
        }


        else
        {
            exit(0);
        } 
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