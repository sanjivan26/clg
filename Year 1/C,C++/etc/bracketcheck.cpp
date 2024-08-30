#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"liststack.h"


int main()
{     
    int n, choice;
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n 1.Balance Check \n 2.Exit");
        scanf("%d",&choice);
        getchar();
        if(choice==1)
        {    
            printf("\n Enter the length of string:");
            scanf("%d",&n);
            char input[n];
            printf("\n Enter the  string:");
            scanf("%s",input);

        
        LinkList l1;
        int i=0;
        int ans=0;
        while(i<n)
        {   
            if(input[i]==')' && l1.check()==0)
            {
                ans=0;
                break;
            }
            else if(input[i]=='(')
            {
                l1.push(input[i]);
            }
            else if(input[i]==')')
            {
                l1.pop();
            }
            i++;
        }

        if(l1.check()==0)
        {
            ans=1;
        }
        
        if(ans==1)
        {
            printf("The number of { and } are balanced");
        }
        else
        {
            printf("The number of { and } are not balanced or string is invalid");
        }

        }
        else
        {
            exit(0);
        } 
    }
    return 0;
}   
