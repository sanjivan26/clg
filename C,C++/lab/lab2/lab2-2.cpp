#include <stdio.h>

void swap(int *a,int *b)
{	int c;
	c=*a;
	*a=*b;
	*b=c;
}

int main()
{
	int n;
	int flag=0;
	int order;
	int temp;

	//Getting inputs
	printf("Enter the no of elements in the array");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of the array");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter 0 for ascending and 1 for descending");
	scanf("%d",&order);
	
	//Sorting
	for(int i=n-1;i>=0;i--)
	{	for(int j=0;j<i;j++)
			{	if(order==0)
				{	if(arr[j+1]<arr[j])
						swap(&arr[j+1],&arr[j]);
				}
				if(order==1)
				{	if(arr[j+1]>arr[j])
					swap(&arr[j+1],&arr[j]);
				}
			}
	}		
	
	
	//Printing output array
	for(int i=0;i<n;i++)
		printf("%d,",arr[i]);
		
}	
