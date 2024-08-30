
/*Efficient storage, retrieval, organisation is the goal of Data structures
*/
#include<stdio.h>
#include<stdlib.h>


class clist
{
    struct node 
    {
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;

    public:
        clist()
        {
            head=NULL;    
            tail=NULL;
        }
        void insbeg(int);
        void display();
};



    int main()
    {   
        clist cl1;
        int choice,num,pos;
        
        while(1)
        {   printf(" \n Enter your choice \n 1.Insert at beginning");
            scanf("%d",&choice);
            switch(choice)
            {
                case(1):
                    printf("Enter the number to be inserted");
                    scanf("%d",&num);
                    cl1.insbeg(num);
                    printf("%d has been inserted",num);
                    break;

                case(8):
                    cl1.display();
                    break;

                case(9):
                    exit(0); 
                    break;


            }





        }
    }


//Method to insert number at the beginning
void clist::insbeg(int num)
{
    if(head==NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        head=newnode;
        tail=newnode;
        newnode->next=newnode;
    }
    else
    {   
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        tail->next=newnode;
    }    
}


//Method to display the cll
void clist::display()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}