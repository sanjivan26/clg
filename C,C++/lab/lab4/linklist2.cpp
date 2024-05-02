#include<stdio.h>
#include<stdlib.h>
#include"linklistfunc.h"

int main()
{
    LinkList l1,l2,l3;
    int n,num;

    //Insert List1
    printf("Step1 : Insert List1 \n ");
    printf("Enter no of values in List1");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter value at position %d \n",i);
        scanf("%d",&num);
        l1.insasc(num);
    }

    //Insert List2
    printf("Step2 : Insert List2 \n ");
    printf("Enter no of values in List2");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter value at position %d \n",i);
        scanf("%d",&num);
        l2.insasc(num);
    }



    //Merge into List3
    printf("Merging lists 1 and 2 into 3 ");
    l3.merge(l1,l2);

    //Displaying lists
    printf("\n List 1 is");
    l1.display();
    printf("\n List 2 is");
    l2.display();
    printf("\n List 3 is");
    l3.display();
    getchar();

    return 1;
}