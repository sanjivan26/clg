//Program to inplement tree data structure using linked list adt
#include<stdio.h>
#include<stdlib.h>

int m=0;

class Tree
{  
    private: 
        
        struct node
        {   
            int data[10];
            struct node * add[11];
        };

        struct node *root;

        int recin(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }
            recin(temp->add[0]);
            for(int i=0;i<m;i++)
            {
                printf("%d",temp->data[i]);
                recin(temp->add[i+1]);                
            }
            return 1;
        }       


    public:
        Tree()
        {
            root=NULL;
        }

        int insert(int);
        int inorder();
};

int main()
{   
    Tree t1;    
    int choice,num;

    printf("\n Enter value for m:");
    scanf("%d",&m);
    m--;
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n1.Insert \n2.Inorder \n3.Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
                printf("\n Enter the number to insert:");
                scanf("%d",&num);
                t1.insert(num);
                break;    
            case(2):
                t1.inorder();
                break;      
            case(3):
                exit(0);
                break;    
        }
    }
    return 1;
}


//Method to insert value
int Tree::insert(int num)
{
    struct node* temp;
    temp=root;
    if(temp->data[0]==-1)
    {
        
    }
    if(num<temp->data[0])
    {
        if(temp->add[0]==NULL)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data[0]=num;
            return 1;
        }
        temp=temp->add[0];
    }
    if(num>temp->data[m])
    {
        if(temp->add[m+1]==NULL)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data[0]=num;
            return 1;
        }
        temp=temp->add[0];
    }    
}

//Method for inorder
int Tree::inorder()
{
    return recin(root);
}