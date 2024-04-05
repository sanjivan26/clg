//Program to implement queue using linked list
#include<stdio.h>
#include<stdlib.h>

class doublink
{
    struct node
    {
        struct node *prev;
        char data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;
    int top;

    public:
        doublink()
        {
            head=NULL;
            tail=NULL;
            top=-1;
        }
        int enqueue(char);
        int dequeue();
        void peek();
};



int main()
{   
    doublink l;    
    int choice;
    char num;
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n 1. Push \n2. Pop \n3. Peek \n4. Exit");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case(1):
                printf("\n Enter the character to insert into queue:");
                scanf("%c",&num);
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
                l.peek();
                break;

            case(4):
                exit(0);                
        }
    }
    return 0;
}        


//Method to push into queue
int doublink::enqueue(char num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=tail;
    if(tail!=NULL)
    {
        tail->next=newnode;
    }
    else
    {
        head=newnode;
    }
    tail=newnode;  

    top++;
    return 1;
}

//Method to pop queue
int doublink::dequeue()
{
    if(head==NULL)
    {
        return 0;
    }
    
    struct node *add;
    add=head;
    head=add->next;
    free(add);
    top--;
    return 1;
}

//Method to peek into queue
void doublink::peek()
{
    if(head==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("The value at the top of the queue is %c", head->data);
    }
}