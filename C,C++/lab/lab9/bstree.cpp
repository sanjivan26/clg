//Program to inplement binary search tree data structure using linked list adt
#include<stdio.h>
#include<stdlib.h>

class Tree
{  
    private: 
        
        struct node
        {   
            int data;
            struct node *left;
            struct node *right;
        };

        struct node *root;

        int recins(struct node *temp,struct node *newnode,int data)
        {

            if(temp->data>data)
            {
                if(temp->left==NULL)
                {
                    temp->left=newnode;
                    return 1;
                }
                temp=temp->left;
            }
            else if(temp->data<data)
            {
                if(temp->right==NULL)
                {
                    temp->right=newnode;
                    return 1;
                }            
                temp=temp->right;
            }
            else if(temp->data==data)
            {
                free(newnode);
                return 0;
            }
            return recins(temp,newnode,data);
        }

        int recpre(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }
            printf("%d",temp->data);
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
            printf("%d",temp->data);      
            return 1;
        }

        int recin(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }

            recin(temp->left);
            printf("%d",temp->data);
            recin(temp->right);
            return 1;
        }       

        int recsearch(struct node *temp, int num)
        {
            if(temp==NULL)
            {
                return 0;
            }
            if(temp->data==num)
            {
                return 1;
            }
            if(num<temp->data)
            {
                return recsearch(temp->left,num);
            }          
            if(num>temp->data)
            {
                return recsearch(temp->right,num);
            }
            return 0;     
        }

        
        struct node *recdel(struct node *temp,int num)
        {
            if(temp==nullptr)
            {
                return temp;
            }
            else if(num<temp->data)
            {
                temp->left = recdel(temp->left,num);
            }          
            else if(num>temp->data)
            {
                temp->right = recdel(temp->right,num);
            }
            else
            {
                if (temp->left == nullptr) 
                {
                    struct node *temp2 = temp->right;
                    free(temp);
                    return temp2;
                } 
                else if (temp->right == nullptr) 
                {
                    struct node *temp2 = temp->left;
                    free(temp);
                    return temp2;
                }
                node *temp2 = temp->right;
                while (temp2->left != nullptr) 
                {
                    temp2 = temp2->left;
                }
                temp->data = temp2->data;
                temp->right = recdel(temp->right, temp2->data);
            }   
            return temp;
        }

    public:
        Tree()
        {
            root=NULL;
        }

        int insert(int);
        int inorder();
        int preorder();
        int postorder();
        int search(int);
        void deletion(int);
};

int main()
{   
    Tree t1;    
    int choice,num;
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n1.Insert \n2.Preorder \n3.Inorder \n4.Postorder \n5.Search \n6.Delete \n7.Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
                printf("\n Enter the number to insert:");
                scanf("%d",&num);
                t1.insert(num);
                break;
            case(2):
                t1.preorder();
                break;    
            case(3):
                t1.inorder();
                break; 
            case(4):
                t1.postorder();
                break; 
            case(5):
                printf("\n Enter the number to search:");
                scanf("%d",&num);
                if(t1.search(num))
                {
                    printf("The element is present in the tree");
                }
                else
                {
                    printf("The element is absent in the tree");
                }
                break;   
            case(6):
                printf("\n Enter the number to delete:");
                scanf("%d",&num);
                t1.deletion(num);
                printf("The element has been deleted");
                break;     
            case(7):
                exit(0);
                break;    
        }
    }
    return 1;
}


//Method to insert value
int Tree::insert(int num)
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

    return recins(root,newnode,num);
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
int Tree::search(int num)
{
    return recsearch(root,num);
}

//Method for deletion
void Tree::deletion(int num)
{
    recdel(root,num);
}