//Program to implement doubly linked list using adt
#include<stdio.h>
#include<stdlib.h>

class doublink
{
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;

    public:
        doublink()
        {
            head=NULL;
            tail=NULL;
        }
        int insevenodd(int, int, int);
        void display();
        void insbeg(int);
        void insend(int);
        int inspos(int,int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        int searchpos(int);
};

int main()
{
    doublink l1;
    int num,choice,result,pos;
    while(1)
    {
    getchar();
    printf("Enter a choice \n 1. Insert Beginning \n 2. Insert End \n 3. Insert Position \n 4. Delete Beginning \n 5. Delete End \n 6. Delete Position \n"); 
    printf(" 7. Search \n 8. Display \n 9. Exit");
    scanf("%d",&choice);

    switch(choice)
    {
        case(1):
            printf("Enter the number");
            scanf("%d",&num);
            l1.insbeg(num);
            printf("Sucessfully inserted");
            break;

        case(2):
            printf("Enter the number");
            scanf("%d",&num);
            l1.insend(num);
            printf("Sucessfully inserted");
            break;

        case(3):
            printf("Enter the number");
            scanf("%d",&num);
            printf("Enter the position");
            scanf("%d",&pos);
            result=l1.inspos(num,pos);
            if(result==1)
            {
                printf("Sucessfully inserted");
            }
            else
            {
                printf("invalid index");
            }            
            break;

        case(4):
            result=l1.delbeg();
            if(result==1)
            {
                printf("Sucessfully deleted");
            }
            else
            {
                printf("Empty list");
            }
            break;

        case(5):
            result=l1.delend();
            if(result==1)
            {
                printf("Sucessfully deleted");
            }
            else
            {
                printf("Empty list");
            }
            break;

        case(6):
            printf("Enter the position");
            scanf("%d",&pos);
            result=l1.delpos(pos);
            if(result==1)
            {
                printf("Sucessfully deleted");
            }
            else
            {
                printf("invalid index");
            }            
            break;

        case(7):
            printf("\n Enter the number to search:");
            scanf("%d",&num);
            if (l1.search(num)!=0)  
            {   
                printf("Successfully deleted %d",l1.search(num));
            }    
            else 
                printf("Empty list");
            break;

        case(8):
            l1.display();   
            break;

        case(9):
            exit(0);
            break;    

        case(10):
            printf("\n Enter the index to search:");
            scanf("%d",&num);
            result=l1.searchpos(num);
            if (result!=0)  
            {   
                printf("data is %d",result);
            }    
            else 
                printf("Empty list");
            break;
    } 
    }  
}


/*Method to insert data at nth odd/even segment
int doublink::insevenodd(int odev,int n,int num)
{
    int pos=(2*n)-odev;

    
	if(head==NULL)
	    {
	    	insbeg(num);
            return 1;
		}

    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        struct node *add;
        add=head;
        int count;
        while(add->next!=NULL)
        {
            count+=1;
            add=add->next;
        }

        if(pos>count+1)
        {
            return 0;
        }

       
	    else
		{
		    struct node* temp;
	        temp = head;
	
	        for(int i=0;i<pos-2;i++)
	        {
		        temp = temp->next;
	        }
	        newnode->data = num;
	        newnode->next = temp->next;
	        temp->next = newnode;
            newnode->prev=temp;
            temp=temp->next;
            temp->prev=newnode;
            }
        return 1;
    }
}*/    

//Method to search for data given position of node
int doublink::searchpos(int cur)
{
    if(head==NULL)
    {
        return 0;
    }
    struct node *add;
    add=head;
    int count=1;
    while(add->next!=NULL)
    {
        add=add->next;
        count+=1;
    }
    if(cur>count+1||cur<1)
    {
        return 0;
    }

    struct node* temp;
    temp = head;
    
	for(int i=0;i<cur-1;i++)
    {
	    temp = temp->next;
    }
    return temp->data;
}

//Method to insert value at the beginning
void doublink::insbeg(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    if(head!=NULL)
    {
        head->prev=newnode;        
    }
    else
    {
        tail=newnode;
    }
    head=newnode;
}

//Method to insert value at the end
void doublink::insend(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=tail;
    if(tail!=NULL)
    {
        tail->next=newnode;
    }
    else
    {
        head=newnode;
    }
    tail=newnode;
}

//Method to insert a value
int doublink::inspos(int num,int pos)
{   
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        struct node *add;
        add=head;
        int count=1;
        while(add->next!=NULL)
        {
            add=add->next;
            count+=1;
        }

        if(pos>count+1||pos<1)
        {
            return 0;
        }
        else if(pos==1)
        {
            insbeg(num);
            return 1;
        }
        else if(pos==count+1)
        {
            insend(num);
            return 1;
        }
	    struct node* temp;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
	    temp = head;
	    for(int i=0;i<pos-2;i++)
	    {
	        temp = temp->next;
	    }
	    newnode->data = num;
	    newnode->next = temp->next;
	    temp->next = newnode;
        newnode->prev=temp;
        if(newnode->next !=NULL)
        {
            temp=newnode->next;
            temp->prev=newnode;
        }   
        return 1;
    }
}

//Method to delete value at the beginning
int doublink::delbeg()
{
    if(head==NULL)
    {
        return 0;        
    }  
    else if(head==tail)
    {
        free(head);
        head=NULL;
        tail=NULL;
        return 1;
    }
    else
    {
        struct node *target;
        target=head;
        head=head->next;
        head->prev=NULL;
        free(target);
        return 1;
    }
}

//Method to delete value at the end
int doublink::delend()
{
    if(head==NULL)
    {
        return 0;        
    }  
    else if(head==tail)
    {
        free(head);
        head=NULL;
        tail=NULL;
        return 1;
    }
    else
    {
        struct node *target;
        target=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(target);
        return 1;
    }
}

//Method to delete a value
int doublink::delpos(int pos)
{
    if(head==NULL)
	    {
	    	return 0;
		}
    else
    {
        struct node *add;
        add=head;
        int count=1;
        while(add->next!=NULL)
        {
            add=add->next;
            count+=1;
        }

        if(pos>count||pos<1)
        {
            return 0;
        }
        else if(pos==1)
        {
            delbeg();
            return 1;
        }
        else if(pos==count)
        {
            delend();
            return 1;
        }

       
	else
	{
	    struct node* temp;
        struct node *target;
	    temp = head;
	    for(int i=0;i<pos-2;i++)
	    {
	        temp = temp->next;
	    }
	    target=temp->next;
        temp->next=target->next;
        temp=target->next;
        temp->prev=target->prev;
        free(target);
        return 1;
    }
    return 1;
    }
}    

//Method to check if element exists in list
int doublink::search(int num)
{
    struct node *temp;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            return 1;
        }
        else
        {
            temp=temp->next;
        }
    }
    return 0;
}

//Method to display the List
void doublink::display()
{
    struct node *add;
    add=head;
    printf("Printing in forward \n [ %d",add->data);
    while(add!=tail)
    {
        add=add->next;
        printf(", %d",add->data);
    }
    printf(" ] \n ");
    add=tail;
    printf("\n Printing in reverse \n [ %d",add->data);
    
    while(add!=head)
    {
        add=add->prev;
        printf(", %d",add->data);
    }
    printf(" ]");
}