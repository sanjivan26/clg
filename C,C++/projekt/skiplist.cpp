//Accepted values from 0 to 999
#include<stdio.h>
#include<iostream>
#include<cstdlib>

#define levels 4
#define maxval 1000

int toss()
{
    return std::rand()%2;
}

class skiplist
{
    private:
        struct node
        {
            struct node * left;
            struct node * right;
            struct node * up;
            struct node * down;
            int data;
        };
        struct node * front;

    public:
        skiplist()
        {
            struct node * temp = (struct node *)malloc(sizeof(struct node));
            temp->data = -1;
            temp->right = (struct node *)malloc(sizeof(struct node));
            struct node * temp2 = temp->right; 
            temp2->data = maxval;
            for(int i=0;i<levels-1;i++)
            {
                temp->up = (struct node *)malloc(sizeof(struct node));
                temp=temp->up;
                temp->right = (struct node *)malloc(sizeof(struct node));
                temp2=temp->right;
                temp2->data = maxval;
                temp->data = -1;
            }
            front=temp;
        }

    
};