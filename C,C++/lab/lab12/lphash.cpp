//Implementation of linear probing hash adt using an array and linked lists
#include <stdio.h>
#include <stdlib.h>
#define size 100

class hash
{
    private:
        int arr[size];

    public:
        hash()
        {
            for(int i=0;i<=size;i++)
            {
                arr[i]=0;
            }
        }
        int insert(int);
        void disp();
        int deletion(int);
        int search(int);
};


int main() 
{
    hash h;
    int choice;
    int num;
    while(1) 
    {

        printf("\n1. Insert \n2. Delete \n3. Search \n4. Display \n5. Exit");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the number ");
                scanf("%d",&num);
                if(num==0 || num==-1)
                {
                    printf("Invalid input");
                    break;
                }
                if(h.search(num))
                {
                    printf("\nElement exists in hash");
                    break;
                }
                if(h.insert(num)) 
                {
                    printf("\n Inserted successfully.");
                }
                else 
                {
                    printf("\n Insertion unsuccessful.");
                }
                break;
            
            case 2:
                printf("Enter the number ");
                scanf("%d",&num);
                if(num==0 || num==-1)
                {
                    printf("Invalid input");
                    break;
                }                
                if(h.deletion(num)) 
                {
                    printf("\n Deleted successfully.");
                }
                else 
                {
                    printf("\n Deletion unsuccessful.");
                }
                break;

            case 3:
                printf("Enter the number ");
                scanf("%d",&num);
                if(num==0 || num==-1)
                {
                    printf("Invalid input");
                    break;
                }                
                if(h.search(num)) 
                {
                    printf("\n Element exists in hash.");
                }
                else 
                {
                    printf("\n Element does not exist in hash.");
                }            
                break;

            case 4:
                h.disp();
                break;

            case 5:
                return 0;
                break;
            

        }
    }
}


//Method to insert into hash 
int hash::insert(int num)
{
    int target=num%size;
    if(arr[target]==0 || arr[target]==-1)
    {
        arr[target]=num;  
        return 1;      
    }
    else
    {
        int cur=(target+1)%size;
        while(cur!=target) 
        {
            if(arr[cur]==0 || arr[cur]==-1)
            {
                arr[cur]=num;
                return 1;
            }
            cur=(cur+1)%size;
        }
        return 0;
    }
}

//Method to display
void hash::disp()
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==0 || arr[i]==-1)
        {
            printf("No value\n");
        }
        else
        {
            printf("%d\n",arr[i]);
        }
    }
}

//Method to delete
int hash::deletion(int num) 
{
    int target=num%size;
    if(arr[target]==num)
    {
        arr[target]=-1;  
        return 1;      
    }
    else
    {
        int cur=(target+1)%size;
        while(cur!=target) 
        {
            if(arr[cur]==num)
            {
                arr[cur]=-1;
                return 1;
            }
            if(arr[cur]==0)
            {
                return 0;
            }
            cur=(cur+1)%size;            
        }
        return 0;
    }
}

//Method to search
int hash::search(int num) 
{
    int target=num%size;
    if(arr[target]==num)
    {  
        return 1;      
    }
    else
    {
        int cur=(target+1)%size;
        while(cur!=target) 
        {
            if(arr[cur]==num)
            {
                return 1;
            }
            if(arr[cur]==0)
            {
                return 0;
            }
            cur=(cur+1)%size;            
        }
        return 0;
    }
}