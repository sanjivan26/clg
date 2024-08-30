//Program to implement stack using linked list
#include<stdio.h>
#include<stdlib.h>

class stack
{  
    private: 

    struct node
    {   
        int data;
        struct node *next;
    };
    int top;
    struct node *head;

    public:
        stack()
        {
            head=NULL;
            top=-1;
        }
        int push(int);
        int pop();
        int peek();
        int isempty();
};

//Method to push into stack
int stack::push(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    top++;
    return 1;
}

//Method to pop stack
int stack::pop()
{
    struct node *add;
    add=head;
    head=head->next;
    int data=add->data;
    free(add);
    top--;
    return data;
}

//Method to peek into stack
int stack::peek()
{
    return head->data;
}

//Method to check is stack is empty
int stack::isempty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}    