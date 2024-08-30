
//Program to implement stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{   
    char data;
    struct node *left;
    struct node *right;
};

class Stack
{  
    private: 

    struct listnode
    {   
        struct node * data;
        struct listnode *next;
    };
    int top;
    struct listnode *head;

    public:
        Stack()
        {
            head=NULL;
            top=-1;
        }
        int push(struct node *);
        struct node * pop();
        struct node * peek();
        int isempty();
};

//Method to push into stack
int Stack::push(struct node * num)
{
    struct listnode *newnode=(struct listnode*)malloc(sizeof(struct listnode));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    top++;
    return 1;
}

//Method to pop stack
struct node * Stack::pop()
{
    struct listnode *add;
    add=head;
    head=head->next;
    struct node * data=add->data;
    free(add);
    top--;
    return data;
}

//Method to peek into stack
struct node * Stack::peek()
{
    return head->data;
}

//Method to check is stack is empty
int Stack::isempty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}    