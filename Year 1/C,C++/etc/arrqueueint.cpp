//Program to implement queue using linked list
#include<stdio.h>
#include<stdlib.h>

#define size 5;

class queue
{
    int arr[5];
    int front;
    int rear;

    public:
        queue()
        {
            front=-1;
            rear=-1;
        }
        int enqueue(int);
        int dequeue();
        void display();
};



int main()
{   
    queue l;    
    int choice,num;
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n 1. Push \n2. Pop \n3. Peek \n4. Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
                printf("\n Enter the value to insert into queue:");
                scanf("%d",&num);
                l.enqueue(num);
                printf("Successfully inserted into queue");
                break;

            case(2):
                if(l.dequeue())
                {
                    printf("Queue is popped successfully");
                }
                else
                {
                    printf("Queue is empty");
                }
                break;

            case(3):
                l.display();
                break;

            case(4):
                exit(0);                
        }
    }
    return 0;
}        


//Method to push into queue
int queue::enqueue(int num)
{
    if(front==(rear+1)%5)
    {
        return 0;
    }
    if(front==-1)
    {
        front++;
    }
    rear++;
    arr[rear]=num;
    return 1;
}


//Method to pop queue
int queue::dequeue()
{
    if(front==rear)
    {
        return 0;
    }
    front++;
    return 1;
}

//Method to display queue
void queue::display()
{
    if(front==(rear+1)%5)
    {
        printf("Stack is empty");
    }
    else
    {
        for(int i=front;i%5!=rear;i++)
        {
            printf("%d ",arr[i]);
        }
    }
}