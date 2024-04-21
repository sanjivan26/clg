//Implementing a graph with an adjacency matrix
#include <stdio.h>
#include <stdlib.h>
#define size 10

class amgraph
{
    private:
        int am[size][size];
        int vlist[size];
        int vertices;

    public:
        amgraph()
        {
            vertices=0;
        }
        int insertvertex(int);
        int deletevertex(int);
        int display();
        int search(int,int);

};


int main() 
{
    amgraph g;
    int choice;
    int num,num2;
    while(1) 
    {

        printf("\n1. Insert vertex \n2. Delete \n3. Search \n4. Display \n5.Exit");
        scanf("%d",&choice);

        switch(choice) 
        {
            case 1:
                printf("Enter the number ");
                scanf("%d",&num);
                if(g.insertvertex(num)) 
                {
                    printf("\n Inserted successfully.");
                }
                else 
                {
                    printf("\n Insertion unsuccessful.");
                }
                break;
            
            case 2:
                printf("Enter the number ");
                scanf("%d",&num);
                if(g.deletevertex(num)) 
                {
                    printf("\n Deleted successfully.");
                }
                else 
                {
                    printf("\n Deletion unsuccessful.");
                }
                break;

            case 3:
            {
                printf("Enter the first vertex ");
                scanf("%d",&num);
                printf("Enter the second vertex ");
                scanf("%d",&num2);
                int result = g.search(num,num2);
                if(result==-1) 
                {
                    printf("\n Edge not found");
                }
                else if(result == 0)
                {
                    printf("\n Edge dosent connect the given vertices");
                }   
                else
                {
                    printf("An edge connects given vertices");
                }         
                break;
            }

            case (4):
                g.display();
                break;
            
            case 5:
                exit(0);
                break;
        }
    }
}

//Method to insert a vertex
int amgraph::insertvertex(int num)
{
    for(int i=0;i<vertices;i++)
    {
        if(vlist[i]==num)
        {
            printf("Vertex already exists");
            return 0;
        }
    }
    if(vertices==size)
    {
        printf("Max size reached");
    }

    vlist[vertices]=num;
    int choice;
    for(int i=0;i<=vertices;i++)
    {
        printf("Is the vertex %d connected to %d ?",num,vlist[i]);
        scanf("%d",&choice);
        if(choice!=0 && choice!=1)
        {
            printf("Invalid input");
            return 0;
        }
        am[vertices][i]=choice;
        am[i][vertices]=choice;
    }
    vertices++;
    return 1;
}

//Method to delete a vertex
int amgraph::deletevertex(int num)
{
    int target = -1;
    for(int i=0;i<vertices;i++)
    {
        if(vlist[i]==num)
        {
            target = i;
            break;
        }
    }
    if(target==-1)
    {
        printf("Vertex not found");
        return 0;
    }
    for(int i=target;i<vertices-1;i++)
    {
        for(int j=0;j<vertices-1;j++)
        {
            if(i!=j)
            {
                am[i][j]=am[i+1][j];
                am[j][i]=am[j][i+1];
            }
            else
            {
                am[i][j]=am[i+1][j+1];
            }
        }
        vlist[i]=vlist[i+1];
    }
    vertices--;
    return 1;
}

//Method to display adjacency matrix
int amgraph::display()
{
    if(vertices==0)
    {
        printf("Graph is empty");
        return 0;
    }
    printf("  ");
    for(int i=0;i<vertices;i++)
    {
        printf("%d ",vlist[i]);
    }
    printf("\n");
    for(int i=0;i<vertices;i++)
    {
        printf("%d ",vlist[i]);
        for(int j=0;j<vertices;j++)
        {
            printf("%d ",am[i][j]);
        }
        printf("\n");
    }
    return 1;
}

//Method to search for an edge
int amgraph::search(int v1,int v2)
{
    int target1 = -1;
    int target2 = -1;
    for(int i=0;i<=vertices;i++)
    {
        if(vlist[i]==v1)
        {
            target1 = i;
        }
        if(vlist[i]==v2)
        {
            target2 = i;
        }        
    }
    if(target1==-1 || target2==-1)
    {
        return -1;
    }
    else
    {
        return(am[target1][target2]);
    }
}