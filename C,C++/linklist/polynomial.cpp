#include<stdio.h>
#include<stdlib.h>

class poly
{
    struct node
    {
        int coe;
        int deg;
        struct node *next;
    };

    struct node *head;


    public:
        poly()
            {
                head=NULL;
            }
        poly addpoly(struct node*,struct node*);
};


int main()
{
    poly p1;
    int choice,num;
    while(1)
    {
        printf("1. insert \n 2. addition \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):

        }
    }
}


//Method for adding two polynomials
poly poly::addpoly(struct node* poly1,struct node* poly2)
{
    while(poly1->next!=NULL)
    {

    }
}