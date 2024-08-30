#include <stdio.h>

/*1) Compare the roll number with the middle element.
  1.1) If present -> return index + 1
  1.2) Otherwise check if the roll number to be searched is bigger than the number in the current index.
      1.2.1) If so, set the current location as the starting point and repeat 1 (array search size reduces by 1/2)
      1.2.2) otherwise, set the current location as the ending point and repeat 1 (array search size reduces by 1/2)
       1.2.3) If there are no more elements to be searched, then return that the roll number is not present in the array.*/
       
int binarysearch(int arr[],int start,int stop,int ele)   
{	
	int no=(start+stop)/2;
   
	if(ele ==arr[no])
		return (no);	
	else
	{	if(ele > arr[no])
			binarysearch(arr,no,stop,ele);
		if(ele < arr[no])
			binarysearch(arr,start,no,ele);
	}
	if(start==stop)
		return -1;			
}	

int main()
{
	int ele,no;
	
	//Getting inputs
	printf("Enter the no of elements in the array");
	scanf("%d",&no);
	int arr[no-1];
	printf("Enter the elements of the array");
	for(int i=0;i<no;i++)
		scanf("%d",&arr[i]);
		
	printf("Enter the element whose existence has to be checked");
	scanf("%d",&ele);
	

    int loc = binarysearch(arr,0,no-1,ele);
    
    	
	if(loc==-1)
		printf("The element is not present in the given array");
	else
		printf("The element is int he index %p",&arr[loc]);	
}	


