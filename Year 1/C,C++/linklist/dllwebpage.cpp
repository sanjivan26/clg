//Function library for webpage navigation system implemented using doubly linked list
#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include "dllwpfunc.h"

int newpage(int,doublink&);
int front(doublink);
int back(doublink);
void display(doublink);

int cur=0;

int main()
{
    int choice,result;
    doublink b1;
    while(1)
    {
        getchar();
        printf("Enter a choice \n 1. New Webpage \n 2. Front \n 3. Back \n 4. Exit");
        scanf("%d",&choice);
        b1.insbeg(10);
        cur++;
        switch(choice)
        {
            case(1):
                result=newpage(5,b1);
                if(result==1)
                {
                    printf("\n New webpage inserted");
                }
                else
                {
                    printf("\n Insertion failed");
                }
                break;

            case(2):
                result=front(b1);
                if(result==1)
                {
                    printf("\n Navigation successful");
                }
                else
                {
                    printf("\n Navigation failed");
                } 
                break;   

             case(3):
                result=back(b1);   
                if(result==1)
                {
                    printf("\n Navigation successful");
                }
                else
                {
                    printf("\n Navigation failed");
                }  
                break;

            case(4):
                exit(0);
                break;      
        }
        display(b1);
        printf("%d",cur);
    }
    return 1;
}


//Method to implement new webpage
int newpage(int data,doublink &b1)
{
    //Node insertion  
    cur++;
    b1.inspos(data,cur);

    //Deleting following nodes
    while(b1.delpos(cur+1)!=0)
    {
        b1.delpos(cur+1);
    }
    return 1;
}

//Method to move front
int front(doublink b1)
{
    if(b1.searchpos(cur+1)!=-1)
    {
        cur+=1;
        return 1;
    }
    
    else
    {
        return 0;
    }
}

//Method to move back
int back(doublink b1)
{
    if(b1.searchpos(cur-1)!=-1)
    {
        cur-=1;
        return 1;
    }
    else
    {
        return 0;
    }
}

//Method to display current webpage content
void display(doublink b1)
{
    printf("\nYou are currently in webpage %d \nIt has data %d",cur,b1.searchpos(cur));
}