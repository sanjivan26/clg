//Program to inplement singly linked list using adt
#include<stdio.h>
#include<stdlib.h>

class LinkList
{  
    private: 

    struct node
    {   
        int data;
        struct node *next;
    };

    struct node *head;

    struct node *gethead()
    {
        return head;
    }


    public:
        LinkList()
        {
            head=NULL;
        }

        int insasc(int);
        int merge(LinkList,LinkList);
        void display();
};



//Method to insert element in ascending order
int LinkList::insasc(int num)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;

    if(head==NULL||head->data>=num)
    {
        newnode->next=head;
        head=newnode;
        return 1;
    }
    else 
    {
        struct node* temp;
        struct node* temp2;
        temp=head;
        while(temp->data<=num)
        {
            if(temp->next==NULL)
            {
                temp->next=newnode;
                return 1;
            }
            else
            {
                temp2=temp;
                temp=temp->next;
            }    
        }
        newnode->next=temp2->next;
        temp2->next=newnode;
        return 1;
    }
}

//Method to merge two lists in ascending order
int LinkList::merge(LinkList l1,LinkList l2)
{   
    struct node* add;
    struct node *temp;
    add=l1.gethead();
    while(add!=NULL)
    {
        insasc(add->data);
        add=add->next;
    }
    add=l2.gethead();
    while(add!=NULL)
    {
        insasc(add->data);
        add=add->next;
    }
    return 1;    
}

//Method to display the List
void LinkList::display()
{
    struct node *add;
    add=head;
    printf("[");
    while(add!=NULL)
    {
        printf(" %d,",add->data);
        add=add->next;
    }
    printf("]");
}