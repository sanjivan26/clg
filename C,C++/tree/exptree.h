//Program to inplement tree data structure using linked list adt
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"liststack.h"

struct node * constructexpressiontree(char[100]);

class Tree
{  
    private: 

        struct node *root;

        int recins(struct node *temp,struct node *newnode)
        {
            int loc;
            printf("\n Type 0 to traverse left or 1 to traverse right");
            scanf("%d",&loc);

            if(loc==0)
            {
                if(temp->left==NULL)
                {
                    temp->left=newnode;
                    return 1;
                }
                temp=temp->left;
            }
            else if(loc==1)
            {
                if(temp->right==NULL)
                {
                    temp->right=newnode;
                    return 1;
                }            
                temp=temp->right;
            }
            return recins(temp,newnode);
        }

        int recpre(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }
            printf("%c",temp->data);
            recpre(temp->left);                
            recpre(temp->right);
            return 1;
        }

        int recpost(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }
            recpost(temp->left);    
            recpost(temp->right);      
            printf("%c",temp->data);      
            return 1;
        }

        int recin(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }

            recin(temp->left);
            printf("%c",temp->data);
            recin(temp->right);
            return 1;
        }       

        int recsearch(struct node *temp, char num)
        {
            if(temp==NULL)
            {
                return 0;
            }
            if(temp->data==num)
            {
                return 1;
            }
            if(recsearch(temp->left,num))
            {
                return 1;
            }          
            if(recsearch(temp->right,num))
            {
                return 1;
            }
            return 0;     
        }

        int recrecdel(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }
            recrecdel(temp->left);    
            recrecdel(temp->right);    
            free(temp);
            return 1;            
        }

        int recdel(struct node *temp,struct node *prev)
        {
            int loc;
            printf("\n Type 0 to traverse left or 1 to traverse right or 2 to delete");
            scanf("%d",&loc);

            if(loc==0)
            {
                if(temp->left==NULL)
                {
                    return 0;
                }
                prev=temp;
                temp=temp->left;
            }
            else if(loc==1)
            {
                if(temp->right==NULL)
                {
                    return 0;
                }            
                prev=temp;
                temp=temp->right;
            }           
            else if(loc==2) 
            {
                if(prev->left==temp)
                {
                    prev->left=NULL;
                }
                else if(prev->right==temp)
                {
                    prev->right=NULL;
                }
                else if(prev==temp)
                {
                    prev=NULL;
                }
                return(recrecdel(temp));
            }
            return(recdel(temp,prev));
        }

    public:
        Tree()
        {
            root=NULL;
        }

        int insert(char);
        int inorder();
        int preorder();
        int postorder();
        int search(char);
        int deletion();
};

//Method to insert value
int Tree::insert(char num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        root=newnode;
        return 1;
    }

    return recins(root,newnode);
}

//Method for preorder
int Tree::preorder()
{
    return recpre(root);
}

//Method for inorder
int Tree::inorder()
{
    return recin(root);
}

//Method for postorder
int Tree::postorder()
{
    return recpost(root);
}

//Method for searching
int Tree::search(char num)
{
    return recsearch(root,num);
}

//Method for deletion
int Tree::deletion()
{
    return recdel(root,root);
}

//Method for constructing an expression tree
struct node* constructexpressiontree(char input[100])
{
    Stack stack;
    int n=strlen(input);
    for(int i=0;i<n;i++)
    {
        if(input[i]!='+' && input[i]!='-' && input[i]!='=' && input[i]!='*'&& input[i]!='/')
        {
            struct node* newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data=input[i];
            stack.push(newnode);            
        }

        else 
        {
            struct node* newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data=input[i];
            newnode->right=stack.pop();
            newnode->left=stack.pop();
            stack.push(newnode);  
        }
    }
    return stack.pop();
}