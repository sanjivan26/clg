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
    }

    //Finding next bigger element and position
    stack s2;
    for(int i=total-1;i>=0;i--)
    {
        while(!s2.isempty() && num[i]>=s2.peek())
        {
            s2.pop();
        }
        s2.push(num[i]);

        if(num[i]==n)
        {
            s2.pop();
            if(s2.isempty()==0)
            {
                nxtbig=s2.pop();
            }
            break;
        }
    }

    printf("The number %d is in position %d.\nIts previous smaller number is %d and its next bigger number is %d\n", n, pos + 1, prevsmol, nxtbig);
}