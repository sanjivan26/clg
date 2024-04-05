#include<stdio.h>
#include<stdlib.h>
#include"intstack.h"

int main()
{
    int n,total;
    printf("Enter the total number of numbers");
    scanf("%d",&total);
    int num[total];
    printf("Enter the numbers");
    for(int i=0;i<total;i++)
    {
        scanf(" %d",&num[i]);
    }
    printf("Enter the number to search for and calculate previous smaller and next bigger number");
    scanf("%d",&n);

    int pos=-1 ,prevsmol=-1 ,nxtbig=-1;

    //Finding previous smaller element and position
    stack s1;
    for(int i=0;i<total;i++)
    {
        while(!s1.isempty() && num[i]<=s1.peek())
        {
            s1.pop();           
        }
        s1.push(num[i]);

        if(num[i]==n)
        {
            pos=i;
            s1.pop();
            if(s1.isempty()==0)
            {
                prevsmol=s1.pop();
            }
            break;
        }
        printf("%d%d",num[i],s1.peek());
    }

    //Finding next bigger element and position
    for(int i=pos;i<n;i++)
    {
        if(num[i]>n)
        {
            nxtbig=num[i];
            break;
        }
    }
    printf("The number %d is in position %d.\nIts previous smaller number is %d and its next bigger number is %d\n", n, pos + 1, prevsmol, nxtbig);
}