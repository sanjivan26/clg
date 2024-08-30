#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declaring Variables
    int *i;
    i = (int *)malloc(sizeof(int));
    
    int *nptr;
    nptr = (int *)malloc(sizeof(int));

    printf("Enter no of values");
    scanf("%d",nptr);

    int *arrptr;
    arrptr = (int *)malloc(sizeof(int) * (*nptr));

    //Getting inputs
    for(*i=0;*i<*nptr;(*i)++)
    {   printf("Enter number %d:",*i+1);
        scanf("%d",&arrptr[*i]);
    }

    //Finding sum
    int *sumptr;
    sumptr = (int *)malloc(sizeof(int));
    *sumptr = 0;

    for(*i=0;*i<*nptr;(*i)++)
        *sumptr+=arrptr[*i];
    

    printf("The total sum is %d\n",*sumptr);
    
}