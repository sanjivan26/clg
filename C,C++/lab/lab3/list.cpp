//Array implementation of List ADT
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
//Defining Class List
class List
{
    int arr[SIZE];
    int cur;
    public:
        List()
        {
            cur = -1;
        }
        int insbeg(int);
        int delbeg();
        int insend(int);
        int inspos(int,int);
        void display();
        int delpos(int);
        int listpop();
        int listloc(int);
};

int main()
{
    List l1;
    int choice, num, val;
    while (1)
    {
        getchar();
        getchar();  // system('cls') for windows, system("clear") in linux
        printf("Enter \n1. Insert Begin\n2. Append\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Pop\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Exit");
        printf("\n Enter a choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            //Insert Begin
            printf("\n Enter the number to insert:");
            scanf("%d",&num);
            if(l1.insbeg(num))
            {
                printf("\n %d successfully inserted.",num);
            }
            else
            {
                printf("\n Failed to insert %d. The list is full.",num);
            }
            break;

        case 2:
            //Insert End
            printf("\n Enter the number to insert:");
            scanf("%d",&num);
            if(l1.insend(num))
            {
                printf("\n %d successfully inserted.",num);
            }
            else
            {
                printf("\n Failed to insert %d. The list is full.",num);
            }
            break;

        case 3:
            //Insert position
            int pos;
            printf("\n Enter the number to insert:");
            scanf("%d",&num);
            printf("\n Enter the position to insert:");
            scanf("%d",&pos);
            if(l1.inspos(num,pos))
            {
                printf("\n %d successfully inserted.",num);
            }
            else
            {
                printf("\n Failed to insert %d. The list is full or the index is invalid.",num);
            }
            break;
            
        case 4:        
            //Delete Begin
            if (l1.delbeg())
                printf("Deletion sucessful");
            else
                printf("The List is already empty");  
            break;      

        case 5:
            //pop
            if (l1.listpop())
                printf("Deletion sucessful");
            else
                printf("The List is already empty");
            break;    
        
        case 6:
            //Delete position
            printf("\n Enter the position to delete:");
            scanf("%d",&pos);
            if(l1.delpos(pos))
            {
                printf("\n %d successfully deleted.",num);
            }
            else
            {
                printf("\n Failed to delete %d. The list is empty.",num);
            }
            break;
            
        case 7:
            //Search
            printf("\n Enter the value to search:");
            scanf("%d",&val);
            if(l1.listloc(val)==(-1))
            {
                printf("\n %d The list does not have the given value.",num);
            }
            else if(l1.listloc(val)==-2)
            {
                printf("\n The list is empty.");
            }
            else if(l1.listloc(val)>=0)
            {
                printf("The value %d is present at location %d",val,l1.listloc(val));
            }
            break;

        case 8:
            //Displaying List
            l1.display();
            break;

        case 9:
            //Exiting List
            exit(0);
            break;

        default:
            printf("\n Enter a valid choice\n");
            break;
        }

    }
    return 0;
}

//Method to insert a number in begining of the list
int List::insbeg(int num)
{
    if(cur==SIZE-1)
    {
        return 0;
    }
    else if(cur==-1)
    {
        cur = 0;
        arr[0]=num;
        return 1;
    }
    else
    {
        for(int i=cur;i>=0;i--)
        {
            arr[i+1]=arr[i];
        }
        cur = cur + 1;
        arr[0]=num;
        return 1;

    }
}
//Method to display the contents of the list
void List::display()
{
    printf("\nThe contents of the list are:");
    for(int i=0;i<=cur;i++)
    {
        printf("%d ",arr[i]);
    }
}
//Method to insert a number in a specified position of the list
int List::inspos(int num,int pos)
{
    if(cur==SIZE-1)
    {
        return 0;
    }
    else if(pos>cur+1||pos>=SIZE)
    {
        return 0;
    }
    else if(cur==-1 && pos==0)
    {
        cur = 0;
        arr[0]=num;
        return 1;
    }
    else
    {
        for(int i=cur;i>=(pos);i--)
        {
            arr[i+1]=arr[i];
        }
        cur = cur + 1;
        arr[pos]=num;
        return 1;

    }
}

//Method to insert a number in the end of the list
int List::insend(int num)
{
    if(cur==SIZE-1)
    {
        return 0;
    }
    else if(cur==-1)
    {
        cur = 0;
        arr[0]=num;
        return 1;
    }
    else
    {        
        cur = cur + 1;
        arr[cur]=num;
        return 1;
    }
}

//Method to delete the first element
int List::delbeg()
{
    if(cur==-1)
    {   
        return 0;
    }
    else  
    {
        for(int i=1;i<=cur;i++)
        {
            arr[i-1]=arr[i];
        }
        cur-=1;
        return 1;
    }
}

//Method to delete the element in a specified position
int List::delpos(int pos)
{
    if(pos>cur||pos>=SIZE)
    {
        return 0;
    }
    else
    {   
        for(int i=pos;i<=cur;i++)
        {
            arr[i-1]=arr[i];
        }
        cur-=1;
        return 1;
    }    
}

//Method to delete the last element in a list
int List::listpop()
{
    if(cur==-1)
    {
        return 0;
    }
    else
    {
        cur-=1;
        return 1;
    }
}

//Method to search a value in a list
int List::listloc(int val)
{
    if(cur==-1)
        return -2;
    else
    {    
        for(int i=cur;i>=0;i--)
        {
            if(arr[i]==val)
                return (cur-1);
        }
        return -1;
    }    
}