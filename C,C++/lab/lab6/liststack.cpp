//Program to implement stack using linked list
#include<stdio.h>
#include<stdlib.h>

class LinkList
{  
    private: 

    struct node
    {   
        char data;
        struct node *next;
    };
    int top;
    struct node *head;

    public:
        LinkList()
        {
            head=NULL;
            top=-1;
        }
        int push(char);
        int pop();
        void peek();
};



int main()
{   
    LinkList l;    
    int choice,pos,result;
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
                printf("\n Enter the character to insert into stack:");
                scanf("%c",&num);
                l.push(num);
                printf("Successfully inserted into stack");
                break;

            case(2):
                if(l.pop())
                {
                    printf("Stack is popped successfully");
                }
                else
                {
                    printf("Stack is empty");
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


//Method to push into stack
int LinkList::push(char num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    top++;
    return 1;
}

//Method to pop stack
int LinkList::pop()
{
    if(top==-1)
    {
        return 0;
    }
    
    struct node *add;
    add=head;
    head=head->next;
    free(add);
    top--;
    return 1;
}

//Method to peek into stack
void LinkList::peek()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("The value at the top of the stack is %c", head->data);
    }
}