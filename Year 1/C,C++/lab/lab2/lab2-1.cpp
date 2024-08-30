#include <stdio.h>


int main()
{
	int ele,no;
	int flag=0;
	

	//Getting inputs
	printf("Enter the no of elements in the array");
	scanf("%d",&no);
	int arr[no];
	printf("Enter the elements of the array");
	for(int i=0;i<no;i++)
		scanf("%d",&arr[i]);
		
	printf("Enter the element whose existence has to be checked");
	scanf("%d",&ele);
	
	//Checking presence of ele in arr[]
	for(int i=0;i<no;i++)
	{	if (arr[i]==ele)
		{	flag=1;
			printf("The element is present in the given array");
		}
	}
	if(flag==0)
		printf("The element is not present in the given array");
		
	return 0;
	
	
	
	
}	


