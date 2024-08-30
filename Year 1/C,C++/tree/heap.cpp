//Program to inplement heap data structure using linked list adt
#include<stdio.h>
#include<stdlib.h>

class heap
{  
    private: 
        int data[31];
        int top;

        int parent(int i)
        {
            return (i-2)/2;
        }
        int left(int i)
        {
            return (i*2)+1;
        }
        int right(int i)
        {
            return (i*2)+2;
        }
        void swap(int a, int b)
        {
            int c=a;
            a=b;
            b=c;
        }
        int upheapify(int i)
        {
            if(data[i]>data[parent(i)])
            {
                while(data[i]>data[parent(i)])
                {
                    swap(data[i],data[parent(i)]);
                }
                upheapify(parent(i));
            }
            else
            {
                return 1;
            }     
        }


    public:
        heap()
        {
            top=-1;
        };

        int insert(int);
        int deletion();
        int display();
        int search(int);
        void sort();
        void deletion(int);
};

int main()
{   
    heap h;    
    int choice,num;
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n1.Insert \n2.Delete \n3.Display \n4.Search \n5.Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
                printf("\n Enter the number to insert:");
                scanf("%d",&num);
                h.insert(num);
                break;
            case(2):
                h.deletion();
                break;    
            case(3):
                h.display();
                break; 
            case(4):
                printf("\n Enter the number to search:");
                scanf("%d",&num);
                if(h.search(num))
                {
                    printf("The element is present in the heap");
                }
                else
                {
                    printf("The element is absent in the heap");
                }
                break;   
            case(5):
                exit(0);
                break;    
        }
    }
    return 1;
}


//Method to insert value
int heap::insert(int num)
{
    if (top==31)
    {
        return 0;
    }
    top++;
    data[top]=num;
    upheapify(top);
    return 1;
}

//Method for deletion
int heap::deletion()
{
    if (top==-1)
    {
        return 0;
    }
    for(int i;i<top;i++)
    {
        data[i]=data[i+1];
    }
    top--;
    return 1;
}

//Method to display
int heap::display()
{
    if(top==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d ",data[i]);
        }
    }
    return 1;
}

//Method for searching
int heap::search(int num)
{
    if(top==-1)
    {
        return 0;
    }
    int i=0;
    while(data[i]<=num)
    {
        i++;
    }
    if (data[i]==num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

